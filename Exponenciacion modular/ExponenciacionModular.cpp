#include <iostream>
#include <NTL/ZZ.h>
using namespace NTL;

ZZ    factorizando_potencia(ZZ ,ZZ ,ZZ );
ZZ    potencia(ZZ ,ZZ );
ZZ    resto(ZZ ,ZZ );

int main(){
    return 0;
}
ZZ factorizando_potencia(ZZ pos_letra,ZZ e,ZZ N){
    bool a=true;
    ZZ potencia_1 ,potencia_2;
    potencia_1=1;
    potencia_2=2;
    ZZ aux2;
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
                    }
                    else{
                        pos_letra_cifrada=resto(potencia(pos_letra_cifrada,potencia_2),nuevo_N);
                        piv=resto(pos_letra_cifrada*piv,nuevo_N);
                    }

                    //cout<<"\nvalor de piv es: "<<piv<<" "<<" valor de pos letra: "<<pos_letra_cifrada<<endl;

                }
                else if(e%2==0){


                    pos_letra_cifrada=resto(potencia(pos_letra_cifrada,potencia_2),nuevo_N);
                    //cout<<"\nvalor de pos letra: "<<pos_letra_cifrada<<endl;
                }

                e=e/2;

            }
            if((e-1)==-1){
                break;
            }
       }
       return piv;
}

ZZ potencia(ZZ base, ZZ elevar) {
    ZZ total, i;
    total = 1; i = 0;
    for (i; i < elevar; i++) {
        total *= base;
    }
    return total;
}


ZZ resto(ZZ a,ZZ b){
        ZZ r;
        r=a-((a/b)*b);
        if(r<0){
            r=b-r;
        }
        return r;
}
