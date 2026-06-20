// ip: GooD MorninG
// op: gOOd mORNINg

#include<stdio.h>
#include<string.h>

int main(){
char str1[20]= {'G','o','o','D',' ' ,'M', 'o', 'r', 'n', 'i', 'n', 'G'};
int i;
printf("Before: ");	
for( i=0; i<=11; i++){
	printf("%c", str1[i]);	
}


printf("\nAfter: ");	
for( i=0; i<=11; i++){
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
