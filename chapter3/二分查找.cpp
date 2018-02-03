#include<iostream>
#include<vector>
using namespace std;
int main(){
	int sought;
	cout<<"输入一个1-8的数字";
	cin>>sought;
	
	vector<int> h={1,2,3,4,5,6,7,8};
	auto beg=h.begin();auto end=h.end();
	auto mid=beg+h.size()/2;
	while(mid!=end&&*mid!=sought){
		if(sought>*mid) beg=mid+1;
		else end=mid;
		mid=beg+(end-beg)/2;
	}
	cout<<*mid<<endl;
}
