#include<iostream>
int main(){
	int value=0;
	int sum=0;
	while(std::cin>>value){
		sum+=value;
	}
	std::cout<<sum;
	return 0;
} 
