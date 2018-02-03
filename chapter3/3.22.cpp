#include<iostream>
#include<vector>
#include<cctype>
using namespace std;
int main(){
	string h="son hello";
	for(auto it=h.begin();it!=h.end();++it){
		if(!isspace(*it)){
			*it=toupper(*it);
		}
	}
	for(auto c:h){
		cout<<c;
	}
}
