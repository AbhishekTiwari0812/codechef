#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		double n;
		scanf("%lf",&n);
		double answer=0.0;
		for(double i=1.0;i<=n;i++){
			answer+= (n/i);
		}
		printf("%.6lf\n",answer );
	}
	return 0;
}
