#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>

void LinearSort(int* unsorted, int size);

void main(){
	int list[20]={1,4,7,4,5,4,7,6,9,4,5,8,9,0,1,2,8,6,2,1};
   LinearSort(list,20);
	getche();
}

void LinearSort(int* unsearched, int size){
	int sea;
   int count=0;
	printf("Search for which number?  ");
   scanf("%d",&sea);

	for(int pos=0;pos<size;pos++){
		if (sea == unsearched[pos]){
      	count=count+1;
      	printf("\n Match found in array possition %d.",pos);
		}
   }
   if(count == 0){
   	printf("\n No match found.");
	}
}




