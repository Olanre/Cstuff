# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# include <string.h>
# define QSIZE 5

typedef struct{
    int head,tail;
    char names[QSIZE][30];
}QUEUE;
void enqueue(char *);
char* dequeue();
void display();
int is_full();
int is_empty();
void init();
QUEUE *pq;


int main(){
    int choice;
    char str[30];
    QUEUE q;
    pq=&q;
    init();
    do{
     clrscr();
     printf("\n\n\t\tEnter your Choice:");
     printf("\n\t\t:1 For Add into the Queue.. ");
     printf("\n\t\t:2 For Delete from the Queue.. ");
     printf("\n\t\t:3 Display Elements of the Queue.. ");
     printf("\n\t\t:4 For Exit..\n\t\t\t :: ");
     scanf("%d",&choice);
     switch(choice){
       case 1: if(is_full())
		printf("\n\n\t\t Error: Queue Overflow..!!");
	       else{
		 printf("\n\n\t\t Enter a Name:");
		 fflush(stdin);
		 gets(str);
		 enqueue(str);
	       }
	       break;
       case 2: if(is_empty()){
		printf("\n\n\t\t Error: Queue UnderFlow..!!");
		init();
	       }
	       else
		printf("\n\n\t\t Deleted Queue Element is %s",dequeue());
	       break;
       case 3: if(is_empty())
		printf("\n\n\t\t Error: Queue is Empty..!!");
	       else
		display();
	       break;
       case 4: exit(0);
       default: printf("\n\n\t\t Plz press 1,2,3 or 4 key..");
     }
     while(!kbhit());
    }while(1);
    return 0;
}
void init(){
     pq->head = pq->tail = 0;
}
int is_full(){
    return pq->tail == QSIZE;
}
int is_empty(){
    if(pq->head == pq->tail){
     init();
     return 1;
    }
    else
     return 0;
}
void enqueue(char *p){
     strcpy(pq->names[(pq->tail)++],p);
     printf("\n\n\t\t Element Successfully Inserted");
}
char* dequeue(){
     return pq->names[(pq->head)++];
}
void display(){
     int i;
     for(i=pq->head;i<pq->tail;i++)
       printf("\n\t\t :%s",pq->names[i]);
}