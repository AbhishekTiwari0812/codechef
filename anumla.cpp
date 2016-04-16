//correct solution
//fine tune it to overcome TLE.
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long int lli;
vector<int> a;
int n;		//size of the vector
 
 
multiset<int> expected;
multiset<int> already;
 
void p(){
	for(int i=0;i<a.size();i++)
		printf("%d ",a[i]);
	printf("\n");
	return;
}
void change_set(int x){
	multiset<int>::iterator it;
	vector<int>temp;
	for(it=already.begin();it!=already.end();it++){
		temp.push_back((*it)+x);
	}
	for(int i=0;i<temp.size();i++){
		already.insert(temp[i]);
		expected.insert(temp[i]);
	}
	already.insert(x);
	a.push_back(x);
	//p();
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		expected.clear();
		already.clear();
		a.clear();
		int size;
		scanf("%d",&size);
		int temp;
		scanf("%d",&temp);
		for(int i=0;i<(1<<size)-1;i++){
			scanf("%d",&temp);
			if(expected.find(temp)!=expected.end())
				expected.erase(temp);
			else{
				change_set(temp);
			}
		}
		p();
 
	}
	return 0;
}