#include <iostream>
using namespace std;

long long int reminder(long long int &X,int &Y,int &N){
	long long int result=1;
	for(int i=0;i<Y;i++){
		result*=X%N;
		result%=N;
	}
	return result%N;

}

int main(){

	int test;
	cin>>test;
	long long int X;
	int Y,N;	
	cin>>N;
	for(int i=0;i<test;i++){
		cin>>X;
		cin>>Y;
		cout<<reminder(X,Y,N)<<endl;

	}
	return 0;
}