#include <iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		int *A=new int[26];
		int *B=new int[26];
		for(int i=0;i<26;i++){
			A[i]=B[i]=0;
		}
		for(int i=0;i<a.length();i++)
			A[a[i]-'a']++;
		for(int i=0;i<b.length();i++)
			B[b[i]-'a']++;
		bool flag=false;
		for(int i=0;i<26;i++){
			if(A[i]>0 && B[i]>0)
				flag=true;
		}
		if(flag)
			cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;

}