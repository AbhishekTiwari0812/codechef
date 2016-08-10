#include <bits/stdc++.h>
#define SIZE (int)1e6+5
using namespace std;

bool dp[SIZE];


void fill(){
	dp[1]=true;
	dp[2]=false;
	dp[3]=true;
	dp[4]=false;
	dp[5]=true;
	for(int i=6;i<SIZE;++i){
		dp[i] = !(dp[i-1] && dp[i-3] && dp[i-5]);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fill();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(dp[n])
			cout<<"JENNY\n";
		else
			cout<<"JACK\n";
	}
	return 0;
}
