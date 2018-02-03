#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> h={1,2,3,4,5,6,7,8};
	for(auto it=h.begin();it!=h.end();++it){
		*it=*it*2;
		cout<<*it;
	}
}
