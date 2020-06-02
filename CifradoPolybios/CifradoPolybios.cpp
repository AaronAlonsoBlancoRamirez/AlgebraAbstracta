#include <iostream>
#include <string>
using namespace std;

class polybios
{
  public:
  string alfabeto;
  string tabla;
  int tam;
  polybios();
  string cifrado(string);
  string decifrado(string);
};
polybios::polybios()
{
  alfabeto="abcdefghijklmnopqrstuvwxyz ";
  tabla="abcde";
  tam=tabla.length();
}
string polybios::cifrado(string mensaje)
{
  int aux,aux2,aux3;
  string msj_cifrado;
  for(int i=0;i<mensaje.length();i++)
  {
    aux=alfabeto.find(mensaje[i]);
    aux2=aux%tam;
    aux3=aux/tam;
    msj_cifrado+=tabla[aux3];
    msj_cifrado+=tabla[aux2];
  }
  return msj_cifrado;
}
string polybios::decifrado(string mensajecifrado)
{
  int pos_f,pos_c;
  string msj_descifrado;
  for(int i=0;i<mensajecifrado.length();i=i+2)
  {
    pos_f=tabla.find(mensajecifrado[i]);
    pos_c=tabla.find(mensajecifrado[i+1]);
    msj_descifrado+=alfabeto[pos_f*tam+pos_c];
  }
  return msj_descifrado;
}

int main()
{
  polybios emisor;
  string mensaje,mensaje_cifrado,mensaje_descifrado;
  //msj1=polybios.cifrado("ABSTRACTA");
  getline(cin,mensaje);
  mensaje_cifrado=emisor.cifrado(mensaje);
  mensaje_descifrado=emisor.decifrado(mensaje_cifrado);
  cout<<mensaje_cifrado<<"\n";
  cout<<mensaje_descifrado<<"\n";
}
