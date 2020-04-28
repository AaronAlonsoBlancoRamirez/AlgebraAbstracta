#include <iostream>
using namespace std;
#include <stdlib.h>
#include <ctime>


class euclides{

    private:
        long res;
        int cont=0,cont1=0;
    public:
        euclides();
        long resto(long ,long);
        long formula1(long,long);
        long formula2(long,long);
        long formula3(long,long);
        long formula4(long,long);
        long formula5(long,long);
        long formula6(long,long);
};
euclides::euclides(){

}

long euclides::resto(long a,long b){
        int c;
        c=a-((a/b)*b);
        return c;
}

long euclides::formula1(long a, long b){
    long r;
    r=resto(a,b);
    if(r==0){     //EN ESTA FUNCION SI EL RESTO ES 0 ENTONCES EL MCD ES B
        cont=0;
        return b;
    }
    else{        //IGUAL A ---> B Y EL B ---> RESTO Y SE LLAMA LA FUNCION RECURSIVAMENTE
        cont++;
        a=b;
        b=r;
        cout<<"el valor de a y b en la vuelta "<<cont<<" es: "<<a<<" "<<b<<"\n";
        formula1(a,b);
    }
}

long euclides::formula2(long a, long b){
    long r;
    r=resto(a,b);
    if(r==0){            //SI EL RESTO ES 0 , B ES EL MCD
        cont=0;
        return b;
    }
    if(r>b/2){         //SI EL RESTO ES MAYOR QUE LA MITAD DE B ENTONCES REEMPLAZA B , ACORTANDO LA CANTIDAD DE VUELTAS A COMPARACION                       // DEL ALGORITMO 1
        r=b-r;         //DEL ALGORITMO 1
    }
    cont++;            //SI NO CUMPLE CON NINGUN "IF" ENTONCES A--->B Y B--->R Y SE LLAMA LA FUNCION RECURSIVAMENTE
    a=b;
    b=r;
    cout<<"el valor de a y b en la vuelta "<<cont<<" es: "<<a<<" "<<b<<"\n";
    formula2(a,b);
}

long euclides::formula3(long a,long b){
    int r;
    if(b==0){         //SI EL RESTO ES IGUAL A 0 , EL MCD ES B
        return a;
        cont=0;
    }
    cont++;
    cout<<"despues de "<<cont<<" vuelta a y b son "<<a<<" "<<b<<"\n";
    return formula3(b,resto(a,b));       //SE LLAMA A LA FUNCION RECURSIVAMENTE PONIENDO B COMO VALOR DE A Y EL RESTO COMO B
}                                        //ACORTANDO LA CANTIDAD DE OPERACIONES Y MEJORANDO EL ALGORITMO

long euclides::formula4(long a,long b){
  if(abs(b)>abs(a)){      //ESTE ALGORITMO COMO SE PUEDE VER NO UTILIZA BUCLES ,SI LOS PARAMETROS FUERAN NEGATIVOS
    return formula4(b,a); //SE LE CONVIERTEN A POSITIVOS PARA QUE EL ALGORITMO PUEDA FUNCIONAR
  }                       // SE LLAMA A LA FUNCION RECURSIVAMENTE PARA CREAR UN BUCLE
  cont1++;
  cout<<"despues de la vuelta "<<cont1<<" a y b son: "<<a<<" "<<b<<"\n";
  if(b==0){ // SI B ES IGUAL A 0 ENTONCES EL MCD SERIA A
    cont1=0;
    return a;
  }
  if(resto(a,2)==0&&resto(b,2)==0){ //EN ESTE CONDICIONAL IF Y LOS SIGUIENTES SE ENFOCA EN REDUCIR A Y B A SU MITAD
    return 2*formula4(a/2,b/2);
    cont1++;
  }
  if(resto(a,2)==0&&resto(b,2)!=0){
    return formula4(a/2,b);
    cont1 ++;
  }
  if(resto(a,2)!=0&&resto(b,2)==0){
    return formula4(a,b/2);
    cont1 ++;
  }
  else{
    return formula4((a-b)/2,b);   //SI NO SE PUDO REDUCIR A Y B RETORNA LA FUNCION PARA QUE PUEDAN SER REDUCIBLES
    cont1 ++;                     //ALA SIGUIENTE VUELTA
  }
}

long euclides::formula5(long a,long b){

    int g=1,t;
    while(resto(a,2)==0 && resto(b,2)==0){     //ESTE ALGORITMO ES BUENO CON NUMEROS PARES YA QUE A Y B SE REDUCIRIAN RAPIDAMENTE
        a=a/2;
        b=b/2;                                 //ESTE WHILE REDUCE A Y B HASTA QUE DEJE DE SER DIVISIBLE ENTRE 2
        cont1++;
        cout<<"despues de la vuelta "<<cont1<<" el valor de a y b es:  "<<a<<" "<<b<<"\n";
    }
    while(a!=0){
          cout<<"despues de la vuelta "<<cont1<<" el valor de a y b es:  "<<a<<" "<<b<<"\n";
          while(resto(a,2)==0){
            a=a/2;
          }
          while(resto(b,2)==0){
            b=b/2;
          }
          t=abs(a-b)/2;
          if(a>=b){
            a=t;
          }
          else{
            b=t;
          }
    cont1++;
    }
    cont1=0;
    return g*b;
}

long euclides::formula6(long a,long b){

  while(a!=b){          //ESTE ALGORITMO REDUCE A Y B , RESTANDO AL MAYOR MENOS EL MENOR
    if(a>b){            //ESTE ALGORITMO TERMINA CUANDO A SEA IGUAL A B
      cont1++;          //NO ES MUY BUENO YA QUE LAS CONODICIONALES SON MUY SIMPLES POR LO TANTO DARA MUCHAS VUELTAS
      cout<<"en la vuela "<<cont1<<" los valores de a y b son "<<a<<" "<<b<<"\n";
      a=a-b;
    }
    else{
      cont1++;
      b=b-a;
      cout<<"en la vuela "<<cont1<<" los valores de a y b son "<<a<<" "<<b<<"\n";
    }
  }
  return a;
}


int main(){

    euclides ejemplo;
    long n1=1859521085 , n2=1548965595;
    int a,b,c,d,e,f;
    cout<<"ALGORITMO 1:\n";
    clock_t t,t2;
    t=clock();
    a=ejemplo.formula1(n1,n2);
    t=clock()-t;
    cout<<"\nTIEMPO QUE TARDO EL ALGORITMO 1: "<<float(t)/CLOCKS_PER_SEC<<" segundos\n";
    //cout<<" \nel mcd de "<<n1<<" y "<<n2<<" es: "<<a<<"\n";
    cout<<"\nALGORITMO 2:\n"; //ESTE ALGORITMO DEMORA 0.005 seg.
    t=clock();
    b=ejemplo.formula2(n1,n2);
    t=clock()-t;
    cout<<"\nTIEMPO QUE TARDO EL ALGORITMO 2: "<<float(t)/CLOCKS_PER_SEC<<" segundos";
    cout<<"\nALGORITMO 3:\n";
    t=clock();
    c=ejemplo.formula3(n1,n2);
    t=clock()-t;
    cout<<"\nTIEMPO QUE TARDO EL ALGORITMO 3: "<<float(t)/CLOCKS_PER_SEC<<" segundos\n";
    cout<<"\nALGORITMO 4:\n";
    t=clock();
    d=ejemplo.formula4(n1,n2);
    t=clock()-t;
    cout<<"\nTIEMPO QUE TARDO EL ALGORITMO 4: "<<float(t)/CLOCKS_PER_SEC<<" segundos\n";
    cout<<"\nALGORITMO 5:\n";
    t=clock();
    e=ejemplo.formula5(n1,n2);
    t=clock()-t;
    cout<<"\nTIEMPO QUE TARDO EL ALGORITMO 5: "<<float(t)/CLOCKS_PER_SEC<<" segundos\n";;
    cout<<"\nALGORITMO 6:\n";
    t=clock();
    e=ejemplo.formula6(n1,n2);
    t=clock()-t;
    cout<<"\nTIEMPO QUE TARDO EL ALGORITMO 6: "<<float(t)/CLOCKS_PER_SEC<<" segundos\n";;

    return 0;
}
