#include <NTL/ZZ.h>           //ALGORITMOS DE MCD USANDO LA LIBRERIA NTL
#include <iostream>
using namespace std;
using namespace NTL;
#include <stdlib.h>
#include <ctime>


class algoritmomcd{

    private:
        ZZ res;
    public:
        algoritmomcd();
        ZZ resto(ZZ ,ZZ);
        ZZ algoritmo1(ZZ ,ZZ);
        ZZ algoritmo2(ZZ ,ZZ);
        ZZ algoritmo3(ZZ ,ZZ);
        ZZ algoritmo4(ZZ ,ZZ);
        ZZ algoritmo5(ZZ ,ZZ);
        ZZ algoritmo6(ZZ ,ZZ);

};
algoritmomcd::algoritmomcd(){

}

ZZ algoritmomcd::resto(ZZ a,ZZ b){
        ZZ r;
        r=a-((a/b)*b);
        if(r<0){
            r=b-r;
        }

        return r;
}

ZZ algoritmomcd::algoritmo1(ZZ a, ZZ b){
    ZZ r;                       //SI ES QUE AL INGRESAR LOS PARAMTROS A ES MAYOR A B ENTONCES DARA UNA VUELTA DEMAS
    do{                         //PARA CAMBIAR LOS VALORES E INVERTIRLOS
        r=resto(a,b);
        a=b;
        b=r;
        //cout<<a<<" "<<b<<" ";    //SI DESCOMENTA ESTE COUT SE PUEDE VER EL PROCESO DEL ALGORITMO
    }while(r!=0);

    return a;

}
ZZ algoritmomcd::algoritmo2(ZZ a,ZZ b){

    ZZ r;
    r=resto(a,b);
    while(r!=0){
            //cout<<a<<" "<<b<<" ";   //SI DESCOMENTA ESTE COUT SE PUEDE VER EL PROCESO DEL ALGORITMO
            if(r>b/2){
                r=b-r;
            }
            a=b;
            b=r;
            r=resto(a,b);
    }
    return b;
}
ZZ algoritmomcd::algoritmo3(ZZ a,ZZ b){
    ZZ r;
    if(b==0){         //SI EL DIVIDENDO ES IGUAL A 0 , EL MCD ES A
        return a;

    }
    //cout<<"valor de a y b son "<<a<<" "<<b<<"\n";    //SI DESCOMENTA ESTE COUT SE PUEDE VER EL PROCESO DEL ALGORITMO
    return algoritmo3(b,resto(a,b));       //SE LLAMA A LA FUNCION RECURSIVAMENTE PONIENDO B COMO VALOR DE A Y EL RESTO COMO B
}                                        //ACORTANDO LA CANTIDAD DE OPERACIONES Y MEJORANDO EL ALGORITMO

ZZ algoritmomcd::algoritmo4(ZZ a,ZZ b){
  ZZ c;
  c=2;
  if(abs(b)>abs(a)){               //ESTE ALGORITMO COMO SE PUEDE VER NO UTILIZA BUCLES ,SI LOS PARAMETROS FUERAN NEGATIVOS
    return algoritmo4(b,a);        //SE LE CONVIERTEN A POSITIVOS PARA QUE EL ALGORITMO PUEDA FUNCIONAR
  }                                // SE LLAMA A LA FUNCION RECURSIVAMENTE PARA CREAR UN BUCLE

  //cout<<a<<" "<<b<<" \n";   //SI DESCOMENTA ESTE COUT SE PUEDE VER EL PROCESO DEL ALGORITMO
  if(b==0){                        // SI B ES IGUAL A 0 ENTONCES EL MCD SERIA A

    return a;
  }
  if(resto(a,c)==0&&resto(b,c)==0){ //EN ESTE CONDICIONAL IF Y LOS SIGUIENTES SE ENFOCA EN REDUCIR A Y B A SU MITAD
    return 2*algoritmo4(a/2,b/2);

  }
  if(resto(a,c)==0&&resto(b,c)!=0){
    return algoritmo4(a/2,b);

  }
  if(resto(a,c)!=0&&resto(b,c)==0){
    return algoritmo4(a,b/2);

  }
  else{
    return algoritmo4((a-b)/2,b);   //SI NO SE PUDO REDUCIR A Y B RETORNA LA FUNCION PARA QUE PUEDAN SER REDUCIBLES
                         //ALA SIGUIENTE VUELTA
  }

}

ZZ algoritmomcd::algoritmo5(ZZ a,ZZ b){
    ZZ g,t,value;
    g=1;
    value=2;
    while(resto(a,value)==0 && resto(b,value)==0){     //ESTE ALGORITMO ES BUENO CON NUMEROS PARES YA QUE A Y B SE REDUCIRIAN RAPIDAMENTE
        a=a/2;
        b=b/2;                                 //ESTE WHILE REDUCE A Y B HASTA QUE DEJE DE SER DIVISIBLE ENTRE 2

        cout<<" el valor de a y b es:  "<<a<<" "<<b<<"\n";
    }
    while(a!=0){

          while(resto(a,value)==0){
            a=a/2;
          }
          while(resto(b,value)==0){
            b=b/2;
          }
          t=abs(a-b)/value;
          if(a>=b){
            a=t;
          }
          else{
            b=t;
          }
          //cout<<" el valor de a y b es:  "<<a<<" "<<b<<"\n"; //SI DESCOMENTA ESTE COUT SE PUEDE VER EL PROCESO DEL ALGORITMO
    }
    return a;
}
ZZ algoritmomcd::algoritmo6(ZZ a,ZZ b){

  while(a!=b){          //ESTE ALGORITMO REDUCE A Y B , RESTANDO AL MAYOR MENOS EL MENOR
    if(a>b){            //ESTE ALGORITMO TERMINA CUANDO A SEA IGUAL A B
                        //NO ES MUY BUENO YA QUE LAS CONODICIONALES SON MUY SIMPLES POR LO TANTO DARA MUCHAS VUELTAS
      cout<<" los valores de a y b son "<<a<<" "<<b<<"\n";
      a=a-b;
    }
    else{

      b=b-a;
      cout<<" los valores de a y b son "<<a<<" "<<b<<"\n";
    }
  }
  return a;
}




int main()
{
   algoritmomcd objeto;
   ZZ a, b, c,d;
   clock_t t;

   cin >> a;
   cin >> b;

   t=clock();
   d=objeto.algoritmo6(a,b); //Se puede probar con cualquier algoritmo
   t=clock()-t;
   cout<<"\nTIEMPO QUE TARDO EL ALGORITMO : "<<float(t)/CLOCKS_PER_SEC<<" segundos\n";
   cout<<"\nmcd :"<<d<<"\n";
   system("pause");
   return 0;

}
