#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int A[n*m];
		int temp;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>temp;
				index=;
				A[index]=temp;
			}
		}
		for(int i=0;i<n*m;i++)
			cout<<A[i]<<" ";
		cout<<endl;
	}
	return 0;
}