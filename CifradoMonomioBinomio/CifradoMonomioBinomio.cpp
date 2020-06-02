 #include <iostream>
#include <string>

using namespace std;

class monomio_binomio
{
  public:
  string alfabeto;
  monomio_binomio();
  string cifrar(string);
  string descifrar(string);
};
monomio_binomio::monomio_binomio()
{
  alfabeto="D-ENAR-IOSBCFGHJKLMÑPQTUVWXYZ.";
}
string monomio_binomio::cifrar(string mensaje)
{
  string mensaje_cifrado;
  int aux;
  for(int i=0;i<mensaje.length();i++)
  {

    aux=alfabeto.find(mensaje[i]);
    cout<<"\n"<<mensaje[i]<<" "<<aux<<"\n";
    if(aux>19){
      mensaje_cifrado+="7";

    }
    if(aux>9 && aux<20){
      mensaje_cifrado+="2";

    }

    mensaje_cifrado+=to_string(aux%10);
  }
  return mensaje_cifrado;
}
string monomio_binomio::descifrar(string mensaje_cifrado)
{
  string msj_descifrado;
  string aux;
  int aux2;
  int tam=alfabeto.length();
  for(int i=0;i<mensaje_cifrado.length();i++)
  {
    if(mensaje_cifrado[i]=='7')
    {
      aux=mensaje_cifrado[i+1];
      aux2=stoi(aux);
      msj_descifrado+=alfabeto[((aux2+20)%tam)];
      i++;
    }
    else if(mensaje_cifrado[i]=='2')
    {
      aux=mensaje_cifrado[i+1];
      aux2=stoi(aux);
      msj_descifrado+=alfabeto[(aux2+10%tam)];
      i++;
    }
    else
    {
      aux=mensaje_cifrado[i];
      aux2=stoi(aux);
      msj_descifrado+=alfabeto[(aux2%tam)];
    }
  }
  return msj_descifrado;
}

int main()
{
  monomio_binomio emisor;
  string mensaje,mensajecifrado,mensajedescifrado;
  cout<<"ingrese una palabra para cifrar\n";
  getline(cin,mensaje);
  for(int i=0;i<mensaje.length();i++){
    mensaje[i]=toupper(mensaje[i]);
  }
  mensajecifrado=emisor.cifrar(mensaje);
  mensajedescifrado=emisor.descifrar(mensajecifrado);
  cout<<mensajecifrado<<"\n";
  cout<<mensajedescifrado;
}
