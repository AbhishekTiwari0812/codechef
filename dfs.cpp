#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


typedef struct node{
    long long int value;
    bool visited;
    vector<struct node*>neighbours;
    
}node;

void dfs_visit(node *current){
   current->visited=true;
   for(long long int i=0;i<current->neighbours.size();i++){
       if(current->neighbours[i]->visited!=true){
           dfs_visit(current->neighbours[i]);
           current->neighbours[i]->visited=true;
       }
           
   }
}
long long int n;
node **G;
long long int components;
void DFS(){
    for(long long int i=0;i<n;i++){
        if(G[i]->visited!=true){
            components++;
            dfs_visit(G[i]);
        }
    }
}

int main() {
    long long int test;
    cin>>test;
    for(long long int something=0;something<test;something++){
        components=0;
        cin>>n;
        long long int k;
        G=new node*[n];
        for(long long int i=0;i<n;i++){
            G[i]=new node;
            G[i]->visited=false;
        }
        for(long long int i=0;i<n;i++){
            cin>>k;
            k-=1;
            G[i]->neighbours.push_back(G[k]);
        }
        DFS();
        cout<<components<<endl;
    }
    return 0;
}
