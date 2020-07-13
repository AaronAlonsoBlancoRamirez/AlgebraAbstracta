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

    ZZ p,q,d,e_pub,n_pub;
    ZZ e,n,phi,tam;

    public:
        rsa(int ,ZZ ,ZZ );
        rsa(int);
        rsa(ZZ,ZZ,ZZ,ZZ,ZZ,ZZ);
        //string alfabeto= "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
        string alfabeto= "abcdefghijklmnopqrstuvwxyz";
        string cifrar(string);
        string descifrar();

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
        string zz_To_String(ZZ);
        string int_to_string(int a);
        ZZ string_To_ZZ(string );
        int ZZ_to_int(ZZ );
        int string_to_int(string );
        ZZ generar_Aleatorio(int );
        ZZ generar_Aleatorio_Prime(int );
        ZZ generar_Aleatorio_Max(ZZ );
        ZZ generar_Aleatorio_bits(int );
        void generar_claves(int);
        ZZ quitar_0(string);
};


rsa::rsa(ZZ p_1,ZZ q_1,ZZ e_1,ZZ d_1,ZZ e_2,ZZ n_2)
{
    p = p_1;
    q = q_1;
    e = e_1;
    d = d_1;
    n = p_1 * q_1;
    phi = (p-ZZ(1))*(q-ZZ(1));
    ///cout<<"PHI_: "<<phi<<endl;
    e_pub = e_2;
    n_pub = n_2;
    cout<<"P:"<<p<<endl;
    cout<<"Q:"<<q<<endl;
    cout<<"N: "<<n<<endl;
    cout<<"PHI: "<<phi<<endl;
    cout <<"E:"<<e<<endl;
    cout <<"D:"<<d<<endl;
    cout<<"E_DEL_MEN: "<<e_pub<<endl;
    cout<<"N_DEL_MEN: "<<n_pub<<endl;
}

rsa::rsa(int bits)
{
    generar_claves(bits);
    e_pub=e;
    n_pub=n;
    cout<<"E_DEL_MEN: "<<e_pub<<endl;
    cout<<"N_DEL_MEN: "<<n_pub<<endl;
}
rsa::rsa(int bits, ZZ e2, ZZ n2)
{
    generar_claves(bits);
    e_pub=e2;
    n_pub=n2;
}



void rsa::generar_claves(int bits)
{
    ZZ min;
    min = (2^bits)/2;
    p=to_ZZ(17);
    p=generar_Aleatorio_Prime(bits);

    cout<<"P:"<<p<<endl;
    //q=to_ZZ(59);
    q=generar_Aleatorio_Prime(bits);

    cout<<"Q:"<<q<<endl;
    n=p*q;
    cout<<"N: "<<n<<endl;
    phi=phi_euler(p,q);
    cout<<"PHI: "<<phi<<endl;

    //e=to_ZZ(3);
    e=generar_Aleatorio_Max(phi);

    cout <<"E:"<<e<<endl;
    tam=alfabeto.length();
    ///cout<<"TAM: "<<tam<<endl;
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
        ///cout<< a << "=" << a/b << "(" << b << ")" << "+" << res << endl;
        a=b;
        b=res;
        res=modulo(a,b);
    }
    ///cout<< a << "=" << a/b << "(" << b << ")" << "+" << res << endl;
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
    result.push_back(x1);
    result.push_back(x2);
    result.push_back(euclides(a,b));
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
        if((b&1)==1){ //VERIFICA SI "B" ES IMPAR O NO
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
string rsa::cifrar(string mensaje)
{
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
	//cout<<"Mensaje rellenado\n";
	//cout<<mensaje_rellenado_0;

    aux2=zz_To_String(n);           //valor de n en string para poder hacer los bloques
    //cout<<endl<<"valor de n en string\n";
    //cout<<endl<<aux2;

    int cont=0;
    string bloque_vacio;
    for(int i=0;i<(mensaje_rellenado_0.length()/(aux2.length()-1)+1);i++){
        for(int j=1;j<aux2.length();j++){
            if(cont<mensaje_rellenado_0.length()){
                bloque=bloque+mensaje_rellenado_0[cont];
                //cout<<endl<<bloque<<" "<<endl;
                cont++;
            }
        }
        if(bloque.length()!=(aux2.length()-1)){
            bloque=rellenado_aux(bloque,aux2.length()-1);
            cout<<endl<<bloque;
        }
        pos_letra_cifrar=string_to_int(bloque);     //quitandole los 0 del bloque
        pos_letra_cifrada=exponenciacion_modular(pos_letra_cifrar,e,n); //CIFRANDO

        string p_string=zz_To_String(pos_letra_cifrada);
        aux3=rellenado_2(p_string,aux2);


        mensaje_cifrado=mensaje_cifrado+aux3;

        //cout<<endl<<aux3<<endl;

        bloque=bloque_vacio;
    }
    return mensaje_cifrado;

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
ZZ rsa::generar_Aleatorio(int bits)
{
     ZZ a;
     a=RandomLen_ZZ(bits);
     return a;
}
ZZ rsa::generar_Aleatorio_Prime(int bits)
{
     ZZ a;
     GenPrime(a,bits);
     return a;
}
ZZ rsa::generar_Aleatorio_Max(ZZ max)
{
    ZZ a;
    a=RandomBnd(max); ///default 512?
    return a;
}
ZZ rsa::generar_Aleatorio_bits(int bits)
{
    ZZ a;
    a = RandomBits_ZZ(bits);
    return a;
}


int main(){

    rsa emisor(8);
    ZZ N=to_ZZ(1),e,pos;
    string word;

    word=emisor.cifrar("comehere");
    cout<<"MENSAJE CIFRADO: "<<endl<<word;
    return 0;


}
