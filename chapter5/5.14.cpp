#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<string> h;
	int i=0;
	int j=0;
	int max=0;
	string c,tmp;
	while(cin>>c){
		if(!h.empty()){
			if(c==h[i-1]) {j+=1;}
			else{
				if(j>max) {max=j;tmp=h[i-1];}
				j=0;
			}
		}
		h.push_back(c);
		i++;
	}
	cout<<tmp<<" 出现了 "<<max+1<<" 次";
} 
