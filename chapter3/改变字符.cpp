#include<iostream>
#include<cctype>
using namespace std;
int main(){
	string str="Hello you";
	for(auto it:str){
		it='a';
	}
	cout<<str<<endl;
	for(auto it=str.begin();it!=str.end();++it){
		*it='a';
	}
	for(auto c:str){
		cout<<c;
	}
	return 0;
}
