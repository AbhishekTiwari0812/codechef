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

vector<int> ans;

long add(int i){
	long num = 0;
	int p = 0;
	while(i > 0){
		if(i&1){
			num+=ans[p];
		}
		i/=2;
		p++;
	}
	return num;
}

int main(){
	FastIO
	int t;
	cin>>t;
	long a[1<<15];
	while(t--){
		ans.clear();
		int n;
		cin>>n;
		f(i,0,1<<n){
			cin>>a[i];
		}
		if(n==1){
            if(a[1])
            cout<<a[1]<<endl;
            else cout<<a[0]<<endl;
            continue;
		}
		else if(n==0){
            cout<<0<<endl;
            continue;
		}
		map<long,int> s;
		f(i,0,1<<n){
			s[a[i]]++;
		}
		map<long, int>::iterator it;
		s[0]--;
		if( s[0] == 0 )
			s.erase( 0 );
		f(i,0,n){
			it = s.begin();
			cout<<"pushing:"<<(it->first)<<endl;
			ans.push_back( it->first );
			it->second--;
			if(it->second == 0)
				s.erase( it );
			if(i==0 || i == 1)
				continue;
			f(j,(1<<(i-1))+1,(1<<i)){
				long rem = add(j);
				s[rem]--;
				cout<<"Removing:"<<rem<<endl;
				if(s[rem]==0){
					s.erase(rem);
				}
			}
		}
		//cout<<"ans:";
		f(i,0,ans.size()){
			cout<<ans[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
