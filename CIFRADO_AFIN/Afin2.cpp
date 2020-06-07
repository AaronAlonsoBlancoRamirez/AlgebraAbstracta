#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>

class afin{

    public:
        afin();
        afin(int,int);
        int clave1,clave2;
        string cifrar(string);
        string descifrar(string);
        string alfabeto;
        int inversa(int,int);
        int generar_clave_a();
        int generar_clave_b();
        int resto(int ,int );
        int euclides(int,int);
        int obtener_clave_a();
        int obtener_clave_b();
};
afin::afin(){
    alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    clave1=generar_clave_a();
    clave2=generar_clave_b();

}
afin::afin(int clave_a,int clave_b){
    alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    clave1=inversa(clave_a,alfabeto.length());
    clave2=clave_b;
}
int main(){

    int ca,cb;
    string mensaje,mensaje_cifrado,mensaje_descifrado;
    afin emisor;
    cout<<"\nINGRESE UNA PALABRA PARA CIFRARLA: ";
    getline(cin,mensaje);
    cout<<"\nPALABRA CIFRADA: ";
    mensaje_cifrado=emisor.cifrar(mensaje);
    afin receptor(emisor.obtener_clave_a(),emisor.obtener_clave_b());
    //cout<<"\n"<<emisor.obtener_clave_a()<<" "<<emisor.obtener_clave_b();
    cout<<"\nMENSAJE DESCIFRADO: ";
    mensaje_descifrado=receptor.descifrar(mensaje_cifrado);
    return 0;
}
int afin::obtener_clave_a(){
    return clave1;
}
int afin::obtener_clave_b(){
    return clave2;
}

int afin::generar_clave_a(){
    srand(time(NULL));
    int clave_a,tam;
    tam=alfabeto.length();
    do{
        clave_a=1+rand()%(1001-1);

    }while(euclides(clave_a,tam)!=1);

    return clave_a;
}
int afin::generar_clave_b(){
    int clave_b,tam;
    tam=alfabeto.length();
    clave_b=1+rand()%(1001-1);
    clave_b=resto(clave_b,tam);

    return clave_b;

}
int afin::euclides(int a, int b){
    int r;
    do{
        r=resto(a,b);
        a=b;
        b=r;
    }while(r!=0);

    return a;

}
int afin::resto(int a,int b){
        int r;
        r=a-((a/b)*b);
        if(r<0){
            r=b-r;
        }
        return r;
}
string afin::cifrar(string mensaje){
    int tam=alfabeto.length();
    int pos_letra,pos_letra_cifrada;
    string palabra_cifrada;

    for(int i=0;i<mensaje.length();i++){
        pos_letra=alfabeto.find(mensaje[i]);
        pos_letra_cifrada=((pos_letra*clave1)+clave2)%tam;
        palabra_cifrada=palabra_cifrada+alfabeto.at(pos_letra_cifrada);
    }
    cout<<palabra_cifrada;
    return palabra_cifrada;

}

string afin::descifrar(string mensaje){
    cout<<"\n LAS CLAVES GENERADAS FUERON: "<<clave1<<" "<<clave2<<"\n";
    int tam=alfabeto.length();
    int pos_letra_cifrada,pos_letra_descifrada;
    string palabra_descifrada;

    for(int i=0;i<mensaje.length();i++){
        pos_letra_cifrada=alfabeto.find(mensaje[i]);
        pos_letra_descifrada=(clave1*(pos_letra_cifrada-clave2))%(tam);
        if(pos_letra_descifrada<0){
            pos_letra_descifrada=pos_letra_descifrada+tam;
        }

        palabra_descifrada=palabra_descifrada+alfabeto.at(pos_letra_descifrada);
    }
    cout<<palabra_descifrada;
    return palabra_descifrada;
}
int afin::inversa(int a, int b){

	int mod=b;
	int mcd = 0;

	int r1 = a, r2 = b;
	int s1 = 1, s2 = 0;
	int t1 = 0,	t2 = 1;
	int s;
	int t;
	while (r2 > 0)
	{
		int q = r1 / r2;

		int r = r1 - (q * r2);
		r1 = r2; r2 = r;

		s = s1 - (q * s2);
		s1 = s2; s2 = s;

		t = t1 - (q * t2);
		t1 = t2; t2 = t;
	};

	s = s1;
	t = t1;
	mcd = r1;

	if(mcd ==1){
        if(s<0){
        s=s+b;
        }
        return s;
	}
	else {
        return 0;
	}
}
