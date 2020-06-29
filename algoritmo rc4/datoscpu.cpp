#include <Windows.h>
#include <iostream>
using namespace std;

static float CalculateCPULoad();
static unsigned long long FileTimeToInt64();
float GetCPULoad();
int generando_semillas(int);
int modulo(int,int);


int main()
{

    generando_semillas(10);

}

int modulo(int a,int b)
{
    int q=a/b;
    int r=a-q*b;
    if(r<0)
        r+=b;
    return r;
}

int generando_semillas(int maximo){
    int k[maximo];
    int s[maximo];
    int f=0;
    int index=0;
    int aux;
    while (index < maximo)
    {
        k[index]=GetCPULoad() * 100;
        cout<<k[index]<<endl;
        index++;
        Sleep(500);
    }
    //LLENANDO EL VECTOR S
    cout<<"VECTOR S AL PRINCIPIO: ";
    for(int j=0;j<maximo;j++){
        s[j]=j;
        cout<<s[j]<<" ";
    }
    cout<<endl;
    //REALIZANDO EL ALGORITMO DE RC4
    for(int i=0;i<maximo;i++){
        f=modulo(f+k[i]+s[i],maximo);
        aux=s[i];
        s[i]=s[f];
        s[f]=aux;
    }

    // IMPRIMIENDO VECTOR S CAMBIADO
    cout<<"VECTOR S AL FINAL: " ;
    for(int j=0;j<maximo;j++){
        cout<<s[j]<<" ";
    }

}


static float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
    static unsigned long long _previousTotalTicks = 0;
    static unsigned long long _previousIdleTicks = 0;

    unsigned long long totalTicksSinceLastTime = totalTicks - _previousTotalTicks;
    unsigned long long idleTicksSinceLastTime = idleTicks - _previousIdleTicks;


    float ret = 1.0f - ((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime) / totalTicksSinceLastTime : 0);

    _previousTotalTicks = totalTicks;
    _previousIdleTicks = idleTicks;
    return ret;
}

static unsigned long long FileTimeToInt64(const FILETIME & ft)
{
    return (((unsigned long long)(ft.dwHighDateTime)) << 32) | ((unsigned long long)ft.dwLowDateTime);
}

// Returns 1.0f for "CPU fully pinned", 0.0f for "CPU idle", or somewhere in between
// You'll need to call this at regular intervals, since it measures the load between
// the previous call and the current one.  Returns -1.0 on error.
float GetCPULoad()
{
    FILETIME idleTime, kernelTime, userTime;
    return GetSystemTimes(&idleTime, &kernelTime, &userTime) ? CalculateCPULoad(FileTimeToInt64(idleTime), FileTimeToInt64(kernelTime) + FileTimeToInt64(userTime)) : -1.0f;
}
