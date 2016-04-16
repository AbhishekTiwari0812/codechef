#include <cmath>
#include <iostream>
#define MOD (int)(1e9+7)
typedef long long int lli;
using namespace std;

int main(){
	lli  t;
	cin>>t;
	lli m,n,k,temp;
	lli temp2;
	while(t--){
		cin>>n>>m>>k;
		lli answer=0;
		for(int i=0;i<n;i++){
			cin>>temp;
			if(temp < k)
				answer=(answer+k)%MOD;
			else if(temp - m*k > k)
				answer=(answer+ temp-((m*k)%MOD)%MOD);
			else{
				temp2=(lli)ceil((double)(temp-k)/(double)k);
				answer=(answer + temp - ((temp2*k)%MOD))%MOD;
			}
           // cout<<answer<<endl;
		}
		cout<<(answer%MOD)<<endl;
	}
	return 0;
}
