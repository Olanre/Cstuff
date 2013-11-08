#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>


#define SIZE 50//defines the size as 50

void push(int i);

int pop(void);

int  *top, *p1, stack[SIZE];
int menu();
void printstack();

int main(void)
{
  int value;
  int will;

  top = stack; /* tos points to the top of stack */
  p1 = stack; /* initialize p1 */
  will= menu();
  clrscr();
  while((will>0)&&(will<4)){
  if(will == 1){
  		printf("Option 1 selected\n");
  		printf("Enter value to put in stack: \t\a");
     scanf("%d", &value);
     fflush(stdin);
      push(value);
      printf("\n\t Value enetered in Stack\n");
      clrscr();
     will= menu();
  }
  if(will == 2){
  	printf("Option 2 selected\n");
  	printf("value on top of stack is %d\n", pop());
   clrscr();
   will= menu();
  }
  if(will == 3){
  	printf("Option 3 selected\n");
  	printstack();
   clrscr();
   will= menu();
  }

  if(will == 4){
  		printf("thanks for using");
  		sleep(5);
  }
  }


  return 0;

}
int menu(){
int option;
   printf("=========================================\n");
   printf("************** STACK MENU:***************\n");
   printf("\t1.Add element to stack\t\n");
   printf("\t2.Delete element from the stack\t\a\n");
   printf("\t3. Print values in stack\t\a\n");
   printf("\t4.Exit\n");
  	scanf("%d",&option);
	 fflush(stdin);
  return option;
}

void push(int i){//start of function push which would the integer in i into the stack
  p1++;//shifts the position of the pointer by 1
  if(p1 == (top+SIZE)) {//checks that the current position in the stack is not over the size of the stack
    printf("Overflow of stack.\n");//if this is so the stack is overflowed
    exit(1);//exits program
  }
  *p1 = i;//the new position becomes the integer pointed to by i
}

int pop(void){ //start of function pop which deletes any integer in the position pointer
  if(p1 == top){//checks that the current position is  not the top of the stack
    printf("\a\a\a Stack Empty....\n");//says that if this is so the stack would be empty
    exit(1);//exits program
  }
  p1--;//removes the current position by 1
  return *(p1+1);// returns the integer in the pointer of p1 in the stack added by 1.

}
void printstack(){//program should print values in stack, does not work properly.
int i;

  for(i = 0; i<SIZE; i++){
    printf("\n%d",i);
  }
}


