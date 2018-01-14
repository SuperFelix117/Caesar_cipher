#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void menu(), delay(float sec), fromtxt(), decryption();

void fromtxt(){
	char choice;
	system("cls");
	printf("Please paste the crypted text to 'input.txt' now.\n\n");
	delay(0.3);
	printf("Start decryption: Press enter\n");
	
	//back to menu if necessary
	printf("Go back to menu:  Press m\n");	 
	choice=getch();
	if(choice=='m'||choice=='M') menu();
	
	//start decryption
	decryption();
	
}

void decryption(){
	int alpha[200],i=0,max=65,shift;
	char text[99999],choice;
	FILE *crypted,*decrypted;
	crypted = fopen("input.txt","r");
	decrypted = fopen("output.txt","w+");
	
	//fetch crypted text
	while((text[i]=fgetc(crypted))!=EOF){	
		alpha[text[i]]++;
		i++;
	}
	
	//find out the position of 'E'
	for(i='A';i<='Z';i++){
		if(alpha[i]>max) max=i; //*****XXXif(alpha[i+1]>alpha[i]) max=i+1;
	}
	
	//find out the no. of shift-key
	shift=max-'E';
	printf("\nshift-key: %d",shift);
	delay(0.5);
	printf("\nDecrypting.");
	delay(0.5);
	printf(".");
	delay(0.5);
	printf(".\n");
	
	//decryption
	printf("\nDecrypted text:\n");
	i=0;
	while(text[i]!=NULL){
		if(text[i]>='A'&&text[i]<='Z') {
			text[i]-=shift;
			if(text[i]<'A') text[i]+=26; //if lower than A , add 26 character
			if(text[i]>'Z') text[i]-=26; //if higher than Z , minus 26 character
		}
		
		printf("%c",text[i]);
		i++; //*****remember to i++
	}
	
	//save
	printf("\n\nDo you want to save the crypted text?\n");
	printf("Press Y to save.\n");
	printf("Press N to go back to the menu.\n");
	while(1){
	choice=getch();
	i=0;
	if(choice=='y'||choice=='Y'){
		while(text[i]!=NULL){
			putc(text[i],decrypted);
			i++;
		}
		printf("Saved to output.txt sucessfully!");
		delay(3);
		fclose(crypted);
		fclose(decrypted);
		menu();
		break;
		
	}else if(choice=='n'||choice=='N'){
		fclose(crypted);
		fclose(decrypted);
		menu();
		break;
	}else{
		printf("wrong choice!");
		delay(1);
		//clear line
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b");
		printf("             ");
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b");
	}
	
	//rewind(crypted); //reset pointer of crypted.txt
	
	}
}

void delay(float sec){
	int i;
	for(i=1;i<=sec*300000000;i++);
}

void description(){
	//Product description
	printf("******************************	\n");
	printf("Caesar Cipher Decrypter		  	\n");
	printf("Version: 1.0.0				  	\n");
	printf("By SuperFelix117			  	\n");
	printf("******************************	\n");
}

void menu(){
	int choice;
	system("cls");
	printf("******************************\n");
	printf("¢c¢d¢f¢g¢h MENU ¢h¢g¢f¢d¢c\n");
	printf("1. decode crypted text from text file\n");
	printf("2. decode crypted text \n");
	printf("3. exit\n");
	printf("******************************\n");
	printf("Please enter your choice: ");
	choice=getch();
	
	switch(choice){
		case '1':
			fromtxt();
		break;
		
		case '3':
			printf("\n~~See you~~");
			exit(0);
		break;
		
		default:
			printf("wrong choice!");
			delay(1);
			menu();
		break;
	}
}

int main(){

	description();
	delay(1.5);
	menu();

	return 0;            
	
}
