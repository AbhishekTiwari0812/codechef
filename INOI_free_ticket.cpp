#include <iostream>
#include <set>

using namespace std;

struct node{
	int id;
	int value;				//for priority
	vector<node *>nbd;
	vector<int> cost;
};

class comp{
public:
	bool operator()(node *a,node *b){
		if(a->value==b->value)
			return a->id<b->id;
		else
			return a->value<b->value;
	}
};
dijkstra(node start,node end){
	set<node *> pq;
	for(int i=0;i<size;i++){
		if(G[i]!=start)
			G[i]->value=INT_MAX;
		else 
			G[i]->value=0;
		pq.insert(G[i]);
	}
	set<node *,comp>::iterator it;
	while(pq.size()>0){
		it=pq.begin();
		node *temp;
		temp=*it;
	}
}

int main(){
	return 0;
}