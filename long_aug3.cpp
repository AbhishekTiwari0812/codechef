#include <bits/stdc++.h>
#define f(i,a,b) for(int i = (a), __ = (b); i < __; ++i)
#define fr(i,a,b) for(int i = (a), __ = (b); i >= __; --i)
#define pb push_back
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef set<string> ss;
typedef map<string,int> msi;
int gcd(int a,int b){if(b)return gcd(b,a%b);else return a;}
ll pow(ll a,ll x){if(x==0)return 1;else{ll b=pow(a,x/2);if(x%2==0)return b*b;else return a*b*b;}}


int n;
ll a[2*(int)1e5+4];
ll sum;


void solve(){
	int start=0;
	int end=-1;
	ll min_sum=LONG_MAX;
	ll current_sum=0;
	while(end < 2*n ){
		if(){
			end++;
			if(end == 2*n)
				break;
			current_sum += a[end];
			if(current_sum < min_sum)
				min_sum=current_sum;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		sum=0;
		cin>>n;
		f(i,0,n)
			cin>>a[i];
		f(i,n,2*n)
			a[i]=a[n-i];
		solve();
	}
	return 0;
}