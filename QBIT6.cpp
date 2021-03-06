#include<iostream>
#include<vector>
#include <cstdio>
using namespace std; 
/* This function calculates (a^b)%MOD */
long long pow(int a, int b, int MOD)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return x;
}
 
/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(int n, int MOD)
{
    return pow(n,MOD-2,MOD);
}
 
long long C(int n, int r, int MOD)
{
    vector<long long> f(n + 1,1);
    for (int i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}
 

int main()
{       
    int MOD = 1000000007;
    int test;
    cin>>test;
    int n,k;
    int m;
    long long int total;
    
    for(int some=0;some<test;some++){
        cin>>n>>k;
        total=0;
        m=n/k;
        for(int i=0;i<=m;i++){
            if(i > n-i*k+i)
                continue;
            total+=C(n-i*k+i,i,MOD);
            total%=MOD;
        }
        cout<<total<<endl;

    }

    
}