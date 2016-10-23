#include <bits/stdc++.h>
#define f(i,a,b) for(int i=(a),__=(b);i < __; ++i)
using namespace std;
typedef long long int ll;

const int size=(int)1e5+5;
ll a[size];
bool visited[size];
ll start_time[size];
ll finish_time[size];
ll ans;
ll n;
ll TIME;

void init(){
	ans=0;
	TIME=0;
	f(i,0,n){
		start_time[i]=-1;
		finish_time[i]=-1;
		visited[i]=false;
	}
}

ll ni(ll i){
	ll next_index = (a[i] + i + 1) % n ;
	return next_index;
}
void dfs_visit(ll i){
	visited[i]=true;
	//cout<<"Visiting "<<i<<endl;
	start_time[i]=TIME++;
	ll next = ni(i);
	if(visited[next]){
        //cout<<"Next " <<next<<endl;
		if(finish_time[next]==-1){
			//cout<<"Ans "<<ans<<endl;
			ans += start_time[i] - start_time[next] + 1;
			//cout<<"Ans changed to "<<ans<<endl;
		}
	}
	else{
		dfs_visit(next);
	}
	finish_time[i]=1;
}

void dfs(){
	f(i,0,n){
		if(!visited[i]){
			dfs_visit(i);
		}
	}
	//cout<<"answer:"
	cout<<ans<<endl;

}


int main(){
    ll t;
    cin>>t;
    while(t--){
    	cin>>n;
    	init();
    	f(i,0,n){
    		cin>>a[i];
    	}
    	dfs();
    }


}
