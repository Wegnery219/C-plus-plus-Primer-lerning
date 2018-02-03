#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<unsigned> scores(11,0);
	auto it=scores.begin();
	int grade=0;
	while(cin>>grade){
		if(grade<0){
			cout<<"´íÎóµÄÊäÈë"<<endl;
			return 0; 
		}
		int tmp=grade/10;
		*(it+tmp)+=1;
	}
	for(auto c:scores){
		cout<<c<<' ';
	}
}
