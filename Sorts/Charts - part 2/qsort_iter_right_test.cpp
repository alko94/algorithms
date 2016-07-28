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

class stack
{
    public:
        stack(int n);
        ~stack();
        void push(int x);
        int  pop();
        bool isNotEmpty();

    private:
        int w, *s, limit;
};

stack::stack(int n)
{
    limit = n;
    s = new int[n];
    w = 0;
}

stack::~stack()
{
    delete [] s;
}

void stack::push(int x)
{
    if(w<limit) s[w++]=x;
}

int stack::pop()
{
    if(w) return s[--w];
    return -1;
}

bool stack::isNotEmpty()
{
   if (w>0) return true;
   else return false;
}

void quicksort(int n, int tab[])
{
    int lewy=0;
    int prawy=n-1;
    stack stos(n);
    int sr=0;
    while (lewy<prawy || stos.isNotEmpty())
    {
        int sr;
        if(lewy<prawy)
        {
            sr=prawy;
            for(int i=prawy-1; i>=lewy; i--)
                if(tab[prawy]<tab[i]) swap(tab[--sr], tab[i]);
            swap(tab[sr], tab[prawy]);
            if (sr-lewy<prawy-sr)
            {
                stos.push(sr+1);
                stos.push(prawy);
                prawy=sr-1;
            }
            else
            {
                stos.push(lewy);
                stos.push(sr-1);
                lewy=sr+1;
            }
        }
        else
        {
            prawy=stos.pop();
            lewy=stos.pop();
        }
    }
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
    
    printf("quicksort iter right key (time in seconds)\n");
    
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











