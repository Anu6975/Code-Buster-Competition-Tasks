// ip: 10 20 30 40 50
// sum: 30 40 60 80 90
// even index: 30 60 90  odd: 40 80

#include<stdio.h>
#include<string.h>

int main(){
	
	int arr[] = {10, 20, 30, 40, 50};
	int arr2[6];
	int i;
	printf("Sum: ");
	for(i=0; i<5; i++){
			int sum=0;
			if(arr[i]==arr[0]){
				sum=sum+arr[i]+arr[i+1];
				arr2[i]=sum;
			}
			else if( arr[i]==arr[4])
			{
				sum=sum+arr[i]+arr[i-1];
				arr2[i]=sum;
			}
		else{
		sum=sum+arr[i-1] +arr[i+1]	;
		arr2[i]=sum;	
		}
        
		printf("%d ", arr2[i]);
	}
	
	printf("\nEven idex: ");
	for(i=0; i<5; i++){
		if(i%2==0){
			printf("%d ", arr2[i]);
		}
		
	}
	printf("\nOddidex: ");
	for(i=0; i<5; i++){
		if(i%2!=0){
			printf("%d ", arr2[i]);
		}
		
	}

	
	return 0;
}
