#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void p(int *A,int n){
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int *A=new int[n];
		long sum=0;
		for(int i=0;i<n;i++){
			cin>>A[i];
			sum+=A[i];
		}
		/*if(sum%n!=0){
			cout<<"No Treat"<<endl;
			continue;
		}*/
		int avg=(int)(sum/(long)n);
		sort(A,A+n);
		int start=0;
		int end=n-1;
		long answer=0;
		int needs,has;
		while(start!=end){
			needs=avg-A[start];
			has=A[end]-avg;
			//p(A,n);
			if(needs>has){
				answer+=has;
				A[start]+=has;
				A[end]-=has;
				end--;

			}
			else{
				answer+=needs;
				A[end]-= needs;
				A[start]+=needs;
				start++;
			}
			//p(A,n);
			//cout<<answer<<endl;
		}
		bool flag=true;
		for(int i=0;i<n-1;i++)
			if(A[i]!=A[i+1]){
				flag=false;
				break;
			}
		if(flag)
			cout<<answer<<endl;
		else cout<<"No Treat"<<endl;

	}
}