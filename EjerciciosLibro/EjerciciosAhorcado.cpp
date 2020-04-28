#include <fstream>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
 using std::string;
#include <sstream>
using std::istringstream;
using namespace std;

class ahorcado{
    private:
        string letra,texto,copia,comp;
        bool b{false};
        int n_errores=0,pocision=-1;
        ifstream archivo;
    public:
        ahorcado();
        string cifrar_palabra();
        void escoger_palabra();
        void dibujar();
        void jugar();
        void actualizar_score();
        void ganar();
};

ahorcado::ahorcado(){

}
void ahorcado::escoger_palabra(){
   archivo.open("palabras.txt",ios::in);//Abre el texto para lectura

   if(archivo.fail()){

     cout<<"\nNO SE PUEDO ABRIR EL ARCHIVO";
     exit(1);
   }
   getline(archivo,texto);


   archivo.close();


}
string ahorcado::cifrar_palabra(){

   string a(texto.length(),'x');
   return a;

}
void ahorcado::actualizar_score(){

    if(comp==copia){
        n_errores++;
        dibujar();
    }
    else{
        comp=copia;
    }
}
void ahorcado::ganar(){
    if(copia==texto){
                cout<<"\n\n  FELICIDADES ADIVINASTE LA PALABRA!!!!  ";
                b=true;
         }

}
void ahorcado::jugar(){
    escoger_palabra();
    copia=cifrar_palabra();
    comp=copia;
    cout<<" COMENZEMOS!! \n";
    while(b!= true){
        cout<<"\nINGRESE UNA LETRA: \n";
        cin>>letra;

        do{
            pocision=texto.find(letra,pocision+1);
            if(pocision!=-1){
                copia.replace(pocision,1,letra);

            }




        }while(pocision!=-1);

         system("cls");//REFRESCA LA PANTALLA
         cout<<"\n"<<copia<<"\n";

         actualizar_score();//VE SI LOS ERRORES AUMENTAN
         ganar();//VE SI LA PALABRA SE ADIVINO

         cout<<" errores totales: "<<n_errores;


    }



}
void ahorcado::dibujar(){


    if(n_errores==1){

        cout<<"     !     \n";
        cout<<"     !     \n";
        cout<<"     !     \n";
    }

    else if (n_errores==2){
        cout<<"     !     \n";
        cout<<"     !     \n";
        cout<<"    _!_    \n";
        cout<<"   (   )   \n";
        cout<<"   (___)   \n";
        cout<<"           \n";
    }
    else if (n_errores==3){
        cout<<"     !     \n";
        cout<<"     !     \n";
        cout<<"    _!_    \n";
        cout<<"   (   )   \n";
        cout<<"   (___)   \n";
        cout<<"     !     \n";
        cout<<"     !     \n";
    }
    else if (n_errores==4){
        cout<<"     !     \n";
        cout<<"     !     \n";
        cout<<"    _!_    \n";
        cout<<"   (   )   \n";
        cout<<"   (___)   \n";
        cout<<"     !____ \n";
        cout<<"     !     \n";
    }
    else if (n_errores==5){
        cout<<"     !     \n";
        cout<<"     !     \n";
        cout<<"    _!_    \n";
        cout<<"   (   )   \n";
        cout<<"   (___)   \n";
        cout<<" ____!____ \n";
        cout<<"     !     \n";
    }
    else if (n_errores==6){
        cout<<"     !     \n";
        cout<<"     !     \n";
        cout<<"    _!_    \n";
        cout<<"   (   )   \n";
        cout<<"   (___)   \n";
        cout<<" ____!____ \n";
        cout<<"     !     \n";
        cout<<"    /      \n";
        cout<<"   /       \n";
    }
    else if (n_errores==7){
        cout<<"     !     \n";
        cout<<"     !     \n";
        cout<<"    _!_    \n";
        cout<<"   (   )   \n";
        cout<<"   (___)   \n";
        cout<<" ____!____ \n";
        cout<<"     !     \n";
        cout<<"    / \\    \n";
        cout<<"   /   \\   \n";
        cout<<"\n";
        cout<<"OHH!! PERDISTE.........";
    }

}


int main(){

ahorcado palabra;
palabra.jugar();

return 0;


}
