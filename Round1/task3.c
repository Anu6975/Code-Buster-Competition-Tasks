// ip:	10 20 30 40 50
// op:	sum: 30 40 60 80 90
// 		Even Index: 30 60 90  
//		Odd Index: 40 80 

#include<stdio.h>
#include<string.h>

int main(){
	
	int arr[] = {10, 20, 30, 40, 50};
	int arr2[6];
	int i;
	
	printf("Sum: ");
	for(i=0; i<5; i++){
		int sum=0;
		if(i==0){
			sum=sum+arr[i]+arr[i+1];
			arr2[i]=sum;
		}
		else if(i==4)
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
	
	printf("\nEven Index: ");
	for(i=0; i<5; i++){
		if(i%2==0)
			printf("%d ", arr2[i]);	
	}
	
	printf("\nOdd Index: ");
	for(i=0; i<5; i++){
		if(i%2!=0)
			printf("%d ", arr2[i]);	
	}
	return 0;
}
