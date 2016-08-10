#include <iostream>
#include <map>
#define MOD 1000000007
typedef long long int lli;
using namespace std;

int a[(int)1e5+1];
int n;
int s[(int)1e5+1];

void calc(){
	s[0]=a[0];
	for(int i=1;i<n;++i){
		s[i]=s[i-1]+a[i];
	}
}

lli f(lli x,lli y,int l){	
	if(y<x)
		return 0;
	if(l==0){
		x-=1;
		y-=1;
		if(x!=0)
			return s[y]-s[x-1];
		else
			return s[y];
	}
	else{
    	bool f1=(x%2==1?true:false);
		bool f2=(y%2==1?true:false);
		lli bs;
		if(f1 && f2){ 
			lli hx = (x+1)/2;
			lli hy = (y+1)/2;
			if(x!=y)
                bs = 2*f(hx,hy,l-1) + f(hx+1,hy-1,l-1);
            else
                bs= f(hx,hx,l-1);
		}
		else if(f1 && !f2){	
			bs = (f(x,y-1,l)+f(y/2,y/2+1,l-1));
		}
		else if(!f1 && f2)
			bs = (f(x+1,y,l)+ f(x/2,x/2+1,l-1));
		else{
            if(x!=y)
                bs = f(x+1,y-1,l) + f(x/2,x/2+1,l-1 ) + f(y/2,y/2+1,l-1);
            else
                bs=f(y/2,y/2+1,l-1);
		}
		return bs%MOD;
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int m;
		lli x,y;
		cin>>n>>m>>x>>y;
		for(int i=0;i<n;i++)
			cin>>a[i];
		calc();
		cout<<f(x,y,m)<<'\n';
	}
    return 0;
}
