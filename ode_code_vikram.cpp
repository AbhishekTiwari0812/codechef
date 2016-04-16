#include <vector>
#include <iostream>
#include <climits>
using namespace std;
typedef long long int lli;
struct node {
	vector<node *>nbd;
	bool visited;
};
node **G;
int n;
int dfs_visit(node *current){
	int count=1;
	for(int i=0;i<current->nbd.size();i++){
		if(!current->nbd[i]->visited){
			current->nbd[i]->visited=true;
			count+=dfs_visit(current->nbd[i]);
		}
	}
	return count;
}

vector<int> DFS(){
	vector<int> comps;
	for(int i=0;i<n;i++)
		if(!G[i]->visited){
			G[i]->visited=true;
			comps.push_back(dfs_visit(G[i]));
		}
	return comps;
}
vector<int> vals;
int size;
lli **DP;
lli Min(lli a,lli b){
    return a<b?a:b;
}

lli knapsack(int w,int index){
    if(w==0)
    	return 0;
    else if(index==size || w<0)
    	return INT_MAX;
    else{
    	lli a=INT_MAX,b=INT_MAX;
    	if(index+1 < size && w-vals[index]>=0){
    		if(DP[w-vals[index]][index+1]==-1){
    			a=knapsack(w-vals[index],index+1)+1;
    			DP[w-vals[index]][index+1]=a;
    		}
    		else a=DP[w-vals[index]][index+1]+1;
    	}
    	else a=knapsack(w-vals[index],index+1)+1;
    	if(index+1 < size && w>=0){
    		if(DP[w][index+1]==-1){
    			b=knapsack(w,index+1);
    			DP[w][index+1]=b;
    		}
    		else b=DP[w][index+1];
    	}
    	else b=knapsack(w,index+1);
    	return Min(a,b);
    }
}

int main(){
	int m;
	cin>>n>>m;
	G=new node*[n];
	for(int i=0;i<n;i++){
		G[i]=new node;
		G[i]->visited=false;
	}
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		a-=1;
		b-=1;
		G[a]->nbd.push_back(G[b]);
		G[b]->nbd.push_back(G[a]);
	}
	vals=DFS();
	size=vals.size();
	int k;
	cin>>k;
	DP=new lli*[k+1];
	for(int i=0;i<k+1;i++){
		DP[i]=new lli[size];
		for(int j=0;j<size;j++)
			DP[i][j]=-1;
	}
	lli answer=knapsack(k,0);
	if(answer >= INT_MAX){
        answer=-1;
        cout<<answer<<endl;
	}
	cout<<(answer-1)<<endl;
	return 0;

}
