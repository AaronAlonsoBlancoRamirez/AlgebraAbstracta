#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
using std::cin;
#include <string>
 using std::string;
#include <sstream>
using std::istringstream;
using namespace std;

void ejercicio18_7();
void ejercicio18_11();
void ejercicio18_19();
void ejercicio18_21();
void ejercicio18_22();
void ejercicio18_27();

int main(){
    //ejercicio18_7();
    //ejercicio18_11();
    //ejercicio18_19();
    //ejercicio18_21();
    //ejercicio18_22();
    //ejercicio18_27();
    return 0;
}
//18.7 (Cifrado simple) Cierta información en Internet se puede cifrar con un algoritmo simple conocido como “rot13”, el
//cual rota cada carácter 13 posiciones en el alfabeto. Así, 'a' corresponde a 'n', y 'x' corresponde a 'k'. rot13 es un ejemplo
//del cifrado de clave simétrica. Con este tipo de cifrado, tanto el que cifra como el que descifra utilizan la misma clave.
void ejercicio18_7(){

    int clave=13,a;
    string texto,datos("abcdefghijklmonqrstuvwxyz");
    cout<<"ingrese palabra a cifrar: \n";
    cin>>texto;

    for(int i=0;i<texto.length();i++){
          a=datos.find(texto[i]);
                if(a==-1)
                    cout<<" ";


                if (a<=clave){
                    texto[i]=datos.at(a+clave);

                }
                else if(a>datos.length()-clave){
                    texto[i]=datos.at((a-datos.length())+clave);


                }

    }
    cout<<"la palabra cifrada es: \n"<<texto;
}
//18.11 Escriba un programa que introduzca por separado un primer nombre y un apellido, y que concatene los dos en un
//nuevo objeto string.
void ejercicio18_11(){
    string a,b;
    cout<<"INGRESE NOMBRE  \n";
    cin>>a;
    cout<<"INGRESE APELLIDO  \n";
    cin>>b;
    string c(a+b);
    cout<<"NOMBRE COMPLETO: \n"<<c;

}
//18.19 Escriba un programa que inserte los caracteres "******" en la mitad exacta de un objeto string.
void ejercicio18_19(){
    string a("HOLA"),b("******");
    a.insert(a.length()/2,b);
    cout<<a;
}
//18.21 Escriba un programa que introduzca una línea de texto, reemplace todos los signos de puntuación con espacios y utilice
//la función strtok de la biblioteca de cadenas estilo C para dividir el objeto string en palabras individuales (tokens).
void ejercicio18_21(){
//18.22 Escriba un programa que introduzca una línea de texto y la imprima al revés. Use iteradores en su solución.
//18.22 Escriba un programa que introduzca una línea de texto y la imprima al revés. Use iteradores en su solución.
    char b[100], signos[]=":;.,?¿!;";
    cout<<" INGRESE UNA PALABRA: \n";
    cin>>b;
    char* point;
    point= strtok(b,signos);
    while(point!=NULL){
        cout<<point<<"\n",
        point=strtok(NULL,signos);
    }
}
void ejercicio18_22(){
    string cadena;
    cout<<"INGRESE UNA PALABRA: \n";
    cin>>cadena;
    string::const_iterator iterador1 = cadena.end();

    iterador1--;
    while ( iterador1 != cadena.begin()-1 )
    {

        cout << *iterador1; // desreferencia el iterador para obtener un char
        iterador1--; // avanza el iterador al siguiente char
    }  // fin de while

 cout << endl;


}
//18.27 Escriba una versión de la rutina de ordenamiento por selección (fi gura 8.28) que ordene objetos string. Use la función
//swap en su solución.
void ejercicio18_27(){
    string a("hola");
    string b("alo");
}

