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
void qsort(int tab[], int lewy, int prawy)
{
    int sr;
    if(lewy<prawy)
    {
        sr=rand()%(prawy-lewy)+lewy;
        swap(tab[sr], tab[prawy]);
        sr=prawy;
        for(int i=prawy-1; i>=lewy; i--)
            if(tab[prawy]<tab[i]) swap(tab[--sr], tab[i]);
        swap(tab[sr], tab[prawy]);
        qsort(tab, lewy, sr-1);
        qsort(tab, sr+1, prawy);
    }
}

void quicksort(int n, int tab[]) {
    qsort(tab,0,n-1);    
}

//you are to define SOMESORT as name of the function with arg1 = int n and arg2 = int tab[] for timing to work!!!
#define SOMESORT quicksort

/*******************************************************/


clock_t clk;

int main()
{
    int NN[] = {10,50,100,500,1000,2000,4000,6000,8000,10000};
    int TT[] = {1000000,100000,10000,1000,1000,100,100,10,10,10};
    srand(time(0));
    
    /********** Name of the algorithm here *****************************/
    
    printf("quicksort recur random key (time in seconds)\n");
    
    /*******************************************************************/
    printf("n\trandom    constant  descending A-shaped\n");
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
        
        
        //generate descending
        for(int i=0; i<limit; ++i) tab[i]=limit-i;
        //timeit
        clk = clock();
        for(int i=0; i<limit; i+=N) SOMESORT(N,tab+i);
        clk = clock()-clk;
        printf("%f  ", (double(clk)/CLOCKS_PER_SEC)/T );
        
        //generate A-shaped
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











