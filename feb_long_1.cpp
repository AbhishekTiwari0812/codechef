#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int *A=new int[n+1];
	for(int i=0;i<n+1;i++){
		A[i]=0;
	}
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		A[temp]++;
	}
	for(int i=0;i<n+1;i++){
		if(A[i]==0)
			cout<<(i)<<" ";
	}
	cout<<endl;
	return 0;
}
