#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

struct point{
	double x,y;
	int cat;
	point(double x,double y){
		this->x=x;
		this->y=y;
		if((x>=0 && y>0)||( x<=0 && y<0))
			cat=1;
		else if(( x<0 && y>=0) ||(x>0 && y<=0))
			cat=2;
        else if(x==0 && y==0)
            cat=1;
	}
	double dist(point p){
		return sqrt((p.x-this->x)*(p.x-this->x) +(p.y-this->y)*(p.y-this->y));
	}
};

int cmp(point a,point b){
	if(a.x==b.x){
		return a.y-b.y;
	}
	else return a.x-b.x;
}

double all_pair_max(vector<point > p){
	double max=-1;
	double temp;
	for(int i=0;i<p.size()-1;i++){
		for(int j=i+1;j<p.size();j++){
			temp=p[i].dist(p[j]);
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
	cin>>n;
	vector<point> cat1;
	vector<point> cat2;
	for(int i=0;i<n;i++){
		double a,b;
		cin>>a>>b;
		point temp(a,b);
		switch(temp.cat){
			case 1:
				cat1.push_back(temp);
			break;
			case 2:
				cat2.push_back(temp);
			break;
		}
	}
	vector<point> v;
	sort(cat1.begin(),cat1.end(),cmp);
	sort(cat2.begin(),cat2.end(),cmp);
	print(cat1);
	print(cat2);
	if(cat1.size()>0){
        sort(cat1.begin(),cat1.end(),cmp);
        point p1=cat1[cat1.size()-1];
        v.push_back(p1);
	}
	cout<<floor(all_pair_max(v))<<endl;
	return 0;
}
