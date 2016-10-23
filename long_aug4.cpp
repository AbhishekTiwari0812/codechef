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
const int size=(int)5e5+5;
ll h[size];
ll r[size];
ll start_time[size];
ll end_time[size];

int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		f(i,0,n)
			cin>>h[i]>>r[i];
	}
	compute_time();
	return 0;
}