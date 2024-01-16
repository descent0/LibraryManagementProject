#include<stdio.h>
#include<stdlib.h>


char USERNAME[50];
int found = 0;
   
   
#include<string.h>
#include<time.h>
#include"file-linkedlistConversions.h"
#include"user.h"
#include"admin.h"


void header(){
	printf("\n\n\n\n\t\t\t\t");
	printf("*************************LIBRARY MANAGEMENT SYSTEM*************************");
	printf("\n\n\n\n");
}
void main(){
	while(1){
	int choice;
	char username[50];
	char passkey[50];
	header();
	printf("\t\t\t\tEnter your choice\n\n");
	printf("1.Admin Login\n\n");
	printf("2.User Login\n\n");
	scanf("%d",&choice);
	if(choice==1){
		printf("enter you passkey\n\n\n\n");
		scanf("%s",&passkey);
		if (strcmp(passkey, "HelloAdmin") ==0){
		
		adminMenu();
	}else{
		printf("\t\t\t\t\t\t\tAccess Denied!!!!......Wrong passkey!!\n");
	}
	}else if(choice==2){
		userlogin();		
		
	}else{
		printf("/n/n//t/t/t/tWrong Key Pressed!!!!!");
	}
}
	
}
