#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> h={1,2,3};
	for(auto &c:h){
		c*=c;
	}
	for(auto c:h){
		cout<<c;
	}
} 
