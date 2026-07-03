// ip: c is a programming language
// op: c is a 	 											--words whose length is less than 4

#include<stdio.h>
#include<string.h>

int main(){
	char str[] = "c is a programming language";
	int i=0, j=0;                                         
	int len = strlen(str);
	char str2[20];
	
	for(i=0; i<=len; i++){
        if (str[i] == ' ' || str[i] == '\0') {
            str2[j] = '\0';
            if (strlen(str2) < 4 && strlen(str2) > 0)
                printf("%s ", str2);
            j = 0;
        } 
		else {
            str2[j] = str[i];
            j++;
        }
	}
	return 0;
}
