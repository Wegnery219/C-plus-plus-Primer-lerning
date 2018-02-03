#include<iostream>
#include<vector>
using namespace std;
int main(){
	int tmp;
	vector<int> h;
	vector<int> a{2};
	while(cin>>tmp){
		h.push_back(tmp);
	}
	for(auto c:h){
		cout<<c<<' ';
	}
	cout<<endl;
	for(auto it=h.begin();it<h.end();it=it+2){
		auto sum=*it+*(it+1);
		cout<<sum<<' ';
	}
}
