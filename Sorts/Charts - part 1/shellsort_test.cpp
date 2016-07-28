#include <stdio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

const int maks = 10000000;
int tab[maks];


// N*T <= maks !!!!
int N; //How large data set to sort?
int T; //How many times repeat this sort?

/********** Definitions of sort functions ***************/
void shellsort (int n, int tab[])
{
    int k[8];
    k[0]=701;
    k[1]=301;
    k[2]=132;
    k[3]=57;
    k[4]=23;
    k[5]=10;
    k[6]=4;
    k[7]=1;

    int ile;
    if (n<4) ile=1;
    else if (n<10) ile=2;
    else if (n<23) ile=3;
    else if (n<57) ile=4;
    else if (n<132) ile=5;
    else if (n<301) ile=6;
    else if (n<701) ile=7;
    else ile=8;
    
    for (int z=ile; z>0; z--)
    {
        for (int i=k[8-z]; i<n; i++)
        {
            int pom=tab[i];
            int j;
            for (j=i; j>=k[8-z] && tab[j-k[8-z]]>pom; j-=k[8-z])
            {
                tab[j] = tab[j-k[8-z]];
            }
            tab[j] = pom;
        }
    }
}

//you are to define SOMESORT as name of the function with arg1 = int n and arg2 = int tab[] for timing to work!!!
#define SOMESORT shellsort

/*******************************************************/


clock_t clk;

int main()
{
    int NN[] = {100,200,300,400,500,600,700,800,900,1000};
    int TT[] = {10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};
    srand(time(0));
    
    /********** Name of the algorithm here *****************************/
    
    printf("shellsort (time in seconds)\n");
    
    /*******************************************************************/
    printf("n\trandom    constant  ascending descending A-shaped\n");
    for(int kk=0; kk<10; ++kk){
        N=NN[kk];
        T=TT[kk];
        
        int limit = N*T;
        
        if(limit>maks) {
            printf("k=%d: Zmniejsz N albo T\n",kk);
            return 0;
        }
        
        printf("%d\t ",N);
        
        //generate random
        for(int i=0; i<limit; ++i) tab[i]=rand()%N;
        //timeit
        clk = clock();
        for(int i=0; i<limit; i+=N) SOMESORT(N,tab+i);
        clk = clock()-clk;
        printf("%f  ", (double(clk)/CLOCKS_PER_SEC)/T );
        
        //generate const
        for(int i=0, r=rand()%N; i<limit; ++i) tab[i]=r;
        //timeit
        clk = clock();
        for(int i=0; i<limit; i+=N) SOMESORT(N,tab+i);
        clk = clock()-clk;
        printf("%f  ", (double(clk)/CLOCKS_PER_SEC)/T );
        
        //generate ascending
        for(int i=0; i<limit; ++i) tab[i]=i;
        //timeit
        clk = clock();
        for(int i=0; i<limit; i+=N) SOMESORT(N,tab+i);
        clk = clock()-clk;
        printf("%f  ", (double(clk)/CLOCKS_PER_SEC)/T );
        
        //generate ascending
        for(int i=0; i<limit; ++i) tab[i]=limit-i;
        //timeit
        clk = clock();
        for(int i=0; i<limit; i+=N) SOMESORT(N,tab+i);
        clk = clock()-clk;
        printf("%f  ", (double(clk)/CLOCKS_PER_SEC)/T );
        
        //generate ascending
        for(int i=0; i<limit; ++i) tab[i]=(i%2?i:limit-i);
        //timeit
        clk = clock();
        for(int i=0; i<limit; i+=N) SOMESORT(N,tab+i);
        clk = clock()-clk;
        printf("%f  ", (double(clk)/CLOCKS_PER_SEC)/T );
        
        
        
        printf("\n");
    }
   
    return 0;
}











