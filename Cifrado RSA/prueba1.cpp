#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <sstream>
#include <NTL/ZZ.h>
using namespace NTL;


class rsa {

    long long p,q,fi_N,d,e;

    public:
        rsa(long long &,long long&);
        long long N;
        string alfabeto;
        string cifrar(string);
        string descifrar();
        long long generar_p();
        long long generar_q();
        long long generar_e();
        ZZ resto(ZZ,ZZ);
        //int euclides(int,int);
        long long inversa(long long,long long);
        ZZ factorizando_potencia(ZZ,ZZ);
        string ToString(const ZZ&);
        ZZ potencia(ZZ,ZZ);
        bool criba(long long,long long);
        void get();
};


rsa::rsa(long long& a,long long& b){
    alfabeto={"ABCDEFGHIJKLMNOPQRSTUVWXYZ "};
    p=generar_p();
    q=generar_q();
    N=p*q;
    fi_N=(p-1)*(q-1);
    e=generar_e();
    a=N;
    b=e;
    d=inversa(e,fi_N);
}

bool rsa::criba(long long N,long long num){
  long long i,j , a[N+1],cont=0;


  for(a[1]=0,i=2;i<=N;i++){
    a[i]=1;
  }
  for(i=2; i<=N/2;i++){
        for(j=2;j<=N/i;j++){
            if(a[i*j]){
                a[i*j]=0;
            }
        }
  }
  if(a[num]==0){
    return false;
  }
  else{
    return true;
  }

}

long long rsa::generar_e(){
    srand(time(NULL));
    long long rango=100;
    do{
        e=1+rand()%(rango-1);

    }while(!criba(fi_N,e));
    cout<<"valor de e: "<<e<<endl;
    return e;
}
long long rsa::generar_p(){

    srand(time(NULL));
    long long rango=1000;
    do{
        p=1+rand()%(rango-2);

    }while(!criba(rango,p));
    cout<<"valor de p: "<<p<<endl;
    return p;

}
long long rsa::generar_q(){
    srand(time(NULL));
    long long rango=999;
    do{
        q=1+rand()%(rango-3);

    }while(!criba(rango,q));
    cout<<"valor de q: "<<q<<endl;
    return q;
}
void rsa::get(){
    cout<<"valor de N: "<<N<<endl;
    cout<<"valor de fi_N: "<<fi_N<<endl;
    cout<<"valor de d: "<<d;
}

long long rsa::inversa(long long a, long long b){

	long long mod=b;
	long long mcd = 0;

	long long r1 = a, r2 = b;
	long long s1 = 1, s2 = 0;
	long long t1 = 0,	t2 = 1;
	long long s;
	long long t;
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
string rsa::cifrar(string mensaje){
    //tenemos "e"
    //MENSAJE SERA "HOLA"
    string letra_cifrada,palabra_cifrada;
    ZZ pos_letra,pos_letra_cifrada,nuevo_E;
    //int nuevo_N=731,piv=1;
    nuevo_E=e;
    for(int i=0; i<mensaje.length();i++){
        pos_letra=alfabeto.find(mensaje[i]);
        cout<<"\npos letra: "<<pos_letra<<endl;
        pos_letra_cifrada=factorizando_potencia(pos_letra,nuevo_E);

        //e=n;
        letra_cifrada=ToString(pos_letra_cifrada);
        palabra_cifrada=palabra_cifrada+letra_cifrada;
        cout<<endl<<letra_cifrada;
    }
    cout<<endl<<palabra_cifrada;
    return palabra_cifrada;


}

string rsa::ToString(const ZZ &z){
    stringstream buffer;
    buffer << z;
    return buffer.str();
}
ZZ rsa::resto(ZZ a,ZZ b){ //152587890625 - 423733
        ZZ r;
        r=a-((a/b)*b);
        if(r<0){
            r=b-r;
        }
        return r;
}

ZZ rsa::factorizando_potencia(ZZ pos_letra,ZZ e){
    bool a=true;
    ZZ potencia_1 ,potencia_2;
    potencia_1=1;
    potencia_2=2;
    ZZ aux=e;
    ZZ  piv;
    piv=1;
    ZZ pos_letra_cifrada;
    ZZ nuevo_N;
    nuevo_N=N;
    while(a){
            if(e>=0){
                if(e%2==1){
                    if(e==aux){
                        pos_letra_cifrada=resto(potencia(pos_letra,potencia_1),nuevo_N);
                        piv=resto(pos_letra_cifrada*piv,nuevo_N);
                        //piv=pos_letra_cifrada;
                    }
                    else{
                        pos_letra_cifrada=resto(potencia(pos_letra_cifrada,potencia_2),nuevo_N);
                        piv=resto(pos_letra_cifrada*piv,nuevo_N);
                        //piv=pos_letra_cifrada;
                    }

                    cout<<"\nvalor de piv es: "<<piv<<" "<<" valor de pos letra: "<<pos_letra_cifrada<<endl;
                    //cout<<"1"<<" ";
                }
                else if(e%2==0){
                    //cout<<"0"<<" ";

                    pos_letra_cifrada=resto(potencia(pos_letra_cifrada,potencia_2),nuevo_N);
                    cout<<"\nvalor de pos letra: "<<pos_letra_cifrada<<endl;
                }

                e=e/2;
                //potenciador=potenciador*2;
                //cout<<prob<<" ";

            }
            if((e-1)==-1){
                break;
            }
       }
       return piv;



}

ZZ rsa::potencia(ZZ base, ZZ elevar) {
    ZZ total, i;
    total = 1; i = 0;
    for (i; i < elevar; i++) {
        total *= base;
    }
    return total;
}
int main(){

    long long e,N;
    rsa receptor(e,N);
    receptor.get();
    string mensaje;
    //cout<<endl<<e<<endl<<N;
    receptor.cifrar("Z ");
    //getline(cin,mensaje);
    //a.cifrar(mensaje);
    return 0;

}
