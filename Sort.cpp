#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>

int* SelectionSort(int* unsorted, int size);
void printArray(int* array, int size);

void main(){
	int list[10]={1,4,7,4,5,4,3,6,9,10};
	int* list2;
	list2 = SelectionSort(list,10);
	printArray(list2,10);
   getche();
}

int* SelectionSort(int* unsorted, int size){
	//int* sorted = (int*)malloc(sizeof(int)* size);
   int smallest;
   int smallestIndex;
   int tmp;


	for(int pos=0;pos<size;pos++){
   	smallest = unsorted[pos];
      smallestIndex = -1;

		for(int i = pos; i < size; i++){
   		if(unsorted[i] < smallest){
      		smallest = unsorted[i];
            smallestIndex = i;
         }
      }


      if (smallestIndex >= 0){
      	//swap smallest element in array and front
      	tmp = unsorted[pos];
      	unsorted[pos] = smallest;
      	unsorted[smallestIndex] = tmp;
      }

      //printArray(unsorted, 10);
      //printf("\n\n\n");
      //getche();

	}
   return unsorted;
}

void printArray(int* array, int size){
	for(int i=0; i<size; i++){
   	printf("\n %d", array[i]);
   }


}

