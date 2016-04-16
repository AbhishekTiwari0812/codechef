#include <iostream>

#include <vector>
using namespace std;




class Node{
	public: 
		int value;
		vector <int> neighbours_id;

};


int main(){

	int number_of_nodes;
	cin>>number_of_nodes;
	Node *nodes_in_tree;
	nodes_in_tree= new Node[number_of_nodes];
	int value;
	//assigning values to each node
	for(int i=0;i<number_of_nodes;i++){
		cin>>value;
		nodes_in_tree[i].value=value;
	}
	//directed edges;
	int number_of_edges;
	cin>>number_of_edges;
	for(int i=0;i<number_of_edges;i++){
		int node1;
		int node2;
		cin>>node1;			//assumes node number starting from 1.
		cin>>node2;
		nodes_in_tree[node1-1].neighbours_id.push_back(node2-1);
		//for undirected 
		//nodes_in_tree[node2-1].neigbours.push_back(nodes_in_tree[node1-1]);
	}



}