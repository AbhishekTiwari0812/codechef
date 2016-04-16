#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#define PI (3.14)

using namespace std;

struct point{
	long double x,y;
	int cat;
	point(long double x,long double y){
		this->x=x;
		this->y=y;
	}
};
long double cat(point p){
	int cat;
	long double x=p.x;
	long double y=p.y;
	if(y >=0 && x>0)
		return 1;
	else if( y<=0 && x<0)
		return 1;
	else if( x<=0 && y >0)
		return 2;
	else if(x>=0 && y< 0)
		return 2;
}
bool cmp(point a,point b){
	if(a.x==b.x)
		return a.y<b.y;
	else return a.x<b.x;
}
long double dist(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
long double all_pair_max(vector<point > p){
	long double max=-1;
	long double temp;
	for(int i=0;i<p.size()-1;i++){
		for(int j=i+1;j<p.size();j++){
			temp=dist(p[i],p[j]);
			if(temp > max)
				max=temp;
		}
	}
	return max;
}
void print(vector<point> v){
	for(int i=0;i<v.size();i++)
		cout<<"("<<v[i].x<<","<<v[i].y<<")"<<endl;
		cout<<endl;
}


int main(){
	int n;

  /*  ifstream in;
    in.open("input.txt");
	*/vector<point> list1;
	vector<point> list2;
	cin>>n;
	long double a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		point temp(a,b);
		if(cat(temp)==1)
			list1.push_back(temp);
		else list2.push_back(temp);
	}
	sort(list1.begin(),list1.end(),cmp);
	sort(list2.begin(),list2.end(),cmp);
	print(list1);
	print(list2);
	vector<point >v;
	if(list1.size()>0){
		v.push_back(list1[0]);
		v.push_back(list1[list1.size()-1]);
	}
	if(list2.size()>0){
		v.push_back(list2[0]);
		v.push_back(list2[list2.size()-1]);
	}
	print(v);
	cout<<floor(all_pair_max(v))<<endl;
	return 0;
}
