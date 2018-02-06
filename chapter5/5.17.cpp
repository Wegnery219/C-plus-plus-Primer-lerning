#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> a={0,1,3,2};
	vector<int> b={0,1,1,2,3,5,8};
	int la=a.size();
	int lb=b.size();
	int len=la<lb?la:lb;
	for(int i=0;i<len;i++){
		if(a[i]!=b[i]){
			cout<<"no";
			return 0;
		}
	}
	//这是条错误的语句for{int i:{1,2,3,4}}{;}
	cout<<"yes";
	return 0;
} 
