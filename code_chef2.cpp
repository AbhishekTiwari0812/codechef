#include <iostream>
#include <string>

using namespace std;

string cipher_and_print(string s){
	string temp;
	for(int i=0;i<s.length();i++){
		if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')){
			if(s[i]=='z')
				temp+='a';
			else if(s[i]=='Z')
				temp+='A';	
			else 
				temp+=s[i]+1;
		}
	}
	return temp;

}

int main(){

	int test;
	cin>>test;
	string s;
	for(int i=0;i<test+1;i++){
		getline(cin,s);
		if(i!=0)
			cout<<cipher_and_print(s)<<endl;
	}
}