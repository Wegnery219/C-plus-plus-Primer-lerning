#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<unsigned> h(11,0);
	unsigned grade;
	while(cin>>grade){
		auto tmp=grade/10;
		if(tmp<h.size()){
			++h[tmp];
		}
	}
	for(auto c:h){
		cout<<c<<' ';
	}
} 
