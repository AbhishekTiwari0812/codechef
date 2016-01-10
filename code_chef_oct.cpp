#include <iostream>
#define INF ((1<<31)-1)

using namespace std;

int main(){
	int test,n;
	cin>>test;
	for(int i=0;i<test;i++){
		cin>>n;
		int sum=0;
		int count=0;
		int current;
		int previous=INF;
		for(int j=0;j<n;j++){
			cin>>current;
			if(current >= previous)
				count++;
			else {
				sum+=count*(count+1)/2;
				count=0;
			}
			previous=current;
		}
		sum+=count*(count+1)/2;
		cout<<(sum+n)<<endl;
	}
	return 0;
}