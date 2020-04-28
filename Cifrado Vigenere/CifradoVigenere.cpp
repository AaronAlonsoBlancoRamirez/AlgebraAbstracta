#include <iostream>
#include <fstream>
#include <iostream>
#include<string>
#include<locale.h>
using namespace std;

class vigenere
{
private:
    string clave;
public:
    vigenere();
    string cifrando(string ,string);
    string alfabeto;
    string descifrar(string,string);
    string cifrar_ascii(string,string);
    string descifrar_ascii(string,string);
    string cifrado_concatenando(string ,string );
    string cifrado_modificado(string ,string );
    void inicializar();


};
vigenere::vigenere()
{
    alfabeto = "abcdefghijklmnopqrstuvwxyz -ABCDEFGHIJKLMNOPQRSTUVWXYZ,.0123456789";

}

string vigenere::cifrando(string msj,string c){    //EJERCICIO 3-C Y 3-R
    string MensajeCifrado;
    int tam = alfabeto.length();
    int pocision,pocision1,pocision_cifrado;
    int cont=0;
    for (int i=0;i<msj.length();i++)
    {
        pocision1=alfabeto.find(msj[i]);
        pocision=alfabeto.find(c[cont]);
        pocision_cifrado=(pocision1+pocision)%tam;
        if (cont==c.length()-1){
            cont=0;
        }
        else{
            cont++;
        }
        MensajeCifrado=MensajeCifrado+alfabeto[pocision_cifrado];
    }
    return MensajeCifrado;
}

string vigenere::descifrar(string mensajeencriptado,string c){ //EJERCICIO 3-B
    string mensajedescifrado;
    int tam = alfabeto.length();
    int pocision,pocision1,pocision_descifrado,value;
    int cont=0;
    for (int i=0;i<mensajeencriptado.length();i++)
    {
        pocision1=alfabeto.find(mensajeencriptado[i]);
        pocision=alfabeto.find(c[cont]);

        if(pocision1<pocision){

            pocision_descifrado=(pocision1-pocision)+tam;
        }
        else{
                pocision_descifrado=(pocision1-pocision)%tam;

        }
        if (cont==c.length()-1){
            cont=0;
        }
        else{
        cont++;
        }
        mensajedescifrado=mensajedescifrado+alfabeto[pocision_descifrado];
    }
    return mensajedescifrado;
}

void vigenere::inicializar(){
    string a,b,c,d,e;
    int op;
    string palabra,clav;
    cout<<"---CODIGO VIGENERE---\n";
    cout<<"escriba la palabra: ";
    getline(cin,palabra);
    cout<<"escriba la clave: ";
    getline(cin,clav);
    cout<<"ESCOGA LA OPCION QUE DESEA USAR \n";
    cout<<" 1--CIFRAR \n";
    cout<<" 2--DESCIFRAR \n";
    cout<<" 3--CIFRAR(ASCII) \n";
    cout<<" 4--DESCIFRAR(ASCII) \n";
    cout<<" 5--CIFRAR CONCATENANDO \n";
    cin>>op;
    if(op==1){
        a=cifrando(palabra,clav);
        cout<<"\nPalabra Cifrada: "<<a;
    }
    else if(op==2){
        b=descifrar(palabra,clav);
        cout<<"\nPalabra Descifrada: "<<b;
    }
    else if(op==3){
        c=cifrar_ascii(palabra,clav);
        cout<<"\nPalabra Cifrada en ASCII: "<<c;
    }
    else if(op==4){
        d=descifrar_ascii(palabra,clav);
        cout<<"\nPalabra descifrada en ASCII: "<<d;

    }
    else if(op==5){
        e=cifrado_concatenando(palabra,clav);
        cout<<"\nPalabra cifrada concatenando: "<<e;
    }
    else{
        cout<<"ESTA OPCION NO EXISTE INGRESE OTRA";
        inicializar();
    }
}

string vigenere::cifrar_ascii(string msj, string c){   //EJERCICIO 3-B
  int pos1,pos2,pos3;

  for(int i=0;i<msj.length();i++){
    pos1=int(msj[i])-65;
    pos2=int(c[i%c.length()])-65;
    cout<<pos1<<"  "<<pos2<<"\n";
    msj[i]=(pos2+pos1)%57 ;
    pos3=int(msj[i]);
    cout<<pos3<<"\n";
    if(pos3<65){
        msj[i]=65+pos3;
    }
  }
  return msj;
}
string vigenere::descifrar_ascii(string msj,string c){  //EJERCICIO 3-B
 int pos1,pos2,pos3;
 for(int i=0;i<msj.length();i++){
    pos1=int(msj[i])-65;
    pos2=int(c[i%c.length()])-65;
    cout<<pos1<<"  "<<pos2<<"\n";

    if(pos1<pos2){
        msj[i]=pos1-pos2+57;
        pos3=int(msj[i]);
        if(pos3<65){
            msj[i]=65+pos3;
        }
    }
    else{
        msj[i]=pos1-pos2%57;
        pos3=int(msj[i]);
        if(pos3<65){
            msj[i]=65+pos3;
        }
    }


 }
 return msj;

}

string vigenere::cifrado_concatenando(string msj,string c){  //EJERCICIO 3-E

    string a="AQUI",MensajeCifrado;
    int pocision1,pocision,tam=alfabeto.length(),res,d,p,pocision_cifrado;
    d=msj.length()/10;
    p=10;
    for(int i=0;i<d;i++){
        msj.insert(p,a);
        p=p+10;
    }
    if(msj.length()%4!=0){
        res=4-msj.length()%4;
        string a(res,'W');
        msj=msj+a;
    }
    for (int i=0;i<msj.length();i++)
    {
        pocision1=alfabeto.find(msj[i]);
        pocision=alfabeto.find(c[i%c.length()]);
        pocision_cifrado=(pocision1+pocision)%tam;

        MensajeCifrado=MensajeCifrado+alfabeto[pocision_cifrado];
    }
    return MensajeCifrado;
}

string vigenere::cifrado_modificado(string msj,string c){ //EJERCICIO 3-F -
    int pocision1,pocision,tam=alfabeto.length(),pocision_cifrado;
    string MensajeCifrado;
    for (int i=0;i<msj.length();i++)
    {
        pocision1=alfabeto.find(msj[i]);
        pocision=alfabeto.find(c[i]);
        pocision_cifrado=(pocision1+pocision)%tam;
        if (i>=c.length()-1){
            pocision1=alfabeto.find(msj[i]);
            pocision=alfabeto.find(msj[i-c.length()-1]);
            pocision_cifrado=(pocision1+pocision)%tam;
        }
        else{
            pocision1=alfabeto.find(msj[i]);
            pocision=alfabeto.find(c[i]);
            pocision_cifrado=(pocision1+pocision)%tam;
        }
        MensajeCifrado=MensajeCifrado+alfabeto[pocision_cifrado];
    }
    return MensajeCifrado;




}
int main(){

  vigenere a;
  //string poema="Puedo escribir los versos mas tristes esta noche.Escribir, por ejemplo La noche esta estrellada, y tiritan, azules, los astros, a lo lejos.El viento de la noche gira en el cielo y canta. Puedo escribir los versos mas tristes esta noche. Yo la quise,y a veces ella tambien me quiso.";
  string em,re;
  string palabra="-s-iDMmsEGGuzyQKvCdpOMTsuz M6ziD1iNhdi7vcmuhQtv vLTyxuuKwTT AGRuthmorv5Zi4Bim858gizeQDwvrKEFzKQt-BdmLS7sAjlG3jjZf5ZY3vlnWvt sJGtuCYSoFLxERXgzRVrAzoA99cZi4K4odfi8ljpIRqnL ,n7nREABT KC8IqykY4h1Fi0L";
  string clave="Sebastian Augusto Paz Rocha 191-10-45515";
  //em=a.cifrando(palabra,clave);
  //cout<<em;
  //cout<<"\n\n";
  cout<<"MENSAJE A CIFRAR: \n";
  cout<<palabra<<"\n\n";
  cout<<"MENSAJE DESCIFRADO: \n";
  re=a.descifrar(palabra,clave);
  cout<<re<<"\n\n";
  //a.inicializar();



}


