#include<iostream>
int main(){
	int currentval=0;int cnt=0;
	int val=0;
	if(std::cin>>currentval){
		cnt+=1;
		while(std::cin>>val){
			if(val==currentval){
				cnt+=1;
			} 
			else{
				std::cout<<currentval<<"  occurs  "<<cnt<<"  times  "<<std::endl;
				currentval=val;
				cnt=1;
			}
		}
		std::cout<<currentval<<"  occurs  "<<cnt<<"  times  "<<std::endl;
	}
	return 0;
}
