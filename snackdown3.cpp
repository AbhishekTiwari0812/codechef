#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli gcd(lli a,lli b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
lli minv(lli a,lli b){
	return a>b?b:a;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	lli a,b,c,d;
	while(t--){
		cin>>a>>b>>c>>d;
		lli g=gcd(c,d);
		if(b < a){
			lli k = (a-b)/d;
			k+=2;
			b=b+k*d;
		}
		lli remain = (b-a)%g;
		cout<<minv(remain,g-remain)<<endl;
	}

}
