#include <iostream>
using namespace std;
#include <NTL/ZZ.h>
using namespace NTL;

ZZ multiplicacion_modular(ZZ , ZZ,ZZ );
ZZ exponenciacion_modular(ZZ ,ZZ ,ZZ );
ZZ modulo(ZZ ,ZZ );
ZZ resto_chino(ZZ);

int main(){
    ZZ a,N;
    cin>>a;
    cin>>N;
}

ZZ rresto_chino(ZZ val)
{
    ZZ q1, a1, q2, a2;
    q1 = inversa(modulo(q,p),p);
    a1 = exponenciacion_modular(modulo(val, p), modulo(d, p-1), p);
    q2 = inversa(modulo(p,q),q);
    a2 = exponenciacion_modular(modulo(val, q), modulo(d, q-1), q);
    return modulo(modulo(a1*q*q1,n)+modulo(a2*p*q2,n),n);
}
ZZ multiplicacion_modular(ZZ a, ZZ b,ZZ mod)
{
    return modulo((modulo(a, mod) * modulo(b,mod)), mod);
}
ZZ exponenciacion_modular(ZZ a,ZZ b,ZZ mod)
{
    ZZ resultado = ZZ(1);
    while(b>0){
        if((b&1)==1){
            resultado = multiplicacion_modular(resultado,a,mod);
        }
        a=multiplicacion_modular(a,a,mod);
        b=b/2;
    }
    return resultado;
}

ZZ modulo(ZZ a,ZZ b)
{
    ZZ q=a/b;
    ZZ r=a-q*b;
    if(r<0)
        r+=b;
    return r;
}







#include <iostream>
using namespace std;
#include <NTL/ZZ.h>
using namespace NTL;

ZZ multiplicacion_modular(ZZ , ZZ,ZZ );
ZZ exponenciacion_modular(ZZ ,ZZ ,ZZ );
ZZ modulo(ZZ ,ZZ );

int main(){
    ZZ a,N;
    cin>>a;
    cin>>N;
}

ZZ rsa::resto_chino(ZZ val)
{
    ZZ q1, a1, q2, a2;
    q1 = inversa(modulo(q,p),p);
    a1 = exponenciacion_modular(modulo(val, p), modulo(d, p-1), p);
    q2 = inversa(modulo(p,q),q);
    a2 = exponenciacion_modular(modulo(val, q), modulo(d, q-1), q);
    return modulo(modulo(a1*q*q1,n)+modulo(a2*p*q2,n),n);
}
ZZ multiplicacion_modular(ZZ a, ZZ b,ZZ mod)
{
    return modulo((modulo(a, mod) * modulo(b,mod)), mod);
}
ZZ exponenciacion_modular(ZZ a,ZZ b,ZZ mod)
{
    ZZ resultado = ZZ(1);
    while(b>0){
        if((b&1)==1){
            resultado = multiplicacion_modular(resultado,a,mod);
        }
        a=multiplicacion_modular(a,a,mod);
        b=b/2;
    }
    return resultado;
}

ZZ modulo(ZZ a,ZZ b)
{
    ZZ q=a/b;
    ZZ r=a-q*b;
    if(r<0)
        r+=b;
    return r;
}
