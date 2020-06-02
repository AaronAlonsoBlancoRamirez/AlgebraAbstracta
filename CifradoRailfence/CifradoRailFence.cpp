#include <iostream>
using namespace std;
#include <string>
#include <stdio.h>
#include <string.h>

class railfence{

private:
    int clave;

public:
    string alfabeto;
    railfence();
    string cifrar(string);
    string descifrar(string);


};
railfence::railfence(){
    clave=4;
    alfabeto = "abcdefghijklmnopqrstuvwxyz";

}

int main(){
    railfence emisor;
    string texto;
    getline(cin,texto);
    emisor.cifrar(texto);
}

string railfence::cifrar(string texto){
    int tam=texto.length();
    string textocifrado;
    int elementos_ola=(clave*2)-2;
    float olas=(tam-1)/elementos_ola;
    if((tam-1)%elementos_ola!=0){
        cout<<"entro aqi\n";
        olas=olas+1;
    }
    cout<<olas;
    int piv;
    int piv2=0;
    int piv3=elementos_ola;
    int piv4=elementos_ola;
    int piv5=1;
    for(int i=0;i<clave;i++){
        piv=i;
        //piv3=elementos_ola;
        for(int j=0;j<olas;j++){
            if(i==0 || i==clave-1){
                textocifrado=textocifrado+texto.at(piv);
                piv=piv+elementos_ola;

            }
            if(i!=0 && i!=clave-1){
                  //piv2
                  textocifrado==textocifrado+texto.at(piv);


            }


        }
        //piv3--;
        //piv4++;
    }
    cout<<"\ntexto cifrado: "<<textocifrado;





}

/*int i,tam,j=0,k=0;
    char texto[15],cif[15],str1[10],str2[10];
    cout<<"Enter texto Text:";
    cin>>texto;
    tam=strlen(texto);
    for(i=0;i<tam;i++)
    {
        if(i%2==0)
        {
            str1[j]=texto[i];
            j++;
        }
        else
            {
                str2[k]=texto[i];
                k++;
            }
        }
    j=0;

    cout<<"Str1:"<<str1<<endl<<"Str2:"<<str2;
*/
