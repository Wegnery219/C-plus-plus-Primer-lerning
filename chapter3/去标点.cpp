#include<iostream>
#include<cctype>
using namespace std;

int main(){
	string h;
	cin>>h;
	for(auto &c:h){
		if(ispunct(c)){
			c=' ';
		}
	}
	cout<<h<<endl;
}
