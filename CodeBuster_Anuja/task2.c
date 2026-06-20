// ip: welcome
// op: asc: ceelmow , desc: womleec
#include<stdio.h>
#include<string.h>

int main(){
	
	char str[10] = {'w', 'e', 'l', 'c', 'o', 'm', 'e'};
	char str1[10];
	int i,j;
	printf("asc: ");
	for(i=0; i<=6; i++){										
		for(j=i; j<7; j++){
			if(str[i]> str[j]){
				char temp;
				temp=str[i];
				str[i]= str[j];
				str[j] = temp;
			}	
		}
		printf("%c", str[i]);
	}
	printf("\tdesc: %s", strrev(str));
	
}
