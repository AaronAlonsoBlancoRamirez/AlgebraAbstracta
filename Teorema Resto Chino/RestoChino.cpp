#include <iostream>
using namespace std;
#include <stdlib.h>
#include <math.h>
using namespace std;


int modulo(int ,int );
int inversa( int a,  int b);
int euclides(int a, int b);
int comprobando_primalidad(int,int);

int resto_chino(int pn[], int an[], int tam)
{

    int cont=0;
    for(int i=0;i<tam-1;i++){
        if(comprobando_primalidad(pn[i],pn[i+1])==0){
          cont++;
        }
    }
    if(cont==0){
        int P, Pi[tam],qi[tam], X;
        X = 0;
        P = 1;
        for (int i = 0; i < tam; i++) //MULTIPLICANDO TODOS LOS Pi , PARA OBTERNER "P"
        {
            P *= pn[i];
        }
        for (int i = 0; i < tam; i++)
        {
            Pi[i] = P / pn[i];
            qi[i] = inversa(Pi[i], pn[i]);
            X += an[i] * Pi[i] * qi[i];
        }
        cout <<endl<<" X = " << modulo(X, P) << " + " << P << "K"<< endl;
        return modulo(X, P);
    }
    else{
      cout<<"no existe primalidad entre los modulos"<<endl;
      return 0;
    }
}

int main()
{
    int nro;
    cout << "INGRESE CANTIDAD DE ECUACIONES A EVALUAR: ";
    cin >> nro;
    int pn[nro], an[nro];
    cout << "\nINGRESE LOS VALORES A EVALUAR\n";
    for (int i = 0; i < nro; i++)
    {
        cout << "\nINGRESE LA VARIABLE:\n";
        cin >> an[i];
        cout << "\nINGRESE EL MODULO:\n";
        cin >> pn[i];
    }
    resto_chino(pn, an, nro);
    return 0;
}
int comprobando_primalidad(int a,int b){

    if(euclides(a,b)==1){
        return 1;
    }
    else{
        return 0;
    }
}

int modulo(int a,int b)
{
    int q=a/b;
    int r=a-q*b;
    if(r<0)
        r+=b;
    return r;
}
int inversa( int a,  int b)
{
	if(euclides(a,b)==1){
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
        }

        s = s1;
        t = t1;
        mcd = r1;


        if(s<0){
            s=s+b;
        }
        return s;


    }
	else{
        return 0;
	}

}
int euclides(int a, int b){
    int r;
    do{
        r=modulo(a,b);
        a=b;
        b=r;
    }while(r!=0);

    return a;

}
