#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define f(i,a,b) for(int i = (a), __ = (b); i < __; ++i)
#define fr(i,a,b) for(int i = (a), __ = (b); i >= __; --i)
#define pb push_back
#define mp make_pair
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


int main(){
	FastIO
	ll a[(int)1e5+3];		//1s
	ll b[(int)1e5+3];		//2s
	int n;
	cin>>n;
	int p=0,q=0;
	int s = 0;
	f(i,0,n){
		int w,c;
		cin>>w>>c;
		s += w;
		if(w==1)
			a[p++]=c;
		else
			b[q++]=c;
	}
	sort(a,a+p);
	sort(b,b+q);
	ll ans = 0;
	int p1=p-1;		//pointer for 1
	int p2=q-1;		//pointer for 2
	f(i,1,s+1){
		/*if(p1 < 0 || p2 < 0){
			cout<<"There's some problem\n";
			return 0;
		}*/
		if(i&1){	//if i is odd
			cout<<ans + a[p1] <<' ';
		}
		else{
			bool flag;	//true if 1s are better
			if(p1 - 1 >= 0 ){
				ll ans1 = a[p1] + a[p1-1];
				ll ans2;
				if(p2 < 0)
					ans2 = INT_MIN;
				else
					ans2 = b[p2];
				if(ans1 > ans2){
					ans += ans1;
					p1 -= 2;
					cout<<ans<<' ';
				}
				else{
					ans += ans2;
					p2 -= 1;
					cout<<ans<<endl;
				}
			}
			else{
				ans += b[p2];
				p2--;
				cout<<ans<<' ';
			}
		}
	}
	return 0;
}
