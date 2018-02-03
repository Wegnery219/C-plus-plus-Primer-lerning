#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> h(10,1);
	cout<<"ÈÝÁ¿"<<h.size()<<endl;
	for(auto it=h.cbegin();it!=h.cend();++it){
		cout<<*it<<" ";
	}
} 
