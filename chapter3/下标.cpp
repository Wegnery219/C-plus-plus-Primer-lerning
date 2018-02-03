#include<iostream>
#include<cctype>
using namespace std;
int main(){
//	const string h="0123456789ABCDEF";
//	decltype(h.size()) ind=0;
//	string n;
//	while(cin>>ind){
//		if(ind<h.size()) n+=h[ind];
//	}
//	cout<<n<<endl;
	const string s="Keep Out!";
	for(auto &c:s){
		c=toupper(c);//´íÎó 
	} 
	cout<<s<<endl;
}
