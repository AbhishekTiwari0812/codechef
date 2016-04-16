#include <iostream>
#include <cstdio>
#define MOD (int)(1e9+7)
using namespace std;
typedef long long int lli;

lli pow_mod(lli a,lli b){
	if(b==0)
		return 1;
	lli m=pow_mod(a,b/2);
	if(b&1)
		return (((m*m)%MOD)*a)%MOD;
	else return (m*m)%MOD;
}



int main(){
	int t;
	scanf("%d",&t);
	lli n,x,m;
	while(t--){
        scanf("%lld%lld%lld",&n,&x,&m);
        lli *A=new lli[n];
        for(int i=0;i<n;i++)
            scanf("%lld",&A[i]);
        lli sum=0;
        lli p=1;
        lli count=1;
        if(m==0)
            printf("%d\n",(A[x-1]%MOD));
        else{
            for(int i=x-1;i>=0;i--){
                cout<<"value:"<<((A[i]%MOD)*p)%MOD<<endl;
                sum += ((A[i]%MOD)*p)%MOD;
                count++;
                if(m!=1)
                    p=(p+pow_mod(count,m-2))%MOD;
            }
            printf("%d\n", (sum%MOD));
        }

	}
	return 0;
}
