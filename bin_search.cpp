#include <iostream>

using namespace std;

int bin_search(int *A,int left,int right,int key){
	int mid=(left+right)/2;
	if(mid<right){
		if(A[mid]==key)
			return mid;
		else if(A[mid]>key)
			return bin_search(A,left,mid,key);
		else return bin_search(A,mid+1,right,key);
	}
	else return mid;
}

int main(){

	int *A;
	int N,Q,X,K,type;
	cin>>N>>Q;
	int current_index;
	int req;	
	A=new int[N];
	for(int i=0;i<N;i++)
		cin>>A[i];
	for(int i=0;i<Q;i++){
		cin>>X>>K>>type;
		current_index= bin_search(A,0,N-1,X);
		if(type==1){
			if(A[current_index] >= X)
				req=current_index-K;
			else 
				req=current_index-K+1;
			
		}
		else{
			if(A[current_index] <= X)
				req=current_index+K;
			else 
				req=current_index+K-1;


		}
		if(req<0 || req >=N)
			cout<<-1<<endl;
		else cout<<A[req];
	}

	return 0;
}