// ip: welcome
// I/P:- welcome
// O/P:- Asc: ceelmow  Desc: womleec

#include<stdio.h>
#include<string.h>

int main(){
	
//	char str[10] = {'w', 'e', 'l', 'c', 'o', 'm', 'e'};
	char str[] = "welcome";
	int i,j;
	int length=strlen(str);
	char str1[length];
	printf("Asc: ");
	for(i=0; i<length; i++){										
		for(j=i; j<length; j++){
			if(str[i]> str[j]){
				char temp;
				temp=str[i];
				str[i]= str[j];
				str[j] = temp;
			}	
		}
		printf("%c", str[i]);
	}
	printf("\tDesc: %s", strrev(str));
}
