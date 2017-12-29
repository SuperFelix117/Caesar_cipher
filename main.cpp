#include<stdio.h>
#include<stdlib.h>
#include<dos.h>

void delay(int sec){
	int i;
	for(i=1;i<=sec*300000000;i++);
}


int main(){
	
	
	//Product description
	printf("******************************\n");
	printf("Caesar Cipher Decoder\n");
	delay(1);
	printf("Version: 1.0.0\n");
	printf("By SuperFelix117\n");
	printf("******************************\n");

	

	return 0;            
	
}
