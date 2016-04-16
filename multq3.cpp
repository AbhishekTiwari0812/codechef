//incomplete
#include <cstdio>
#include <iostream>
using namespace std;


struct node{
	int vals[3];
	node *l;
	node *r;
	node *p;
	int k;			//rotation value
	int l_index;
	int r_index;
};

node *create_node(){
	node *temp=new node;
	temp->l=NULL;
	temp->r=NULL;
	temp->p=NULL;
	temp->k=0;
	return temp;
}
node *construct_tree(int *A,int start,int end){
	if(start==end){
		node *temp=create_node();
		for(int i=0;i<3;i++)
			temp->vals[i]=0;
		temp->vals[A[start]%3]++;
		temp->l_index=start;
		temp->r_index=end;
		return temp;

	}else{
		int mid=(start+end)/2;
		node *left=construct_tree(A,start,mid);
		node *right=construct_tree(A,mid+1,end);
		node *root=new node;
		root->k=0;
		root->l=left;
		root->r=right;
		left->p=root;
		right->p=root;
		root->l_index=start;
		root->r_index=end;
		for(int i=0;i<3;i++)
			root->vals[i]=root->l->vals[i]+root->r->vals[i];
		return root;
	}
}

int find(node *root,int left,int right,int k){
	if(root->l_index==left && root->r_index==right)
		return root->vals[(k+root->k)%3];
	int mid=(root->l_index+root->r_index)/2;
	if(right<=mid){
		return find(root->l,left,right,(k+root->k)%3);
	}
	else if(left > mid){
		return find(root->r,left,right,(k+root->k)%3);
	}else{
		return find(root->l,left,mid,(k+root->k)%3)+find(root->r,mid+1,right,(k+root->k)%3);
	}
}

void update(node *root,int left,int right){
    if(root==NULL)
        return;
	if(root->l_index==left && root->r_index==right)
		root->k=(root->k+1)%3;
	int mid=(root->l_index+root->r_index)/2;
	if(right<=mid){
		update(root->l,left,right);
	}
	else if(left > mid){
		update(root->r,left,right);
	}else{
		update(root->l,left,mid);
		update(root->r,mid+1,right);
	}
}

int main(){
	int n,q;
	scanf("%d",&n);
	scanf("%d",&q);
	int *A=new int[n];
	for(int i=0;i<n;i++)
		A[i]=0;

	node *root=construct_tree(A,0,n-1);
	int a,b,c;
	for(int i=0;i<q;i++){
		scanf("%d%d%d",&a,&b,&c);
		if(a==0){
			update(root,b,c);
		}
		else{
			printf("%d\n",find(root,b,c,0));
		}
	}
	cin>>n;
	return 0;
}
