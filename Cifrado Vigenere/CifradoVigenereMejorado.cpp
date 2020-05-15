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
    string cifrando(string);
    string alfabeto;
    string descifrar(string);
    string cifrar_ascii(string);
    string descifrar_ascii(string);
    string cifrado_concatenando(string);
    void inicializar();


};
vigenere::vigenere()
{
    //alfabeto2 = "abcdefghijklmnopqrstuvwxyz -ABCDEFGHIJKLMNOPQRSTUVWXYZ,.0123456789";
    alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
    clave = "sapo";

}

string vigenere::cifrando(string msj){    //EJERCICIO 3-C Y 3-R
    string MensajeCifrado;
    int tam = alfabeto.length();
    int pocision,pocision1,pocision_cifrado;
    int cont=0;
    for (int i=0;i<msj.length();i++)
    {
        pocision1=alfabeto.find(msj[i]);
        pocision=alfabeto.find(clave[cont]);
        pocision_cifrado=(pocision1+pocision)%tam;
        if (cont==clave.length()-1){
            cont=0;
        }
        else{
            cont++;
        }
        MensajeCifrado=MensajeCifrado+alfabeto[pocision_cifrado];
    }
    return MensajeCifrado;
}

string vigenere::descifrar(string mensajeencriptado){ //EJERCICIO 3-B
    string mensajedescifrado;
    int tam = alfabeto.length();
    int pocision,pocision1,pocision_descifrado,value;
    int cont=0;
    for (int i=0;i<mensajeencriptado.length();i++)
    {
        pocision1=alfabeto.find(mensajeencriptado[i]);
        pocision=alfabeto.find(clave[cont]);

        if(pocision1<pocision){

            pocision_descifrado=(pocision1-pocision)+tam;
        }
        else{
                pocision_descifrado=(pocision1-pocision)%tam;

        }
        if (cont==clave.length()-1){
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
        a=cifrando(palabra);
        cout<<"\nPalabra Cifrada: \n"<<a<<"\n";

    }
    else if(op==2){
        b=descifrar(palabra);
        cout<<"\nPalabra Descifrada: \n"<<b<<"\n";

    }
    else if(op==3){
        c=cifrar_ascii(palabra);
        cout<<"\nPalabra Cifrada en ASCII: \n"<<c<<"\n";

    }
    else if(op==4){
        d=descifrar_ascii(palabra);
        cout<<"\nPalabra descifrada en ASCII: \n"<<d<<"\n";


    }
    else if(op==5){
        e=cifrado_concatenando(palabra);
        cout<<"\nPalabra cifrada concatenando: \n"<<e<<"\n";

    }
    else{
        cout<<"ESTA OPCION NO EXISTE INGRESE OTRA \n";

    }
}

string vigenere::cifrar_ascii(string msj){   //EJERCICIO 3-B
  int pos1,pos2,pos3;

  for(int i=0;i<msj.length();i++){
    pos1=int(msj[i])-65;
    pos2=int(clave[i%clave.length()])-65;
    //cout<<pos1<<"  "<<pos2<<"\n";
    msj[i]=(pos2+pos1)%57 ;    // cambia la letra del mensaje a una nueva letra de mensaje sumando la pos1 mas la 2 modulo 57
    pos3=int(msj[i]);
    //cout<<pos3<<"\n";
    if(pos3<65){
        msj[i]=65+pos3;
    }
  }
  return msj;
}
string vigenere::descifrar_ascii(string msj){  //EJERCICIO 3-B
 int pos1,pos2,pos3;
 for(int i=0;i<msj.length();i++){
    pos1=int(msj[i])-65;
    pos2=int(clave[i%clave.length()])-65;
    //cout<<pos1<<"  "<<pos2<<"\n";

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

string vigenere::cifrado_concatenando(string msj){  //EJERCICIO 3-E

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
        pocision=alfabeto.find(clave[i%clave.length()]);
        pocision_cifrado=(pocision1+pocision)%tam;

        MensajeCifrado=MensajeCifrado+alfabeto[pocision_cifrado];
    }
    return MensajeCifrado;
}


int main(){

  vigenere a;
  string em,re;
  cout<<"INGRESE MENSAJE A CIFRAR: \n";
  getline(cin,em);
  em=a.cifrando(em);
  cout<<"MENSAJE CIFRADO: \n";
  cout<<em<<"\n";
  cout<<"MENSAJE DESCIFRADO: \n";
  re=a.descifrar(em);
  cout<<re<<"\n\n";


  //a.inicializar();    //FUNCION QUE ABRE EL MENU PARA PODER REALIZAR LA FUNCION QUE EL USUARIO DESEE CIFRAR , DESCIFRAR ,
                      //CIFRAR EN ASCII Y DESCIFRAR EN ASCII

  system("pause");


}
