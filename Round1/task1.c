// ip: GooD MorninG
// op: gOOd mORNINg

#include<stdio.h>
#include<string.h>

int main(){
char str1[] = "GooD MorninG";
int i, length=strlen(str1);
printf("Before: ");	
for( i=0; i<length; i++){
	printf("%c", str1[i]);	
}

printf("\nAfter: ");	
for( i=0; i<length; i++){
	if(str1[i] >= 65 && str1[i]<91){
		str1[i]= str1[i] + 32;
		printf("%c" , str1[i]);
	}
	else{
		str1[i]= str1[i] - 32;
		printf("%c", str1[i]);
	}	
}
return 0;
}
