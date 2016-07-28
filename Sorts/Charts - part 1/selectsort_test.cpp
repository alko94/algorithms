#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <utility>

using namespace std;

const int maks = 10000000;
int tab[maks];


// N*T <= maks !!!!
int N; //How large data set to sort?
int T; //How many times repeat this sort?

/********** Definitions of sort functions ***************/
void selectionsort (int n, int tab[])
{
    for (int i=0; i<n; i++)
    {
        int k=i;
        for (int j=i+1; j<n; j++)
        {
            if (tab[j]<tab[k]) k=j;
        }
        swap (tab[k], tab[i]);
    }
}

//you are to define SOMESORT as name of the function with arg1 = int n and arg2 = int tab[] for timing to work!!!
#define SOMESORT selectionsort

/*******************************************************/


clock_t clk;

int main()
{
    int NN[] = {100,200,300,400,500,600,700,800,900,1000};
    int TT[] = {10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};
    srand(time(0));
    
    /********** Name of the algorithm here *****************************/
    
    printf("selectionsort (time in seconds)\n");
    
    /*******************************************************************/
    printf("n\trandom    constant  ascending descending A-shaped\n");
    for(int k=0; k<10; ++k){
        N=NN[k];
        T=TT[k];
        
        int limit = N*T;
        
        if(limit>maks) {
            printf("k=%d: Zmniejsz N albo T\n",k);
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











