#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;


class cesar{
    private:
        int clave;
        string mensaje;



    public:
        cesar();
        string cifrar(string);
        string descifrar(string);
        string datos;
};

cesar::cesar(){

    clave=3;
    datos="abcdefghijklmnopqrstuvwxyz ";

}

string cesar::cifrar(string msj){
    int tam = datos.length();
    int pos;
    for(int i=0;i<msj.length();i++){


                pos=((datos.find(msj[i]))+clave)%tam;
                msj[i]=datos.at(pos);


    }
    //mensaje_cifrado=msj;
    return msj;
}

string cesar::descifrar(string msjc){
   int pos;
   int tam=datos.length();
   for(int i=0;i<msjc.length();i++){

                pos=datos.find(msjc[i]);

                if(pos<3){
                    pos=datos.find(msjc[i])-clave+tam;
                    msjc[i]=datos.at(pos);
                }
                else{
                        pos=(datos.find(msjc[i])-clave)%tam;
                        msjc[i]=datos.at(pos);
                }


    }
    return msjc;
}


int main()
{


    cesar palabra;
    string mensaje;
    string mensaje_cifrado, mensaje_descifrado;
    cout<<"escriba una palabra: ";
    getline(cin,mensaje);
    mensaje_cifrado=palabra.cifrar(mensaje);
    cout<<"\nmensaje cifrado: "<<mensaje_cifrado<<"\n";
    mensaje_descifrado=palabra.descifrar(mensaje_cifrado);
    cout<<"\nmensaje descifrado: "<<mensaje_descifrado;

    return 0;
}

