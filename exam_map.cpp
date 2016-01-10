#include <fstream>
#include <iostream>
#include <map>

using namespace std;

typedef struct pair{
	string value;
	int count;
}pair;

int main(int argc,char *argv[]){
	map < string , int > m;
	map < string , int > ::iterator j;
	ifstream in;
	ofstream out;
	in.open ( argv[1] );
	out.open("word_list.txt");
	string s;
	while(in >> s){
		m[s]++;
	}
	for(j=m.begin();j!=m.end();j++){
		out<<"word: "<<j->first<<" count: "<<j->second;
		out<<"\n";
	}

	return 0;
}