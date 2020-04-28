#include<conio.h>
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

void funcion1();
void funcion2();
void funcion4();
void funcion5();
void funcion6();
void funcion7();
void funcion8();
void funcion9();
void funcion10();
void funcion11();
void funcion12();
void funcion13();

int main(){

    //funcion1();
    //funcion2();
    //funcion4();
    //funcion5();
    //funcion6();
    //funcion7();
    //funcion8();
    //funcion9();
    //funcion10();
    //funcion11();
    //funcion12();
    funcion13();
    return 0;
}
//EJERCICIO 1 (PRACTICA LABORATORIO)
void funcion1(){

    string s = "universidaducsp";
    char o[s.length()];
    string a;

    string::const_iterator iterador1 = s.begin();
    int cont = 0;
    while (iterador1 != s.end()) {
        o[cont]=*iterador1;
        iterador1++;
        cont++;
    }
    cout << o <<"\n";
}
//EJERCICIO 3 (PRACTICA LABORATORIO)
//Convertir las letras de un string de minúsculas a mayúsculas, y las mayúsculas a
//minúsculas.
void funcion2(){

  string cadena2("UNIVERSIDAD");
  string cadena1("ucsp");

  cout<<"palabra "<<cadena2<<" es ahora: ";
  for(int i=0;i<cadena2.length();i++){
          cadena2[i]=tolower(cadena2[i]);
          cout<<cadena2[i];
  }
  cout<<"\n";

  cout<<"palabra "<<cadena1<<" es ahora: ";
  for(int i=0;i<cadena1.length();i++){
          cadena1[i]=toupper(cadena1[i]);
          cout<<cadena1[i];
  }
  cout<<"\n";

}
//EJERCICIO 4(PRACTICA LABORATORIO)
//Recibir dos números por consola en variables tipo entero, luego construir un objeto
//string que concatene el primer número seguido del segundo número. Imprimir la
//cadena resultante, y en una nueva línea su valor multiplicado por 2. Usar funciones para
//convertir de string a entero y visceversa.
 void funcion4( ){

  int n1,n2;
  cout<<"ingrese los 2 numeros: \n";
  cin>>n1>>n2;
  string w1,w2,w3,w4;
  w1=to_string(n1);
  w2=to_string(n2);
  w3=w2+w1;
  cout<<w3<<"\n";

  n1=n1*2;
  n2=n2*2;


  w1=to_string(n1);
  w2=to_string(n2);
  w3=w2+w1;
  cout<<w3<<"\n";

}
//EJERCICIO 5(PRACTICA LABORATORIO)
//Crear un objeto string que esté formado por 1000 caracteres ‘a’, escribiendo una sola línea de código
void funcion5(){
  string a(1000,'a');
  cout<<a<<"\n";
}
//EJERCICIO 6(PRACTICA LABORATORIO)
//Convertir la cadena: “Yo desaprobe el curso de Algebra Abstracta” a la cadena: “Yo aprobe el curso de Algebra Abstracta”.
void funcion6(){

//EJERCICIO 7(PRACTICA LABORATORIO)
//Recibir dos strings por entrada estándar, una frase y una palabra. Contar cuántas veces aparece la palabra en la frase.
string a("Yo desaprobe el curso de Algebra Abstracta");
    a.erase(3,3);
    cout<<a;
}
//EJERCICIO 7(PRACTICA LABORATORIO)
//Recibir dos strings por entrada estándar, una frase y una palabra. Contar cuántas veces aparece la palabra en la frase.
void funcion7(){
    string a,b;
    int found=-1,cont=0;
    cout<<"INGRESE FRASE: \n";
    getline(cin,a);
    cout<<"INGRESE PALABRA: \n";
    cin>>b;

    do{
        found=a.find(b,found+1);
        if(found!=-1){
            cont++;
        }
    }while(found!=-1);
    cout<<"\nse encontro la palabra "<<b<<" "<<cont<<" veces \n";
}
//EJERCICIO 8(PRACTICA LABORATORIO)
//Recibir un string de longitud N e imprimir cada letra del string en una nueva línea usando iteradores.
void funcion8(){
  string b;
  cout<<"INGRESE LA PALABRA:\n";
  cin>>b;
  string::const_iterator iterador = b.begin();
  cout<<"ITERACION A TRAVES DEL OBJETO STRING:\n";
  while (iterador != b.end()) {
    cout<<*iterador;
    iterador++;
  }
  cout<<"\n";

}
//EJERCICIO 9(PRACTICA LABORATORIO)
//Recibir dos strings por consola e imprimir un string que tenga al segundo string en la mitad el primer string.
//El primer string siempre tiene tamaño par.
void funcion9(){
    string a,b;
    cout<<"INGRESE LA PRIMERA PALABRA\n";
    cin>>a;
    while(a.length()%2!=0){
        cout<<"INGRESE OTRA PALABRA..\n";
        cin>>a;
    }
    cout<<"INGRESE LA SEGUNDA PALABRA\n";
    cin>>b;
    a.insert(a.length()/2,b);
    cout<<a;
}
//EJERCICIO 10(PRACTICA LABORATORIO)
//Recibir tres strings por consola, buscar todas las apariciones del segundo string en el primero
//y reemplazarlas por el tercer string recibido.
void funcion10(){
    string a,b,c;
    cout<<"ingrese la frase: \n";
    getline(cin,a);
    cout<<"ingrese una palabra: \n";
    cin>>b;
    cout<<"ingrese otra palabra: \n";
    cin>>c;
    int pocision=-1;
    do{
        pocision=a.find(b,pocision+1);
        if(pocision !=-1){
            a.replace(pocision,c.length(),c);
        }

    }while(pocision!=-1);
    cout<<a;
}
//EJERCICIO 11(PRACTICA LABORATORIO)
//Dadas dos palabras, imprimir la que es lexicográficamente mayor.
void funcion11(){
    string a("boton"),b("computadora");
    string datos("abcdefhijklmnopqrstuvwxyz");
    cout<<"palabras: \n"<<a<<"\n"<<b<<"\n\n";
    int x,y,i=0;
    bool z{false};
    while(z!=true){
        x=datos.find(a.at(i));
        y=datos.find(b.at(i));
        if(x==y){
            i++;
        }
        else if(x>y){
            cout<<"palabra lexicograficamente mayor: "<<a<<"\n";
            z=true;
        }
        else{
            cout<<"palabra lexicograficamente mayor: "<<b<<"\n";
            z=true;
        }
    }
}
//EJERCICIO 12(PRACTICA LABORATORIO)
//Crear una función que reciba un número N (N va de 1 a 10), y que escriba N números con valores que van de 1 a 1000
//en un archivo llamado “numeros.txt”.
void funcion12(){
   ifstream archivo;
   string texto;
   int op,cont=0;
   cout<<"ingrese un numero del 1 al 10\n";
   cin>>op;
   archivo.open("numeros.txt",ios::in);
   if(archivo.fail()){
        cout<<"\nNO SE PUEDO ABRIR EL ARCHIVO";
        exit(1);
   }
   while(!archivo.eof()&& cont<op){
        getline(archivo,texto);
        cout<<texto<<"\n";
        cont=cont+1;
   }
   archivo.close();
}
//EJERCICIO 13(PRACTICA LABORATORIO)
//Leer los números en el archivo “numeros.txt” de la pregunta 10 e imprimir la sumatoria.
void funcion13(){
   ifstream archivo;
   string texto;
   int sum=0,a;
   archivo.open("numeros.txt",ios::in);
   if(archivo.fail()){
        cout<<"\nNO SE PUEDO ABRIR EL ARCHIVO";
        exit(1);
   }
   while(!archivo.eof()){
        getline(archivo,texto);
        a=stoi(texto);
        sum=sum+a;
   }
   cout<<"la sumatoria de los numeros en el archivo es: \n"<<sum;
}



