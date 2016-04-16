#include <iostream>
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

lli gcdExtended(lli a, lli b, lli *x, lli *y){
    if (a == 0){
        *x = 0, *y = 1;
        return b;
    }
    lli x1, y1;
    lli gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}


lli modInverse(lli a, lli m){
    lli x, y;
    lli g = gcdExtended(a, m, &x, &y);
    lli res = (x%m + m) % m;
    return res;
}


lli inverse_mod(lli den){
	return modInverse(den,(lli)MOD);
}


lli cal_sum(lli n,lli k){
    if(n==1 && k==1)
        return 1;
    if(k==0)
        return n;
    else if(k<0)
        return 1;
	lli a=pow_mod(n,k+1);
	a-=1;
    a+=MOD;
	a%=MOD;
	lli b=inverse_mod(n-1);
	return (a*b)%MOD;
}




int main(){
	int t;
	cin>>t;
	lli n,x,m;
	while(t--){
        cin>>n>>x>>m;
        lli *A=new lli[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        lli sum=0;
        if(m==0)
            cout<<A[x-1]<<endl;
        else{
            for(lli i=x-1;i>=0;i--){
                cout<<"n="<<(x-i)<<" k="<<(m-2)<<" sum="<<cal_sum(x-i,m-2)<<endl;
                sum+=(cal_sum(x-i,m-2)*A[i])%MOD;
            }
            cout<<(sum%MOD)<<endl;
        }
	}
	return 0;
}
