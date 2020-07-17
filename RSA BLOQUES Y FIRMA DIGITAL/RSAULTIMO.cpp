#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <sstream>
#include <NTL/ZZ.h>
#include <vector>
using namespace NTL;



class rsa {

    private:
        ZZ p,q,d,e,n,phi,e_pub,n_pub;
        string alfabeto;
        string firma_digital;

    public:

        rsa(ZZ,ZZ,int);
        rsa(int);
        string cifrar(string);
        string descifrar(string);
        ZZ modulo(ZZ,ZZ);
        ZZ euclides(ZZ,ZZ);
        vector<ZZ>  euclides_extendido(ZZ,ZZ);
        ZZ inversa(ZZ ,ZZ);
        ZZ multiplicacion_modular(ZZ , ZZ ,ZZ );
        ZZ exponenciacion_modular(ZZ ,ZZ ,ZZ );
        ZZ phi_euler(ZZ p,ZZ q);
        string rellenado_0(int);
        string rellenado_aux(string,int);
        string rellenado_2(string,string);
        string rellenado_descifrado(string , int);
        string zz_To_String(ZZ);
        string int_to_string(int a);
        ZZ string_To_ZZ(string );
        int ZZ_to_int(ZZ );
        int string_to_int(string );
        ZZ generar_Aleatorio_bits(int );
        void generar_claves(int);
        ZZ quitar_0(string);
        ZZ resto_chino(ZZ val);
        bool test_primalidad_fermat(ZZ p);
        string cifrar_firma_digital(string);
};


rsa::rsa(int bits)
{
    generar_claves(bits);
    alfabeto= "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
}
rsa::rsa(ZZ ee,ZZ NN ,int bits)
{
    generar_claves(bits);
    e_pub=ee;
    n_pub=NN;
    alfabeto= "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
    cin>>firma_digital;
    //firma_digital="-AaronBlanco191-10-46317,Arequipa-Peru";

}



bool rsa::test_primalidad_fermat(ZZ p)
{
    for(int a=2;a<10;a++)
    {
        if(exponenciacion_modular(ZZ(a),p-1,p)!=1)
        {
            return false;
        }
    }
    return true;
}


void rsa::generar_claves(int bits)
{
    ZZ min;
    min = (2^bits)/2;
    p=generar_Aleatorio_bits(bits/2);
    while(test_primalidad_fermat(p)!=1){
        p=generar_Aleatorio_bits(bits/2);
    }
    cout<<"P:"<<p<<endl<<endl;
    q=generar_Aleatorio_bits(bits/2);
    while(test_primalidad_fermat(q)!=1){
        q=generar_Aleatorio_bits(bits/2);
    }
    //cout<<endl<<test_primalidad_fermat(q)<<endl;
    cout<<"Q:"<<q<<endl<<endl;
    n=p*q;
    cout<<"N: "<<n<<endl<<endl;
    phi=phi_euler(p,q);
    cout<<"PHI: "<<phi<<endl<<endl;
    e=generar_Aleatorio_bits(bits/2);
    while(test_primalidad_fermat(e)!=1){
        e=generar_Aleatorio_bits(bits/2);
    }
    cout <<"E:"<<e<<endl;
    d=inversa(e,phi);
    cout <<"D:"<<d<<endl;
}
ZZ rsa::modulo(ZZ a,ZZ b)
{
    ZZ q=a/b;
    ZZ r=a-q*b;
    if(r<0)
        r+=b;
    return r;
}
ZZ rsa::euclides(ZZ a, ZZ b)
{
    ZZ res=modulo(a,b);
    while(res!=0)
    {
        a=b;
        b=res;
        res=modulo(a,b);
    }
    return b;
}
vector<ZZ> rsa::euclides_extendido(ZZ a, ZZ b)
{
    vector<ZZ> result;
    ZZ r1 = a, r2 = b;
    ZZ x1 = to_ZZ(1), x2 = to_ZZ(0);
    ZZ y1 = to_ZZ(0), y2 = to_ZZ(1);
    ZZ q , r , x , y;
    while(r2>0){
        q = r1/r2;
        r = r1 - q*r2;
        r1 = r2;
        r2 = r;
        x = x1 - q*x2;
        x1 = x2;
        x2 = x;
    }
    result.push_back(x1);   //LA INVERSA DE A MOD B
    result.push_back(x2);   //MODULO
    result.push_back(euclides(a,b));//EL MCD
    return result;
}
ZZ rsa::inversa(ZZ a,ZZ b)
{
    vector<ZZ> temp;
    temp=euclides_extendido(a,b);
    if(temp[0]<0){
        return temp[0]+b;
    }
    else{
        return temp[0];
    }
}
ZZ rsa::multiplicacion_modular(ZZ a, ZZ b,ZZ mod)
{
    return modulo((modulo(a, mod) * modulo(b,mod)), mod);
}
ZZ rsa::exponenciacion_modular(ZZ a,ZZ b,ZZ mod)
{
    ZZ resultado = ZZ(1);
    while(b>0){
        if((b&1)==1){
            resultado = multiplicacion_modular(resultado,a,mod);
        }
        a=multiplicacion_modular(a,a,mod);
        b=b/2;
    }
    return resultado;
}
ZZ rsa::phi_euler(ZZ p,ZZ q)
{
    ZZ res;
    res = (p-ZZ(1))*(q-ZZ(1));
    return res;
}

string rsa::rellenado_0(int a)
{
    string llenar = int_to_string(a);
    string treat_fill = int_to_string(alfabeto.length());
    while(llenar.length()<treat_fill.length()){
        llenar = '0' + llenar;       ///llenado al principio
    }
    return llenar;
}

ZZ rsa::quitar_0(string w){
   ZZ piv;
   string aux1;
   int pos=w.find('0');
   while(pos!=-1){
        w.erase(pos,1);
   }
   piv=string_To_ZZ(w);
   return piv;
}
string rsa::rellenado_2(string piv,string w){
    while(piv.length()<w.length()){
        piv = '0' + piv;
    }
    return piv;
}
string  rsa::rellenado_aux(string a, int n_n)
{
    string var1="26";
    int i=0;
    char b;
    while(a.length()<n_n){

        i=i%2;
        b=var1[i];
        a=a+b;
        i++;
    }
    return a;
}
string  rsa::rellenado_descifrado(string a, int n_n)
{
    while(a.length()<n_n){
        a=  '0' + a;
    }
    return a;

}
string rsa::cifrar_firma_digital(string firma ){

    string cifrado;
    cifrado = cifrar(firma);
    cout<<endl<<"cifrado"<<endl;
    cout<<endl<<cifrado<<endl;
    return cifrado;


}
string rsa::cifrar(string mensaje)
{
	mensaje=mensaje+firma_digital;                  //AGREGANDO LA FIRMA DIGITAL
	string mensaje_cifrado;
	ZZ aux, p,pos_letra_cifrar;
	ZZ pos_letra_cifrada;
    string mensaje_rellenado_0,aux1,aux2,bloque;
    string aux3;
    int pos_letra,piv;
	for(int i=0;i<mensaje.length();i++){
        pos_letra=alfabeto.find(mensaje[i]);
        aux1=rellenado_0(pos_letra);
        mensaje_rellenado_0=mensaje_rellenado_0+aux1;
	}
    aux2=zz_To_String(n_pub);           //valor de n en string para poder hacer los bloques
    int cont=0;
    string bloque_vacio;
    for(int i=0;i<(mensaje_rellenado_0.length()/(aux2.length()-1)+1);i++){
        for(int j=1;j<aux2.length();j++){
            if(cont<mensaje_rellenado_0.length()){
                bloque=bloque+mensaje_rellenado_0[cont];
                cont++;
            }
        }
        if(bloque.length()!=(aux2.length()-1)){
            bloque=rellenado_aux(bloque,aux2.length()-1);
        }
        pos_letra_cifrar=string_To_ZZ(bloque);          //quitandole los 0 del bloque
        pos_letra_cifrada=exponenciacion_modular(pos_letra_cifrar,e_pub,n_pub); //CIFRANDO
        string p_string=zz_To_String(pos_letra_cifrada);
        aux3=rellenado_2(p_string,aux2);
        mensaje_cifrado=mensaje_cifrado+aux3;
        bloque=bloque_vacio;
    }
    return mensaje_cifrado;

}
ZZ rsa::resto_chino(ZZ val)
{
    ZZ q1, a1, q2, a2;
    q1 = inversa(modulo(q,p),p);
    a1 = exponenciacion_modular(modulo(val, p), modulo(d, p-1), p);
    q2 = inversa(modulo(p,q),q);
    a2 = exponenciacion_modular(modulo(val, q), modulo(d, q-1), q);
    return modulo(modulo(a1*q*q1,n)+modulo(a2*p*q2,n),n);
}
string rsa::descifrar(string w){
    string mensaje_descifrado_bloques,mensaje_descifrado;
    string aux2=zz_To_String(n);
    string bloque,bloque_vacio;
    string aux1;
    char letter;
    int pos,pos1;
    ZZ pos_letra_descifrar,pos_letra_descifrada,p_letra_des;
    int cont=0;
    for(int i=0;i<w.length()/(aux2.length());i++){      //SEPARANDO EN BLOQUES DE TAMAÑO N PARA
            for(int j=0;j<aux2.length();j++){
                if(cont<w.length()){
                    bloque=bloque+w[cont];
                    cont++;
                }
            }
            pos_letra_descifrar=string_To_ZZ(bloque);
            pos_letra_descifrada=resto_chino(pos_letra_descifrar); //USANDO RESTO CHINO
            string p_string;
            p_string=zz_To_String(pos_letra_descifrada);
            aux1=rellenado_descifrado(p_string,aux2.length()-1);
            mensaje_descifrado_bloques=mensaje_descifrado_bloques+aux1;
            bloque=bloque_vacio;
    }
    cont=0;
    for(int k=0;k<mensaje_descifrado_bloques.length()/2;k++){   //TRANSFORMANDO EL MENSAJE EN BLOQUES A BLOQUES DE 2
        for(int l=0;l<2;l++){                                   //CIFRAS PARA ACCEDER A LAS POCISIONES EN EL ALFABETO
            if(cont<w.length()){
                bloque=bloque+mensaje_descifrado_bloques[cont];
            }
            cont++;
        }
        p_letra_des=string_To_ZZ(bloque);       //CONVIRTIENDO LA POSICISON DE LA LETRA DE "ZZ" A
        pos=ZZ_to_int(p_letra_des);             //ENTERO PARA ACCEDER A SU POCISION EN EL ALFABETO
        mensaje_descifrado=mensaje_descifrado+alfabeto[pos];
        bloque=bloque_vacio;
    }
    return mensaje_descifrado;
}
string rsa::zz_To_String(ZZ z) {
    stringstream a;
    a << z;
    return a.str();
}
ZZ rsa::string_To_ZZ(string str){
    ZZ number(INIT_VAL, str.c_str());
    return number;
}
int rsa::ZZ_to_int(ZZ number)
{
    int n;
    conv(n,number);
    return n;
}
string rsa::int_to_string(int a)
{
    stringstream bleach;
    bleach << a;
    string aux=bleach.str();
    return aux;
}
int rsa::string_to_int(string a)
{
    stringstream bleach(a);
    int aux = 0;
    bleach >> aux;
    return aux;
}


ZZ rsa::generar_Aleatorio_bits(int bits)
{
    ZZ a;
    a = RandomBits_ZZ(bits);
    return a;
}
int main(){

    // PROBANDO EL RSA
    /*rsa emisor(128);
    mensaje_cifrado=emisor.cifrar("EL BOOM BOOM BOOM TAM TAM TAM TAM TAM");
    cout<<endl;
    cout<<"MENSAJE CIFRADO: "<<endl<<mensaje_cifrado<<endl;
    mensaje_descifrado=emisor.descifrar(mensaje_cifrado);
    cout<<endl<<"MENSAJE DESCIFRADO"<<endl<<mensaje_descifrado;*/


    //PARA PODER DESCIFRAR A ALGUIEN
    /*rsa receptor(128);
    string mensaje_cifrado_emisor,mensaje_descifrado;
    cin>>mensaje_cifrado_emisor;
    mensaje_descifrado=receptor.descifrar(mensaje_cifrado_emisor);
    cout<<endl<<mensaje_descifrado<<endl;*/

    //CIFRAR PARA ALGUIEN
    ZZ E,N;
    string mensaje_cifrado_mandar,mensaje_descifrado;
    cin>>E;
    cin>>N;
    rsa emisor(E,N,256);

    mensaje_cifrado_mandar=emisor.cifrar("ALGEBRA-ABSTRACTA");
    cout<<endl<<"MENSAJE CIFRADO: ";
    cout<<endl<<mensaje_cifrado_mandar;



    return 0;
}
