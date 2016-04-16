#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int t;
	//cin>>t;
	scanf("%d",&t);
	int n,temp,temp2,count;

	while(t--!=0){
		scanf("%d",&n);
		scanf("%d",&temp);
		int i;
		count=0;
		for(i=0;i<n;i++){
            scanf("%d",&temp2);
            if(temp2>temp)
                count++;
		}
		printf("%d\n",count);

	}
	return 0;
}
