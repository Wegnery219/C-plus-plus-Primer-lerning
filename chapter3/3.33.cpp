#include<iostream>
#include<vector>
using namespace std;
int main(){
	unsigned scores[11];
	unsigned grade;
	while(cin>>grade){
		if(grade<=100){
			++scores[grade/10];
		}
	}
	for(auto c:scores){
		cout<<c<<' ';
	}
	cout<<endl;
	string s="wss";
	cout<<s.size();
}
