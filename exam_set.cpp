#include <iostream>
#include <fstream>

#include <set>
using namespace std;


int main(int argc,char *argv[]){
	set <string>s;
	ifstream in;
	ofstream out;
	in.open(argv[1]);
	out.open("word_list.txt");
	string word;

	// 	set::iterator k;
	//	k=s.find(key)!=s.end();
	//	s.erase(k);

	while( in >> word){
		s.insert(word);
	}
	set<string>::iterator j;
	for(j=s.begin();j!=s.end();j++){
		out<<(*j);
		out<<"\n";
	}
	cout<<s.count()<<endl;
	s.clear();
	in.close();
	out.close();
	return 0;
}

