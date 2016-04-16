#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int *A=new int[n];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	sort(A,A+n);
	if(n==1){
		cout<<A[0]<<endl;
		return 0;
	}
	vector<int> B;
	B.push_back(A[0]);
	int last=0;
	for(int i=0;i<n;i++)
		if(!(B[last]==A[i])){
			B.push_back(A[i]);
			last++;
		}
	n=B.size();
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	int max=B[n-2];
	for(int i=0;i<n-1;i++){
		if((B[n-1]%B[i]) > max)
			max=B[n-1]%B[i];
	}
	cout<<max<<endl;
	return 0;
}