#include<stdio.h>
#include<math.h>

int countPrimes(int n);

int main(){
    printf("%d",countPrimes(100));
}

int countPrimes(int n)
{
    int IsPrimes[n];
    int PrimesNum=0;
    for(int i=2; i<n; i++)
        IsPrimes[i]=1;
    // remove the times of primes.
    for(int i=2; i<=sqrt(n); i++)
        if(IsPrimes[i])
            for(int j=i; j*i<=n; j++)
                IsPrimes[j*i]=0;
    // count the number of primes.
    for(int i=2; i<n; i++)
        if(IsPrimes[i])
            PrimesNum++;
    return PrimesNum;
}