/*IA program for Delaware Software House Inc*/
/*Registration number: 100404   */
/*Center number: 1004041346*/
/*Subject: Computer Science*/
/*Year: 2010*/
/*Name: Olanrewaju Okunlola*/


#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#include<string.h>

struct update{
	char name1[30];
   int day, month, year;
   char change[100];
   float cost1, idnum1;
   };

update updatedarray[100];//array to intake entries relating to updated programs
/*array to copy contents of updated file into another copy file and back into
updated file*/
update allow[10];

struct deploye{
	char name2[30];
   int day1, month1, year1;
   char descrip[100];
   float cost2, idnum2;
   };
deploye deployedarray[100];//array to intake entries relating to deployed programs
/*array used to copy contents from deployed file into a another copy file
 and back into deployed file*/
deploye copy[10];

//declare function deployed which takes no parameters
void deployed();
//declare function updated which takes no parameters
void updated();
//declare function countitme which takes no parameters
void counttime();
//declare function deleteentry which takes no parameters
void deleteentry();
//declare function getdata which takes in no parameter
void getdata();
//declare function computecost which takes no parameters
void computecost();
//declare a function called menu which takes no parameter and returns a integer
int menu();
//declare function print which takes no parameters
void print();


//main function called void main which accepts no parameters is created here
void main(){
          int option;
			//calls the menu function and places the value of choice in option
   		option=menu();
         int ans;/*creates an integer called ans which allows to user to
         allocate their answer to the question of if they want to enter an entry
         about deployed or updated programs*/
   	/*performing a while loop which checks if the chioce entered is less than
    	6 and more than 0 then implements a certain action*/
   	while(option>0&&option<8){

      /*checks if the chioce entered is 1 then prints a statement that
      delcares option 1 is selected*/
   	if(option==1){
         clrscr();
   		printf("Option 1 selected\n");
   		printf("Does the entry relate to a deployed program or updated one? ");
         printf("\n\t 1 for updated 2 for deployed(1/2)\n");
         scanf("%d",&ans);//enters answer in memory
         fflush(stdin);
         /*checks if the answer was 1, if so it implememts a process, if not
         it terminates*/
         if(ans==1){
         		updated();/*calls back function updated which takes
               no parameters*/
         }
         if(ans==2){/*checks if the answer was 2, if so it implememts a
         process, if not it terminates*/
         		deployed();/*calls back a function called
               deployed which takes no parameters*/
         }
         /*if statement to check that if the answer is not 1 or two an
         incorrect assignment has been made*/
         if((ans != 1)&&(ans != 2)){
         	printf("\nIncorrect assignment, question asked for 1 for updated");
            printf("company programs ");
            printf("option and 2 for deployed company programs\n");
         }

         option=menu();/*calls back function menu which accepts no parameters
         into the void main function in which is serves the purpose of allowing
          the user to enter another option*/

		}//if statement ends

      /*checks if the choice entered is 2 then prints a statement declaring that
       option 2 is selected*/
   	if(option==2){
      	clrscr();
   		printf("Option 2 selected\n");
          counttime();/*calls back function counttime accepts no
          parameters*/

         option=menu();
         /*calls back function menu which accepts no parameters into the void
         main function in which is serves the purpose of allowing the user to
         enter another option*/
   	}//if statement ends

      /*a function to check if the choice entered is 3 and  prints a statements
       declaring option 3 is selected*/
   	if(option==3){
      	clrscr();
      	printf("Option 3 selected\n");
         //calls back function sort which takes in no parameters
         deleteentry();
         option=menu();/*calls back function menu which accepts no parameters
         into the void main function in which is serves the purpose of allowing
         the user to enter another option*/
   	}//if statement ends

      /*checks if the choice entered is 4 and prints a statement delcaring that
		option 4 is selected*/
   	if(option==4){
          clrscr();
   		printf("Option 4 selected\n");
         getdata();//calls back function getdata
         option=menu();/*calls back function menu which accepts no parameters
         into the void main function in which is serves the purpose of allowing
         the user to enter another option*/
   	}//if statement ends

      /*checks if the choice entered is 5 and prints a statement delcaring that
      option 5 is selected*/
   	if(option==5){
      	clrscr();
   		printf("Option 5 selected\n");
         computecost();/*calls back function computecost
         which takes in no parameters*/

         option=menu();/*calls back function menu which accepts no parameters
         into the void main function in which is serves the purpose of allowing
         the user to enter another option*/
   	}//if statement ends
      /*a function to check if the choice entered is 3 and  prints a statements
       declaring option 3 is selected*/
   	if(option==6){
      	clrscr();
      	printf("Option 6 selected\n");
         //calls back function print which takes in no parameters
        print();
         option=menu();/*calls back function menu which accepts no parameters
         into the void main function in which is serves the purpose of allowing
         the user to enter another option*/
   	}//if statement ends


    	 /*checks if the choice entered is 5 and prints a statement declaring that
        option 5 is selected*/
   	if(option==7){
      	clrscr();
      	printf("Thanks for using\n");
          sleep(2);
         /*calls back function named menu, however option 7 does not exsist in
          menu so it terminates*/
         option=8;
   	}//if statement ends
   }//while statement ends
}//end of void main

int menu(){

/*creating a integer to named chioce to allow the user to choose one of the
items in the menu, from 1 to 5*/
int decision;

	printf("\n\t Delaware Software House Inc archive program");
   printf("\n\t==============================================================");
   printf("\n           1. Enter data: deployed program or updated        ");
   printf("\n           2. Count times a program has been updated");
   printf("\n           3. Delete a program in the file   ");
   printf("\n           4. Search for/get data for program, delete data");
   printf("\n           5. Compute total cost for updated/deployed programs");
   printf("\n           6. Print report   ");
   printf("\n           7. Exit   ");
   printf("\n\n        Enter Option             \t");
	//scans and inputs in computer one of the options above if it a numerical one
	scanf("%d",&decision);
//to enable choice to be returned whereever you call you call it
return decision;
}//end of menu function


void updated(){/*start of function updated which takesin no parameters and
allows the user to enter and store data about a program/(s) being updated in
 a file*/

	int x;//declare an integer called x
   FILE *updatedFile;//declare a file pointer called jp
   int answer;


   printf("How many entries do you want to input, note the maximum is 100\t");
   scanf("%d",&x);
   if ((x<100)&&(x>0)){/*if statement checking that the entry entered isnt
   above 100 and below 0, if it is it tells the user that it is an incorrect
    entry*/
   	updatedFile = fopen("updated.txt","a");/*operation to open the file
      taxfilenew.txt in memory using file pointer*/
   	for(int s=0; s<x; s++){/*implememts and allows the user to enter and
      store in file whenver integer s is below the amount of items they wanted
      to enter */
			printf("\nPlease enter the name of the program you are updating\t");
      	scanf("%s",&updatedarray[s].name1[0]);
         fflush(stdin);
         int r = strlen(updatedarray[s].name1);/*checks if there is actually
         something inside the stirng entered, if not it asks the user to enter
         the stirng again.*/
      	while(r == 0){/*start of while loop qhich implements if the lenth of
         the stirng is 0*/
         	printf("\nImpossible assignment, must be a string\a\n");
     	   	printf("\nPlease enter the name of the program you are updating\t");
      		scanf("%s",&updatedarray[s].name1[0]);
      		fflush(stdin);
         }//end of while loop

         printf("\nPlease enter the changes made of the program you are");
         printf(" updating\t");
      	scanf("%s",&updatedarray[s].change[0]);
         fflush(stdin);
         int t=strlen(updatedarray[s].change);/*checks if there is actually
         something inside the stirng entered, if not it asks the user to enter
         the stirng again.*/
      	while(t == 0){/*start of while loop qhich implements if the lenth of
         the stirng is 0*/
         	printf("\nImpossible assignment, must be a string\a\n");
     	   	printf("\nPlease enter the name of the program you are updating\t");
      		scanf("%s",&updatedarray[s].change[0]);
      		fflush(stdin);
         }//end of while loop
         printf("\n Please enter the amount it cost to update the program\t");
         scanf("%fl",&updatedarray[s].cost1);
         fflush(stdin);
         while(updatedarray[s].cost1<0){ /*start of while loop to check if the
         amount entered is above 0, if so it terminates if not it asks the user
          to enter the entry again*/
         	printf("Impossible assignment. Must be greater than 0");
            printf("\n Please enter the amount it cost to implement changes in");
            printf(" program you are storing\t");
      		scanf("%fl",&updatedarray[s].cost1);
      		fflush(stdin);
         }//end of while loop

         printf("\n Please enter the idnumber assigned to this update\t");
         scanf("%fl",&updatedarray[s].idnum1);
         fflush(stdin);

         while(updatedarray[s].idnum1<0){ /*start of while loop to check if the
         amount entered is above 0, if so it terminates if not it asks the user
          to enter the entry again*/
         	printf("Impossible assignment. Must be greater than 0");
            printf("\nPlease enter the amount it cost to implement changes in");
            printf(" program you are storing\t");
      		scanf("%fl",&updatedarray[s].idnum1);
      		fflush(stdin);
         }//end of while loop

      	printf("Please enter the day \t");
      	scanf("%d",&updatedarray[s].day);
      	fflush(stdin);

      	while(updatedarray[s].day>31){/*checks that day isnt above 31, won't
          terminate until correction is made*/
           printf("\a\a\n Wrong entry entered, no month has so many days!\n");
           printf("Please enter the correct day \t");
           scanf("%d",&updatedarray[s].day);
           fflush(stdin);
      	}//end of while

      	printf("Please enter the month\t");
      	scanf("%d", &updatedarray[s].month);

      	while(updatedarray[s].month>12){/*checks that month enterd isnt
         over 12, wont  terminate until correction is made*/
      		printf("\a\nError, wrong entry entered no year has so many months");
         	printf("Please  enter the month\t");
      		scanf("%d", &updatedarray[s].month);
      		fflush(stdin);
      	}//end of while loop

      	while((updatedarray[s].month == 2)&&(updatedarray[s].day> 28)){/*
         ensures that a day above 29 isnt entered in febraury unless it is a
         leap year, wont terminate until it is corrected*/
           printf("\nERROR Please enter a new day, february has 28 days\a\n");
           printf("IS this a leap year?, 1 for yes 2 for no\t");
           scanf("%d",&answer);
           fflush(stdin);
            	if(answer!= 1){/*if statement to check if the answer to the
               above is 1 or yes and prints something to screen*/
      				while(updatedarray[s].day>28){/*while loop which implements
                  once, while not in a leap year, the entry for febraury is 28*/
               		printf("Please enter the correct day");
                  	scanf("%d",&updatedarray[s].day);
                  	fflush(stdin);
                  }//end of while loop
               }//end of if statment

        }//end of while

        while(updatedarray[s].day>30){/*checks that day isnt above 30 in months
        which only 30 days, wont terminate until date entered is acceptable*/
				if((((updatedarray[s].month == 9)&&(updatedarray[s].month == 4)&&
            (updatedarray[s].month == 6)&&(updatedarray[s].month == 11)))){/*
            if statement to check if the days entered werent over 30 for a
            month with 30 days only*/
      			printf("\a\nwrong entry entered, that month has 30 days\n");
         		printf("Please enter the day \t");
      			scanf("%d",&updatedarray[s].day);
      			fflush(stdin);
            }//end of if statement
        } //end of while loop

        printf("Please enter the year\t");
        scanf("%d", &updatedarray[s].year);
        fflush(stdin);

        while(updatedarray[s].year<0){/*checks that year is not below 0, if so
         it doesnt terminate*/
      		printf("\a\nError, wrong entry entered. no year is negative\n");
         	printf("Please enter the year\t");
      		scanf("%d", &updatedarray[s].year);
      		fflush(stdin);/*ensure that space and enter are not regonized
            as variables*/
      	}//end of while loop

			/*operation to print several things into a file using a file pointer*/
			fprintf(updatedFile,"%s %s %fl %fl %d %d %d\n", updatedarray[s].name1,
         updatedarray[s].change, updatedarray[s].cost1,
         updatedarray[s].idnum1, updatedarray[s].day, updatedarray[s].month,
         updatedarray[s].year);
         clrscr();

  	   }//end of for loop
      fclose(updatedFile);//operations to close file using file pointer jp

  		 printf("\n you have entered and stored data in file");
   	clrscr();
   }else{/*if the number of entries was too big or too small the program
    goes to the else portion of that if statement*/

    printf("\n\a\n Wrong Entry!!!!!\nArray been used to store data wont hold");
    printf("so many entries and wont store less than 0, you will be returned");
      printf(" to menu\n");

   }//end of if statement


}//end of function updated
void deployed(){/*start of function deployed which takes in no parameters and
allows the user to enter and store entries about a program/(s) deployed in a
the system*/
	int xo;//declare integer called xo
   FILE *deployedFile;//declares a file pointer called deployedFile
   int answer;//declares an integer called answer



     printf("How many entries do you want to input,note the maximum is 100:\t");
   	scanf("%d",&xo);
      if((xo<100)&&(xo>0)){
      	deployedFile = fopen("deployed.txt","a");
   		for(int s=0; s<xo; s++){/*implememts and allows the user to enter and
          store in file whenver integer s is below the amount of items they
          wanted to enter*/
				printf("Please enter the name of the program you are deploying:\t");
            printf(" for\t");
      		scanf("%s",&deployedarray[s].name2[0]);
            printf("\n %s \n", deployedarray[s].name2);
            fflush(stdin);
            int t=strlen(deployedarray[s].name2);

      		while(t == 0){ /*a while loop that implements when the string
            length of the name2 is 0 and allows the user to enter a new
            varaible*/
            	printf("\nIncorrect assignment. must be a string\n");
            printf("Please enter the name of the program you are deploying");
            printf(" for\t");
      			scanf("%s",&deployedarray[s].name2[0]);
            	fflush(stdin);
            }//end of while loop

         printf("\nPlease enter a decription of the program you are");
         printf("deploying:\t");
      	scanf("%s",&deployedarray[s].descrip[0]);
         printf(" \n %s \n", deployedarray[s].descrip);
         fflush(stdin);//ensures space isnt accepted as a variable*/
         int r=strlen(deployedarray[s].descrip);/*checks if there is actually
         something inside the stirng entered, if not it asks the user to enter
         the stirng again.*/

      	while(r == 0){/*start of while loop qhich implements if the lenth of
         the stirng is 0*/
         	printf("\nImpossible assignment, must be a string\a\n");
     	   	printf("\n Please enter a decription of the program");
            printf(" you are deploying:\t");
      		scanf("%s",&deployedarray[s].descrip[0]);
      		fflush(stdin);
         }//end of while loop

      		printf("\nPlease enter the cost of making and deploying");
            printf(" the program:\t");
      		scanf("%fl",&deployedarray[s].cost2);
         	fflush(stdin);

            while(deployedarray[s].cost2<0){/*implements when the amount is
             not smaller than 0*/
               printf("INCORRECT ASSIGNMENT entry must be greater than zero/a");
               printf("\nPlease enter the cost of making and");
               printf(" deploying the program:\t");
      			scanf("%fl",&deployedarray[s].cost2);
         		fflush(stdin);
            }//end of while loop

      		printf("Please  enter the id number of this entry:\t");
      		scanf("%fl",&deployedarray[s].idnum2);
         	fflush(stdin);

            while(deployedarray[s].idnum2<0){/*implements if item put in for
            idnum2 is less than zero and tells the User that such an entry is an
             error and allows them to correct this*/
            	printf("INCORRECT entry, must be greater than 0/a");
               printf("Please enter the id number of this entry:\t");
      			scanf("%fl",&deployedarray[s].cost2);
               fflush(stdin);
            }//end of while loop

         printf("Please enter the day: \t");
      	scanf("%d",&deployedarray[s].day1);
      	fflush(stdin);

      	while(deployedarray[s].day1>31){/*checks that day isnt above 31, wont
          terminate until correction is made*/
           printf("\a\a\n Wrong entry entered, no month has so many days!\n");
           printf("Please enter the correct day: \t");
           scanf("%d",&deployedarray[s].day1);
           fflush(stdin);
      	}//end of while

      	printf("Please enter the month:\t");
      	scanf("%d", &deployedarray[s].month1);
      	fflush(stdin);

      	while(deployedarray[s].month1>12){/*checks that month enterd isnt over
          12, wont terminate until correction is made*/
      		printf("\nError, wrong entry entered no year has so many months\t");
         	printf("Please  enter the month:\t");
      		scanf("%d", &deployedarray[s].month1);
      		fflush(stdin);
      	}//end of while loop

      	while((deployedarray[s].month1 == 2)&&(deployedarray[s].day1>28)){/*
         ensures that a day above 29 isnt entered in febraury unless it is a
         leap year, wont terminate until it is corrected*/
           printf("\nERROR Please enter a new day, february has 28 days:\a\n");
           printf("IS this a leap year?, 1 for yes 2 for no:\t");
           scanf("%d",&answer);
           fflush(stdin);
            	if(answer!= 1){/*if statement to check if the answer to the
               above is 1 or yes and prints something to screen*/
      				while(deployedarray[s].day1>28){/*while loop which implements
                   once while not in a leap year, the entry for febraury is 28*/
               		printf("Please enter the correct day:");
                  	scanf("%d",&deployedarray[s].day1);
                  	fflush(stdin);
                  }//end of while loop
               }//end of if statment
        }//end of while

        while(deployedarray[s].day1>30){/*checks that day isn't above 30 in
        months with only 30 days, wont terminate until date entered is
        acceptable*/
				if((((deployedarray[s].month1 == 9)&&(deployedarray[s].month1 == 4)
        		&&(deployedarray[s].month1 == 6)&&
            (deployedarray[s].month1 == 11)))){/*
            if statement to check if the days entered werent over 30 for a
            month with 30 days only*/
      			printf("\a\nwrong entry entered, that month has 30 days\n");
         		printf("Please enter the day \t");
      			scanf("%d",&deployedarray[s].day1);
      			fflush(stdin);
            }//end of if statement
        } //end of while loop

        printf("Please enter the year\t");
        scanf("%d", &deployedarray[s].year1);
        fflush(stdin);

        while(deployedarray[s].year1<0){/*checks that year is not below 0, if
        so it doesnt terminate*/
      		printf("\a\nError, wrong entry entered. no year is negative\n");
         	printf("Please enter the year\t");
      		scanf("%d", &deployedarray[s].year1);
      		fflush(stdin);
      	}//end of while loop

         fprintf(deployedFile,"%s %s %fl %fl %d %d %d\n", deployedarray[s].name2,
         deployedarray[s].descrip, deployedarray[s].cost2,
         deployedarray[s].idnum2, deployedarray[s].day1,
         deployedarray[s].month1, deployedarray[s].year1);
         clrscr();

      }//end of forloop
      	fclose(deployedFile);//operartion to close file using file pointer


      	printf("\n You have stored content in a file");
      	clrscr();

      }else{
      	printf("\n\a\nWrong entry!!!!\n Array cannot hold more than 100");
         printf(" entries or less than 0, you will be returned to main menu\n");

      }//end of if statement


}//end of void deployed
void counttime(){/*start of function counttime which allows the user
to count amount of times a program has been updated*/
char name1[30], change[100];
int day, month, year;
float count=0;
float cost1, idnum1;
char name[30];
FILE *updatedFile;/*declarations of file pointer called updatedFile which will
be used to open updated.txt to read*/
FILE *countFile;/*declarations of file pointer called countFile which will be
 used to open count.txr to write*/

       printf("Please enter the name of the program you want to check\t");
       scanf("%s",&name[0]);
       if(updatedFile = fopen("updated.txt","r")){//*operation to open the file
         /*a while loop that terminates if the iteration has reached the
         end of the file which in memory using the file pointer updatedFile*/

   		while(!feof(updatedFile)){
            		fscanf(updatedFile,"%s %s %fl %fl %d %d %d\n", &name1[0],
                  &change[0], &cost1, &idnum1, &day, &month, &year);
                  /*sets r to string compare which checks if name has the same
                  as name1. If the same it counts it once*/
                  int r=strcmp(name, name1);
                  if(r==0){
      					count = (count + 1);
      				}else{
      					printf("\nNot same");
                  }//end of if statement
      	}//end of while loop

      	fclose(updatedFile);//operation to close file using file pointer
         countFile = fopen("count.txt","a");
			fprintf(countFile, "%fl\n", count);
         fclose(countFile);

       }else{/*if file cant be read from it prints that it was nt found or
          was unreadable*/

          printf("\a\a\a FILE NOT FOUND or...Unreadble file\n");
		 }//end of if statement
}//end of void counttime

void computecost(){
char name1[30], change[100];
int day, month, year, dy, mth, yr, time, answer;
double costo = 0;
double cost = 0;
double totalcost;
float cost1, idnum1, cost2, idnum2;
char name2[30], descrip[100];
int day1, month1, year1;
FILE *updatedFile;/*declarations of file pointer called updatedFile*/
FILE *deployedFile;/*declarations of file pointer called deployedFile*/
FILE *DeployedCostFile;/*declarations of file pointer called DeployedCostFile*/
FILE *totalcostfile;/*declarations of file pointer called totalcostfile*/
FILE *UpdatedCostFile;/*declarations of file pointer called UpdatedCostFile*/

         clrscr();/* a function to clear the things printed on screen, meant
         to make the program looks presentable.*/

			if(updatedFile = fopen("updated.txt","r")){/* checks if updated.txt
         exsists and can open*/
				while(!feof(updatedFile)){/*scanf all entries from updated.txt into
            several varialbes */
            		fscanf(updatedFile,"%s %s %fl %fl %d %d %d\n", &name1[0],
                  &change[0], &cost1, &idnum1, &day, &month, &year);
                   //counts the 'cost1' in the file
                   cost = (cost1 + cost);
            }//end of while statement
            fclose(updatedFile);
            UpdatedCostFile = fopen("cost.txt","w");
         	fprintf(UpdatedCostFile,"%ld\n",cost);
         	fclose(UpdatedCostFile);/*assignment to close file cost.txt
         	using file pointer jp*/

         }else{/*if file cant be read from it prints that it was nt found or
          	was unreadable*/
          	printf("\a\a\a FILE NOT FOUND or...Unreadble file\n");

       	}//end of if statement

         if(deployedFile = fopen("deployed.txt","r")){/* checks if deployed.txt
          exsists and can open*/

				while(!feof(deployedFile)){/*scanf all entries from updated.txt into
             several varialbes*/
            		fscanf(deployedFile,"%s %s %fl %fl %d %d %d\n", &name2[0],
                  &descrip[0], &cost2, &idnum2, &day1, &month1, &year1);
                   //counts the 'cost1' in the file
                   costo = (cost2 + costo);
            }//end of while statement

            fclose(deployedFile);
            DeployedCostFile = fopen("costo.txt","w");
         	fprintf(DeployedCostFile,"%ld\n",costo);
         	fclose(DeployedCostFile);
         }else{/*if file cant be read from it prints that it was nt found or
          was unreadable*/
          printf("\a\a\a FILE NOT FOUND or...Unreadble file\n");
       	}//end of if statement

         printf("Please enter the day: \t");
      	scanf("%d",&dy);
      	fflush(stdin);

      	while(dy>31){/*checks that day isnt above 31, wont terminate until
         correction is made*/
           printf("\a\a\n Wrong entry entered, no month has so many days!\n");
           printf("Please enter the correct day: \t");
           scanf("%d",&dy);
           fflush(stdin);
      	}//end of while
      	printf("Please enter the month:\t");
      	scanf("%d", &mth);
      	fflush(stdin);

      	while(mth>12){/*checks that month enterd isnt over 12, wont
         terminate until correction is made*/
         	/*print to screen that the months are too many and the tax statment
             are due before the last day of november*/
      		printf("\nError,wrong entry entered no year has so many months:\t");
         	printf("Please  enter the month:\t");
      		scanf("%d", &mth);
      		fflush(stdin);
      	}//end of while loop

      	while((mth == 2)&&(dy>28)){/*ensures that a day above 29 isnt
         entered in febraury unless it is a leap year, wont terminate until
         it is corrected*/
           printf("\nERROR Please enter a new day, february has 28 days:\a\n");
           printf("IS this a leap year?, 1 for yes 2 for no:\t");
           scanf("%d",&answer);
           fflush(stdin);
            	if(answer!= 1){/*if statement to check if the answer to the
               above is 1 or yes and prints something to screen*/
      				while(dy>28){/*while loop which implements once, while not
                  in a leap year, the entry for febraury is 28*/
               		printf("Please enter the correct day:\t");
                  	scanf("%d",&dy);
                  	fflush(stdin);
                  }//end of while loop
               }//end of if statment

        }//end of while

        while(dy>30){/*checks that day isnt above 30 in months which only
        30 days, wont terminate until date entered is acceptable*/
				if((((mth == 9)&&(mth == 4)&&(mth == 6)&&(mth == 11)))){/*
            if statement to check if the days entered werent over 30 for a
            month with 30 days only*/
      			printf("\a\nwrong entry entered, that month has 30 days\n");
         		printf("Please enter the day: \t");
      			scanf("%d",&dy);
      			fflush(stdin);
            }//end of if statement
        } //end of while loop

        printf("Please enter the year:\t");
        scanf("%d", &yr);
        fflush(stdin);

        while(yr<0){/*checks that year is not below 0, if so it doesnt
        terminate*/
      		printf("\a\nError, wrong entry entered. no year is negative\n");
         	printf("Please enter the year:\t");
      		scanf("%d", &yr);
      		fflush(stdin);
      	}//end of while loop

         totalcost = (costo + cost1);
         printf(" Please enter the time:\t");
         scanf("%d", &time);

         while(time<0){
         	printf("\nError, that time is negative\a");
            printf("Please enter another time value between 0 and 23:59");
            scanf("%d", &time);
         }

         totalcostfile = fopen("totalcost.txt","a");
         //prints cost to file totalcost.txt
         fprintf(totalcostfile,"%d %d %d %d %ld\n", time, dy, mth, yr, totalcost);
         fclose(totalcostfile);/*assignment to close file totalcost.txt*/
}//end of void computecost

void getdata(){/*start of function getdata which allowed user to search for
programs and changes made to them*/
char sorta[30];
int count = 0;
float cost1, idnum1, cost2, idnum2;
char name2[30], descrip[100];
int day1, month1, year1;
char name1[30], change[100];
int day, month, year;
FILE *deployedFile;
FILE *updatedFile;


       printf("Enter the name of the program you want to check exists? \t");
       scanf("%s",&sorta[0]);
       if(deployedFile = fopen("deployed.txt","r")){/* checks if deployed.txt
       exsists and can open*/

				while(!feof(deployedFile)){/*scanf all entries from updated.txt
            into several varialbes*/
            		fscanf(deployedFile,"%s %s %fl %fl %d %d %d\n", &name2[0],
                  &descrip[0], &cost2, &idnum2, &day1, &month1, &year1);
                   //counts the 'cost1' in the file
                   int r=strcmp(sorta, name2);
                  if(r==0){
                  	printf(" \nProgram found in file: program name %s", name2);
                     printf("\n\nOther entries relating to program: \n\t *** ");
                     printf("%s %fl %fl %d %d %d ***\n", descrip, cost2, idnum2,
                      day1, month1, year1);
                  }else{
                  	printf("\n\t\t Not the same\n");
                  }
            }//end of while statement

            printf("\n---------------------File for deployed programs");
            printf(" searched----------------\n");
            fclose(deployedFile);
         }else{/*if file cant be read from it prints that it was nt found or
          was unreadable*/
          	printf("\n\a\a\a FILE NOT FOUND or...Unreadble file\n");
       	}//end of if statement
         printf("\nChecking if program has been updated since deployed\n");

         if(updatedFile = fopen("updated.txt","r")){/* checks if updated.txt
          exsists and can open*/

				while(!feof(updatedFile)){/*scanf all entries from updated.txt
            into several varialbes*/
            		fscanf(updatedFile,"%s %s %fl %fl %d %d %d\n", &name1[0],
                  &change[0], &cost1, &idnum1, &day, &month, &year);
                   //counts the 'cost1' in the file
                   int r=strcmp(sorta, name1);
                   if(r==0){
                   		count =  (count + 1);
                        printf("\n\t\t**** Changes made were:%s \a\a\a\n",
                        change);
                        printf("\t\t****Changes cost: %fl and were made:%d %d");
                        printf(" %d\n", cost1, day, month, year);
                   }
         	}//end of while statement

            fclose(updatedFile);
            printf("\n\t Program was updated %d times", count);

         }else{/*if file cant be read from it prints that it was nt found or
          was unreadable*/
          printf("\a\a\a\n\t\t ***FILE NOT FOUND or...Unreadble file***\n");
       	}//end of if statement

}
void deleteentry(){/*start of function deleteentry whic allows user to delete
program entries in file*/
char call[30];
int ans;
float cost1, idnum1, cost2, idnum2;
char name2[30], descrip[100];
int day1, month1, year1;
char name1[30], change[100];
int day, month, year;
FILE *updatedFile;
FILE *UpdatedCopyFile;
FILE *deployedFile;
FILE *DeployedCopyFile;

			printf("\n\n DO you want to delete an entry? 1 for yes 2 for no:\t");
         scanf("%d",&ans);
         fflush(stdin);
         if(ans == 1){

         		printf("\nEnter name of program entry you want deleted:\t");
               scanf("%s", &call[0]);
               if(deployedFile = fopen("deployed.txt","r")){/* checks if
               deployed.txt exsists and can open*/
               	DeployedCopyFile = fopen("copy1.txt","w");
						while(!feof(deployedFile)){/*scanf all entries from
                  updated.txt into several varialbes*/
                     for( int s=0; s<1; s++){
            				fscanf(deployedFile,"%s %s %fl %fl %d %d %d\n",
                        &copy[s].name2[0], &copy[s].descrip[0], &copy[s].cost2,
                         &copy[s].idnum2, &copy[s].day1, &copy[s].month1,
                         &copy[s].year1);
                        printf("\n %s %s %fl %fl %d %d %d\n", copy[s].name2,
                        copy[s].descrip, copy[s].cost2, copy[s].idnum2,
                        copy[s].day1, copy[s].month1, copy[s].year1);

                        int u=strcmp(call, copy[s].name2);
                        if(u==0){
                          	continue;
                        }else{
                          	fprintf(DeployedCopyFile,"%s %s %fl %fl %d %d %d\n",
                           copy[s].name2, copy[s].descrip, copy[s].cost2,
                           copy[s].idnum2, copy[s].day1, copy[s].month1,
                           copy[s].year1);
                        }

                     }
                  }//end of while statement
                  fclose(DeployedCopyFile);
               }else{/*if file cant be read from it prints that it was not
               found or was unreadable*/
          	  		printf("\n\a\a\a\t\t *** Deployed FILE NOT FOUND or");
                  printf("...Unreadble file***\n");
       			}//end of if statement

               fclose(deployedFile);

               if(DeployedCopyFile = fopen("copy1.txt","r")){
               	deployedFile = fopen("deployed.txt","w");
               	while(!feof(DeployedCopyFile)){/*scanf all entries from
                  updated.txt into several varialbes*/
                     	fscanf(DeployedCopyFile,"%s %s %fl %fl %d %d %d\n",
                        &name2[0], &descrip[0], &cost2, &idnum2, &day1, &month1,
                         &year1);
                     	fprintf(deployedFile,"%s %s %fl %fl %d %d %d\n", name2,
                        descrip, cost2, idnum2, day1, month1, year1);

                  }
                  fclose(deployedFile);
               }else{
               	printf("\n\t\t *** Copy 1 File cannot be found or read");
                  printf(" from***\a\n");
               }
               fclose(DeployedCopyFile);
            	if(updatedFile = fopen("updated.txt","r")){/* checks if
               deployed.txt exsists and can open*/
               UpdatedCopyFile = fopen("copy2.txt","w");

						while(!feof(updatedFile)){/*scanf all entries from
                  updated.txt into several varialbes*/
                     for( int s=0; s<1; s++){
            				fscanf(updatedFile,"%s %s %fl %fl %d %d %d\n",
                        &allow[s].name1[0], &allow[s].change[0],
                        &allow[s].cost1, &allow[s].idnum1, &allow[s].day,
                        &allow[s].month, &allow[s].year);
                        printf("\n%s %s %fl %fl %d %d %d\n", allow[s].name1,
                        allow[s].change, allow[s].cost1, allow[s].idnum1,
                        allow[s].day, allow[s].month, allow[s].year);
                        int v=strcmp(call, allow[s].name1);
                        if(v==0){
                          	continue;
                        }else{
                          	fprintf(UpdatedCopyFile,"%s %s %fl %fl %d %d %d\n",
                           allow[s].name1, allow[s].change, allow[s].cost1,
                           allow[s].idnum1, allow[s].day, allow[s].month,
                           allow[s].year);
                        }
                     }

                  }//end of while statement

                   fclose(UpdatedCopyFile);

               }else{/*if file cant be read from it prints that it was nt found or
         	 			was unreadable*/
          				printf("\n\a\a\a\t\t *** Updated FILE NOT FOUND or");
                     printf("...Unreadble file***\n");
       			}//end of if statement

               fclose(updatedFile);

               if(UpdatedCopyFile = fopen("copy2.txt","r")){
               	updatedFile = fopen("updated.txt","w");
               	while(!feof(UpdatedCopyFile)){/*scanf all entries from
                  updated.txt into several varialbe*/
                     	fscanf(UpdatedCopyFile,"%s %s %fl %fl %d %d %d\n",
                        &name1[0], &change[0], &cost1, &idnum1, &day, &month,
                        &year);
                     	fprintf(updatedFile,"%s %s %fl %fl %d %d %d\n", name1,
                        change, cost1, idnum1, day, month, year);

                  }
                  fclose(updatedFile);

               }else{
               	printf("\n\t***Copy2 File cannot be found or read from***\n");
               }
            	fclose(UpdatedCopyFile);
         }
         if(ans == 2){
            clrscr();
         	sleep(5);
         }


}
void print(){
int count = 0;
int decision;
float cost1, idnum1, cost2, idnum2;
char name2[30], descrip[100];
int day1, month1, year1;
char name1[30], change[100];
int day, month, year;
double cost, costo;
FILE *deployedFile;
FILE *DeployedCostFile;
FILE *updatedFile;
FILE *UpdatedCostFile;

   clrscr();
	printf(" \nDO you want to print a report based on deployed programs,");
   printf(" updated programs or both?: ( enter 1 2 or 3 respectively) \t");
   scanf("%d", &decision);
   if(decision == 1){
   clrscr();
      if(deployedFile = fopen("deployed.txt","r")){/*checks if deployed.txt
      exsists and can open*/

				while(!feof(deployedFile)){/*scanf all entries from updated.txt i
            nto several varialbes*/
            		fscanf(deployedFile,"%s %s %.2fl %.2fl %d %d %d\n", &name2[0],
                   &descrip[0], &cost2, &idnum2, &day1, &month1, &year1);
                  printf("\n----- Delaware Software House Inc-----");
                  printf("\n Name of File is:\t %s", name2);
                  printf("\nTHe date deployed is:\t%d %d %d", day1, month1,
                  year1);
                  printf("\n A brief description of the program:\n \t %s",
                  descrip);
                  printf("\n The ID number entry is:\t %.2fl ", idnum2);
                  printf("\n THe cost to deploy this program was:\t %.2fl ",
                  cost2);
                  printf("\n\n**** Delaware : Excellence is efficiency*****\n");
            }
            fclose(deployedFile);

      }else{//if the if statemnt isnt true it goes to else portion
         	/*prints to the screen that file is not found or unreadble*/
         	printf("file not found, or unreadable!!\n");
       }//end of if statement
       computecost();
       DeployedCostFile = fopen("costo.txt","r");

       while(!feof(DeployedCostFile)){//scanf entries from file into variables
         fscanf(DeployedCostFile,"%ld\n",&costo);
         printf(" Cost of deployed programs is: \t %ld", costo);
       }

       fclose(DeployedCostFile);
   }
   if(decision = 2){
   clrscr();
   	if(updatedFile = fopen("updated.txt","r")){/* checks if updated.txt
      exsists and can open*/

				while(!feof(updatedFile)){/*scanf all entries from updated.txt
            into several varialbes*/
            		fscanf(updatedFile,"%s %s %.2fl %.2fl %d %d %d\n", &name1[0],
                   &change[0], &cost1, &idnum1, &day, &month, &year);
                  printf("\n++++++ Delaware Software House Inc++++++");
                  printf("\n Name of File is:\t %s", name1);
                  printf("\n THe date deployed is:\t%d %d %d", day, month,
                  year);
                  printf("\n Changes made to the program are:\n \t %s",
                  change);
                  printf("\n THe cost to update this program was:\t %.2fl ",
                  cost1);
                  printf("\n The ID number entry is:\t %.2fl ", idnum1);
                  printf("\n**** Delaware : Excellence is efficiency*****\n\a");
                  count = (count +1);
            }
            fclose(updatedFile);
   	}else{//if the if statemnt isnt true it goes to else portion
         	/*prints to the screen that file is not found or unreadble*/
         	printf("file not found, or unreadable!!\n");
      }//end of if statement
      computecost();
      UpdatedCostFile = fopen("cost.txt","r");

      while(!feof(UpdatedCostFile)){//scanf all entries from file into variables
         fscanf(UpdatedCostFile,"%ld\n",&cost);
         printf(" Cost of updated programs is: \t %ld", cost);
       }

       fclose(UpdatedCostFile);
       printf("Total amount of times programs have been updates is:\t%d",count);
   }
   if(decision == 3){
   clrscr();
   if(deployedFile = fopen("deployed.txt","r")){/* checks if deployed.txt
    exsists and can open*/

				while(!feof(deployedFile)){/*scanf all entries from updated.txt
            into several varialbes*/
            		fscanf(deployedFile,"%s %s %.2fl %.2fl %d %d %d\n", &name2[0],
                   &descrip[0], &cost2, &idnum2, &day1, &month1, &year1);
                  printf("\n----- Delaware Software House Inc-----");
                  printf("\n Name of File is:\t %s", name2);
                  printf("\n THe date deployed is:\t%d %d %d", day1, month1,
                  year1);
                  printf("\n A brief description of the program:\n \t %s",
                  descrip);
                  printf("\n The ID number entry is:\t %.2fl ", idnum2);
                  printf("\n THe cost to deploy this program was:\t %.2fl ",
                  cost2);
                  printf("\n***** Delaware : Excellence is efficiency*****\n");
            }
            fclose(deployedFile);

       }else{//if the if statemnt isnt true it goes to else portion
         	/*prints to the screen that file is not found or unreadble*/
         	printf("file not found, or unreadable!!\n");
       }//end of if statement
       computecost();
       DeployedCostFile = fopen("costo.txt","r");

       while(!feof(DeployedCostFile)){//scanf entries from file into variables
         fscanf(DeployedCostFile,"%ld\n",&costo);
         printf(" Cost of deployed programs is: \t %ld", costo);
       }

       fclose(DeployedCostFile);

     if(updatedFile = fopen("updated.txt","r")){/* checks if updated.txt exsists
      and can open*/

				while(!feof(updatedFile)){/*scanf all entries from updated.txt into
             several varialbes*/
            		fscanf(updatedFile,"%s %s %.2fl %.2fl %d %d %d\n", &name1[0],
                   &change[0], &cost1, &idnum1, &day, &month, &year);
                  printf("\n++++++ Delaware Software House Inc++++++");
                  printf("\n Name of File is:\t %s", name1);
                  printf("\n THe date deployed is:\t%d %d %d", day, month,
                   year);
                  printf("\n Changes made to the program are:\n \t %s",
                  change);
                  printf("\n THe cost to update this program was:\t %.2fl ",
                   cost1);
                  printf("\n The ID number entry is:\t %.2fl ", idnum1);
                  printf("\n***** Delaware : Excellence is efficiency*****\n");
                  count = (count +1);
            }
            fclose(updatedFile);
   	}else{//if the if statemnt isnt true it goes to else portion
         	/*prints to the screen that file is not found or unreadble*/
         	printf("file not found, or unreadable!!\n");
      }//end of if statement

      computecost();
      UpdatedCostFile = fopen("cost.txt","r");

      while(!feof(UpdatedCostFile)){//scanf all entries from file into variables
         fscanf(UpdatedCostFile,"%ld\n",&cost);
         printf(" Cost of updated programs is: \t %ld", cost);
       }

       fclose(UpdatedCostFile);
       printf("Total amount of times programs have been updates is:\t%d",count);
   }
}






















