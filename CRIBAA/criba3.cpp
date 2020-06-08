#include <iostream>
using namespace std;

void criba(int);
int main(){
    int a;
    cin>>a;
    criba(a);


}

void criba(int N){
  int i,j , a[N+1],cont=0;
  for(a[1]=0,i=2;i<=N;i++){ // DE LA POCISION 2 HASTA N, SERA "1" OSEA VERDADERO , YA QUE LA POCISION 0 Y 1 NO SON PRIMOS
    a[i]=1;
  }
  for(i=2; i<=N/2;i++){
    for(j=2;j<=N/i;j++){
      if(a[i*j]!=0){
            a[i*j]=0;   //MULTIPLOS NO PODRAN SER PRIMOS , ENTONCES SERAN 0
      }

    }
  }
  for(i=1;i<=N;i++){
    if(a[i]){
      cout<<i<<" ";
      cont++;
    }

  }
  cout<<"\n";
  cout<<cont;




}
