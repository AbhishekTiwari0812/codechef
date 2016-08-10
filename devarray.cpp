#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	//cin>>t;
	t=1;
	while(t--){
		int max = INT_MIN;
		int min = INT_MAX;
		int n,q;
		cin>>n>>q;
		int temp;
		for(int i=0;i<n;i++){
			cin>>temp;
			if(temp < min)
				min = temp;
			if(temp > max)
				max = temp;
		}
		while(q--){
			cin>>temp;
			if(temp >= min && temp <= max)
				cout<<"Yes\n";
			else
				cout<<"No\n";
		}	
	}
}