/*IA tax program for Starlite Renewable*/
/*Registration number: 1004041354   */
/*Center number: 100404*/
/*Subject: COmputer Science*/
/*Year: 2010*/
/*Name: Olanrewaju Okunlola*/


#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<string.h>

/*structure which creates a 15 bit string called taxtype and a float called tax.
 This is used when the user only wants to input a tax and its type and not items
 for which tax must be calculated for*/
struct taxe{
	char taxtype[15];
   float tax;
   };
taxe arraytax[100];/*creates an array of taxe, a structure which contains a
string and a float, with 100 memory cells*/


/* a structure which creates a 15 bit string called taxtyp, and two float called
 taxn and itmprc. this structure is only used if the user wants to enter an item
  which a tax on
it to be deducted.*/
struct taxe2{
	char taxtyp[15];
   float taxn;
   float itmprc;
   };
taxe2 arraytax2[100];/*creates an array of taxe2, a structure which contains a s
tring and two floar, with 100 memory cells*/


//declare function entertaxonly which accepts and saves the tax and tax type
void entertaxonly();
//declare function itemandtaxdeduct which accepts
void itemandtaxdeduct();
//declare function getandcompute which takes no parameters
void getandcompute();
//declare function storeindisk which takes no parameters
void storeindisk();
//declare function allocatefortax which takes in no parameter
void allocatefortax();
//declare function allocateforitemandtax which takes no parameters
void allocateforitemandtax();
//declare a function called menu which takes no parameter and returns a integer
int menu();
//declare a function called screenplay which takes no parameters
void screenplay();

//main function called void main which accepts no parameters is created here
void main(){
         screenplay();
         int option;
			//calls the menu function and places the value of choice in option
   		option=menu();
         int ans;/*creates an integer called ans which allows to user to
         allocate their answer to the question of if they want to enter tax on
         its own or an item which is tax deductible*/
   /*performing a while loop which checks if the chioce entered is less than
    6 and more than 0 then implements a certain action*/
   while(option>0&&option<7){

      /*checks if the chioce entered is 1 then prints a statement that
      delcares option 1 is selected*/
   	if(option==1){
         clrscr();/* a function to clear the things printed on screen, meant
         to make the program looks presentable.*/
      	/*prints on the screen that Option 1 is selected after using an if
         statement to check this. It is conditional and will nto appear if
         Option 1 was not selected*/
   		printf("Option 1 selected\n");
         /*asks if the user wants to enter a tax amount only or a item which
         tax may be deducted form*/
   		printf("Does the transaction include only a tax amount or an actual ");
         printf("transaction with item and tax deductible(1/2)\n");
         scanf("%d",&ans);//enters answer in memory
         fflush(stdin);//ensures enter and space are not entered as answers
         /*checks if the answer was 1, if so it implememts a process, if not
         it terminates*/
         if(ans==1){
         		entertaxonly();/*calls back function entertaxonly which takes
               no parameters*/
         }
         if(ans==2){/*checks if the answer was 2, if so it implememts a
         process, if not it terminates*/
         		itemandtaxdeduct();/*calls back a function called
               enteritemandtaxdedut which takes no parameters*/
         }
         /*if statement to check that if the answer is not 1 or two an
         incorrect assignment has been made*/
         if((ans != 1)&&(ans != 2)){
         	printf("\nIncorrect assignment, question asked for 1 for taxonly ");
            printf("option and 2 for item and tax transaction\n");
         }

         option=menu();/*calls back function menu which accepts no parameters
         into the void main function in which is serves the purpose of allowing
          the user to enter another option*/


		}//if statement ends

      /*checks if the choice entered is 2 then prints a statement declaring that
       option 2 is selected*/
   	if(option==2){
      	clrscr();/* a function to clear the things printed on screen, meant to
         make the program looks presentable.*/
         /*prints on the screen that Option 2 is selected after using an if
         statement to check this. it is conditional and will not appear if
         Option 2 was not selected*/
   		printf("Option 2 selected\n");
          getandcompute();/*calls back function getandcomputewhich accepts no
          parameters*/

         option=menu();
         /*calls back function menu which accepts no parameters into the void
         main function in which is serves the purpose of allowing the user to
         enter another option*/
   	}//if statement ends

      /*a function to check if the choice entered is 3 and  prints a statements
       declaring option 3 is selected*/
   	if(option==3){
      	clrscr();/* a function to clear the things printed on screen, meant to
         make the program looks presentable.*/
      	/*prints on the screen that Option 3 is selected after using an if
			statement to check this. it is conditional and will not appear if
         Option 3 was not selected*/
      	printf("Option 3 selected\n");
         //calls back function storeindisk which takes in no parameters
         storeindisk();
         option=menu();/*calls back function menu which accepts no parameters
         into the void main function in which is serves the purpose of allowing
         the user to enter another option*/
   	}//if statement ends

      /*checks if the choice entered is 4 and prints a statement delcaring that
		option 4 is selected*/
   	if(option==4){
          clrscr();/* a function to clear the things printed on screen, meant
          to make the program looks presentable.*/
         /*prints on the screen that Option 4 is selected after using an if \
         statement to check this. it is conditional and will not appear if
         Option 4 was not selected*/
   		printf("Option 4 selected\n");
         allocatefortax();//calls back function allocatefortax
         option=menu();/*calls back function menu which accepts no parameters
         into the void main function in which is serves the purpose of allowing
         the user to enter another option*/
   	}//if statement ends

      /*checks if the choice entered is 5 and prints a statement delcaring that
      option 5 is selected*/
   	if(option==5){
      	clrscr();/* a function to clear the things printed on screen, meant to
         make the program looks presentable.*/
         /*prints on the screen that Option 5 is selected after using an if
         statement to check this. it is conditional and will not appear if
         Option 5 was not selected*/
   		printf("Option 5 selected\n");
         allocateforitemandtax();/*calls back function allocateforitemandtax
         which takes in no parameters*/

         option=menu();/*calls back function menu which accepts no parameters
         into the void main function in which is serves the purpose of allowing
         the user to enter another option*/
   	}//if statement ends

    	 /*checks if the choice entered is 5 and prints a statement declaring that
        option 5 is selected*/
   	if(option==6){
      	clrscr();/* a function to clear the things printed on screen, meant to
         make the program looks presentable.*/
      	/*prints on the screen 'thanks for using' after an if statement is used
          to check if option 6 was selected. It will only appear if option 6 is
          selected*/
      	printf("Thanks for using\n");
         /*this call terminated the program after 2 seconds and is used when
         option 6 is selected and after thanks for using is printed on the
         screen*/
          sleep(2);
         /*calls back function named menu, however option 7 does not exsist in
          menu so it terminates*/
         option=7;
   	}//if statement ends
   }//while statement ends



}//void main ends
void screenplay(){/*start of function called screenplay which displays text
on screen*/
/*prints characters formatted to screen*/
printf("\n\n\n\n\t\t   * * *  ***********      ****           ********     \n");
/*prints characters formatted to screen*/
printf("\t\t  *          **          *   **          **      *      \n");
/*prints characters formatted to screen*/
printf("\t\t *           **         *      **        **        *    \n");
/*prints characters formatted to screen*/
printf("\t\t *           **        *        **       **        *    \n");
/*prints characters formatted to screen*/
printf("\t\t  * * * *    **       *          **      **       *     \n");
/*prints characters formatted to screen*/
printf("\t\t         *   **      ***************     **     *       \n");
/*prints characters formatted to screen*/
printf("\t\t         *   **     *              **    **       *     \n");
/*prints characters formatted to screen*/
printf("\t\t        *    **    *                **   **         *   \n");
/*prints characters formatted to screen*/
printf("\t\t  * * *      **   *                  **  **           * \n");
sleep(1);/*function to cause all data on screen to be wiped after a set amount
of seconds*/
clrscr();//clears all data left on screen
/*prints characters formatted to screen*/
printf("\n\n\n\n\t\t\t **         **  ************  ********* \n");
/*prints characters formatted to screen*/
printf("\t\t\t **        ****      **       *         \n");
/*prints characters formatted to screen*/
printf("\t\t\t **         **       **       *         \n");
/*prints characters formatted to screen*/
printf("\t\t\t **                  **       *         \n");
/*prints characters formatted to screen*/
printf("\t\t\t **         **       **       ****      \n");
/*prints characters formatted to screen*/
printf("\t\t\t **         **       **       *         \n");
/*prints characters formatted to screen*/
printf("\t\t\t **         **       **       *         \n");
/*prints characters formatted to screen*/
printf("\t\t\t **         **       **       *         \n");
/*prints characters formatted to screen*/
printf("\t\t\t ********** **       **       ********* \n");
sleep(1);
clrscr();//clear all data left on screen

printf("\n\n\n\n\n\n\t\t\t\t COMPANY TAX PROGRAM   ");
sleep(1);
clrscr();
}
int menu(){

/*creating a integer to named chioce to allow the user to choose one of the
items in the menu, from 1 to 5*/
int decision;
   //prints on the screen inside the function menu(); 'school manager module'
	printf("\n\t Starlite Renewable Company Tax Program");
   /*prints a series of symbols on the screen after it prints school manger
   module, this is done inside the funciton menu();*/
   printf("\n\t==============================================================");
   //prints an option in the option menu inside the function menu
   printf("\n           1. Enter tax statements           ");
   //prints an option in the option menu inside the function menu
   printf("\n           2. Gather tax statments in file and compute total due");
   //prints an option in the option menu inside the function menu
   printf("\n           3. Store old tax statements    ");
   //prints an option in the option menu inside the function menu
   printf("\n           4. Allocate item prices in different files along with tax type");
   //prints an option in the option menu inside the function menu
   printf("\n           5. Allocates tax amounts with tax type in different files   ");
   //prints an option in the option menu inside the function menu
   printf("\n           6. Exit   ");
	/*tells the user to input one of the options shown above inside the function
    menu();*/
   printf("\n\n        Enter Options              \t");
	//scans and inputs in computer one of the options above if it a numerical one
	scanf("%d",&decision);
//to enable choice to be returned whereever you call you call it
return decision;
}//end of menu function

void entertaxonly(){/*start of function entertaxonly which takes in no
parameters and allows the user to enter and store tax and its type in a file*/

	int x;//declare an integer called x
   FILE *jp;//declare a file pointer called jp
   int day, month, year;//declares 3 integers called day, month and year
   int answer;//declares an integer called answer

   printf("how many entries do you want to input, note the maximum is 100\t");/*
   asks the user to print the amount of entries that need to be inputted,
   stating that the maximum is 100*/
   scanf("%d",&x);//stores the answer which is an integer in memory
   if ((x<100)&&(x>0)){/*if statement checking that the entry entered isnt
   above 100 and below 0, if it is it tells the user that it is an incorrect
    entry*/
   	jp = fopen("taxfilenew.txt","a");/*operation to open the file
      taxfilenew.txt in memory using file pointer*/
   	for(int s=0; s<x; s++){/*implememts and allows the user to enter and
      store in file whenver integer s is below the amount of items they wanted
      to enter */
      	/*asks the user to enter the type of tax they want entered*/
			printf("\nPlease enter the type of tax you want stored\t");
         /*stores the variable entered which is a string in memory*/
      	scanf("%s",&arraytax[s].taxtype[0]);
         fflush(stdin);//ensures space isnt accepted as a variable*/
         int r = strlen(arraytax[s].taxtype);/*checks if there is actually
         something inside the stirng entered, if not it asks the user to enter
         the stirng again.*/
      	while(r == 0){/*start of while loop qhich implements if the lenth of
         the stirng is 0*/
         	printf("\nImpossible assignment, must be a string\a\n");/*prints
            error to screen*/
     	   	printf("\n Please enter the amount of the tax you are storing\t");/*
            asks user to enter a string*/
      		scanf("%fl",&arraytax[s].tax);/*stores new entry in memory,
            overwriting the previous one*/
      		fflush(stdin);//ensures that space is not accepted as a variable
         }//end of while loop
         printf("\n Please enter the amount of the tax you are storing\t");/*
         asks the user to enter the tax amount they want stored*/
         scanf("%fl",&arraytax[s].tax);/*stores the float in memory*/
         fflush(stdin);//ensures enter or space is not entered as a variable
         while(arraytax[s].tax<0){ /*start of while loop to check if the tax
         amount entered is above 0, if so it terminates if not it asks the user
          to enter the entry again*/
         	printf("Impossible assignment. Must be greater than 0");/*tells the
            user that the tax amount which is below 0 is an impossible
            assignment in a while loop*/
            printf("\n Please enter the amount of the tax you are storing\t");/*
            asks the user the enter the new tax amount because the previous
            entry was below 0*/
      		scanf("%fl",&arraytax[s].tax);/*stores the new amount in memory if
            the orginal one was below zero and overwrites the previous entry*/
      		fflush(stdin);/*ensures that enter and space are not regonized as
            variables*/
         }//end of while loop
      	printf("Please enter the day \t");/*asks the user for the day*/
      	scanf("%d",&day);/*stores thew variable for the day in memory*/
      	fflush(stdin);/*ensures that enter and space are not regonized as
         variables*/
      	while(day>31){/*checks that day isnt above 31, wont terminate until
         correction is made*/
           printf("\a\a\n Wrong entry entered, no month has so many days!\n");/*
           prints to screen that the month entered is above 31 which is
           incorrect, this is within a while loop which implements when this
           is true*/
           printf("Please enter the correct day \t");/*asks the user to enter
           the day once more*/
           scanf("%d",&day);/*stores the new day in memory, thus writing the
           new entryto the variable */
           fflush(stdin);/*ensure that space and enter are not regonized
           as variables*/
      	}//end of while
      	printf("Please enter the month\t");/*tells the user to please enter
          the current month*/
      	scanf("%d", &month);/*stores the variable within month in memory*/
      	fflush(stdin);/*ensure that space and enter are not regonized as
         variables*/
      	while(month>=12){/*checks that month enterd isnt over 12, wont
         terminate until correction is made*/
         	/*print to screen that the months are too many and the tax statment
             are due before the last day of november*/
      		printf("\a\nError, wrong entry entered no year has so many months");
            printf("and tax statements are due by end of 11th month\n");
         	printf("Please  enter the month\t");/*asks the user to enter the
             month, this tme it is within a while loop which will store this
             and check if it is not above 11*/
      		scanf("%d", &month);/*stores the entry within month in memory
            writing the new entry to the variable*/
      		fflush(stdin);/*ensure that space and enter are not regonized as
            variables*/
      	}//end of while loop
      	while((month == 2)&&(day>28)){/*ensures that a day above 29 isnt
         entered in febraury unless it is a leap year, wont terminate until
         it is corrected*/
           printf("\nERROR Please enter a new day, february has 28 days\a\n");/*
           tells the user that they have entered too amny days for a month with
           only 28 days*/
           printf("IS this a leap year?, 1 for yes 2 for no\t");/*asks the user
           if the current year is a leap year, thus it will allow it to enter 29
           */
           scanf("%d",&answer);/*stores the variable within year in memory,
            writing the new entryto the varialbe*/
           fflush(stdin);/*ensure that space and enter are not regonized as
           variables*/
            	if(answer!= 1){/*if statement to check if the answer to the
               above is 1 or yes and prints something to screen*/
      				while(day>28){/*while loop which implements once, while not
                  in a leap year, the entry for febraury is 28*/
               		printf("Please enter the correct day");/*asks the user to
                     input the correct day of the year, one that is below 28
                      for a non leap year 2nd month*/
                  	scanf("%d",&day);/*stores the entry within day in memory,
                      writing the new entry to the variable*/
                  	fflush(stdin);/*ensure that space and enter are not
                      regonized as variables*/
                  }//end of while loop
               }//end of if statment

        }//end of while
        while(day>30){/*checks that day isnt above 30 in months which only
        30 days, wont terminate until date entered is acceptable*/
				if((((month == 9)&&(month == 4)&&(month == 6)&&(month == 11)))){/*
            if statement to check if the days entered werent over 30 for a
            month with 30 days only*/
      			printf("\a\nwrong entry entered, that month has 30 days\n");/*
               tells the user that the 31 days they inputted was too many for
               a month with only 30*/
         		printf("Please enter the day \t"); /*asks the user to enter
               the day of the month*/
      			scanf("%d",&day);/*stores the entry within day in memory,
               writing the new entry to the variable*/
      			fflush(stdin);/*ensure that space and enter are not regonized
               as variables*/
            }//end of if statement
        } //end of while loop
        printf("Please enter the year\t");/*asks the user to enter the year*/
        scanf("%d", &year);/*stores the variable within day in memory,*/
        fflush(stdin);/*ensure that space and enter are not regonized as
        variables*/
        while(year<0){/*checks that year is not below 0, if so it doesnt
        terminate*/
      		printf("\a\nError, wrong entry entered. no year is negative\n");/*
            tells the user they they entered a negative year, which is
             impossible*/
         	printf("Please enter the year\t");/*aks the user to enter
            the year once more*/
      		scanf("%d", &year);/*stores the entry within year in memory,
            writing the new entry to the variable*/
      		fflush(stdin);/*ensure that space and enter are not regonized
            as variables*/
      	}//end of while loop
			/*operation to print several things into a file using a file pointer*/
			fprintf(jp,"%d %d %d %s %fl\n",day, month, year, arraytax[s].taxtype, arraytax[s].tax);


  	   }//end of for loop
      fclose(jp);//operations to close file using file pointer jp

  		 printf("\n you have entered and stored date in file");/*prints to
       the screen that the user's attempt to store entries in file was a
       success*/
   	clrscr();/*function to clear screen of data printed*/
   }else{/*if the number of entries was too big or too small the program
    goes to the else portion of that if statement*/
   		/*prints the screen that because the user entered a number, too
         large or too small to fit of entries, it will cause a problem and
         refers them back to the menu*/
    printf("\n\a\n Wrong Entry!!!!!\nArray been used to store data wont hold");
    printf("so many entries and wont store less than 0, you will be returned");
      printf(" to menu\n");
   }//end of if statement


}//end of function entertaxonly
void itemandtaxdeduct(){/*start of function itemandtaxdeduct which taxes in
 no parameters and allows the user to enter and store tax, item which tax
 was levied on and the date*/
	int xo;//declare integer called xo
   float taxc;//declare a float called taxc
   int day, month, year;//declare 3 integers called day, month and year
   FILE *jp;//declares a file pointer called jp
   int answer;//declares an integer called answer



   	printf("how many entries do you want to input,note the maximum is 100\t");
   	scanf("%d",&xo);
      if((xo<100)&&(xo>0)){
      	jp = fopen("taxfile2.txt","a");
   		for(int s=0; s<xo; s++){/*implememts and allows the user to enter and
          store in file whenver integer s is below the amount of items they
          wanted to enter*/
				printf("Please enter the type of tax you are storing and paying");
            /*prints on the screen that the user must enter the taxtyp*/
            printf(" for\t");
      		scanf("%s",&arraytax2[s].taxtyp[0]); /*stores the entry within
            taxtyp in memory*/
            fflush(stdin);/*ensure that space and enter are not regonized as
            variables*/
            int r=strlen(arraytax2[s].taxtyp);
      		while(r == 0){ /*a while loop that implements when the string
            length of the taxtyp is 0 and allows the user to enter a new
            varaible*/
            	printf("\nIncorrect assignment. must be a string\n");/*tells
               the user than they entered an incorrect assignment, correct
               one should be a string*/
            printf("Please enter the type of tax you are storing and paying");
            /*prints on the screen that the user must enter the taxtyp*/
            printf(" for\t");
      			scanf("%s",&arraytax2[s].taxtyp[0]);/*stores the entry within
               taxtyp in memory writing the new entry to the variable*/
            	fflush(stdin);/*ensure that space and enter are not regonized
               as variables*/
            }//end of while loop
      		printf("\nPlease enter the percentage of tax on the item you have ");
            printf("bought or are selling\t");//tells the user to enter the taxn
      		scanf("%fl",&arraytax2[s].taxn);/*stores the entry within taxn in
            memory*/
         	fflush(stdin);/*ensure that space and enter are not regonized as
            variables*/
            while(arraytax2[s].taxn<0){/*implements when the tax percent is
             not smaller than 0*/
             /*tells the user that they entered an incorrect assignment
              and the entry must be greater than 0*/
             printf("INCORRECT ASSIGNMENT entry must be greater than zero/a/a");
               //tells the user to enter the taxn
               printf("\n Please enter the percentage of tax on the item you");
               printf(" have bought or are selling\t");
      			scanf("%fl",&arraytax2[s].taxn);/*stores the entry within taxn
               in memory writing the new entry to the variable*/
         		fflush(stdin);/*ensure that space and enter are not regonized
               as variables*/
            }//end of while loop
      		printf("Please  enter the amount of the item which tax is to be");
            printf(" caluculated for\t");/*tells the user to enter the itmprc*/
            //stores the entry within itmprc in memory
      		scanf("%fl",&arraytax2[s].itmprc);
            //ensure that space and enter are not regonized as variables
         	fflush(stdin);
            while(arraytax2[s].itmprc<0){/*implements if item put in for itmprc
             is less than zero and tells the User that such an entry is an error
              and allows them to correct this*/
               //tells the user that the entry must be greater than 0
            	printf("INCORRECT entry, must be greater than 0/a");
               /*tells the user to enter the itmprc*/
               printf("Please enter the amount of the item which tax is to be");
               printf(" caluculated for\t");
      			scanf("%fl",&arraytax2[s].itmprc);/*stores the entry within
               itmprc in memory writing the new entry to the variable*/
         		//ensure that space and enter are not regonized as variables
               fflush(stdin);
            }//end of while loop
         	printf("Please enter the day\t");//tells the user to enter the day
      		scanf("%d",&day);//stores the entry within day in memory
            //tells the user that no month has s many days
      		fflush(stdin);
       		while(day>31){/*checks that day isnt above 31, wont terminate until
             correction is made*/
            	//tells the user that no month has s many days
         		printf("\a\nWrong entry entered no month has so many days \n");
               //tells the user to enter the day
            	printf("Please enter the day\t");
      			scanf("%d",&day);/*stores the entry within day in memory writing
                the new entry to the variable*/
               //ensure that space and enter are not regonized as variables
      			fflush(stdin);
         	}//end of while loop
            //tells the user to enter the month
         	printf("Please enter the month\t");
      		scanf("%d",&month);//stores the entry within month in memory
      		fflush(stdin);/*ensure that space and enter are not regonized as
            variables*/
         	while(month>12){/*checks that month enterd isnt over 12, wont
            terminate until correction is made*/
         		printf("\aERROR wrong entry entered no year has so many months\n");/*tells the user than no year has so many month*/
               //tells the user to enter the month
            	printf("Please enter the month\t");
      			scanf("%d",&month);/*stores the entry within month in memory
               writing the new entry to the variable*/
               //ensure that space and enter are not regonized as variables
      			fflush(stdin);
         	}//end of while loop
         	while((month == 2)&&(day>28)){/*ensures that a day above 29 isnt
            entered in febraury unless it is a leap year, wont terminate until
             it is corrected*/
            	/*tells the user that the entry is incorrect and febraury has
               only 28 days*/
      			printf("ERROR Please enter a new day, february has 28 days\a\n");
      			printf("IS this a leap year?, 1 for yes 2 for no\t");/*asks the
               user if this is a leap year, 1 for yes and 2 for no*/
            	scanf("%d",&answer);/*stores the entry within answer in memory*/
               /*ensure that space and enter are not regonized as variables*/
            	fflush(stdin);
               /*checks if the answer for the leap year question is 1(yes)*/
            	if(answer!= 1){
      				while(day>28){//implements once the day entered is above 28
                     //tells the user to enter the day
               		printf("Please enter the correct day");
                  	scanf("%d",&day);/*stores the entry within day in memory
                      writing the new entry to the variable*/
                     /*ensure that space and enter are not regonized as
                     variables*/
                  	fflush(stdin);
                  }//end of while loop
               }//end of if statement

       		}//end of while loop
         	while(day>30){/*checks that day isnt above 30 in months which only
             30 days, wont terminate until date entered is acceptable*/
               //checks that the days entered werent 31 for months with 30 days
					if((((month == 9)&&(month == 4)&&(month == 6)&&(month == 11)))){
      				printf("\a\nwrong entry entered, that month has 30 days\n");/*
                  tell the user that the entry is incorrect and that that month
                   has 30 days*/
                  //tells the user to enter the day
         			printf("Please enter the day \t");
      				scanf("%d",&day);/*stores the entry within day in memory
                   writing the new entry to the variable*/
                  /*ensure that space and enter are not regonized as variables*/
      				fflush(stdin);
            	}//end of if statement
           }//end of while loop
         	printf("Please enter the year\t");//tells the user to enter the year
      		scanf("%d",&year);//stores the entry within year in memory
            //ensure that space and enter are not regonized as variables
      		fflush(stdin);
            //checks that year is not below 0, if so it doesnt terminate
         	while(year<1){
            	/*tells the user that the wrogn entry was entered and that
               there are no negative years*/
               printf("\aERROR wrong entry entered. cant have negative years\n");
               //tells the user to enter the year
         		printf("Please enter the year\t");
      			scanf("%d",&year);/*stores the entry within year in memory
               writing the new entry to the variable*/
               //ensure that space and enter are not regonized as variables
      			fflush(stdin);
				}//end of while loop
            /*operation to calculate amount of tax is on the item using the tax percent to be levied on it*/
      		taxc = ((arraytax2[s].taxn/100) * arraytax2[s].itmprc);
            /*operation to print entries into file using file pointer*/
         	fprintf(jp, "%d %d %d %s %fl %fl\n", day, month, year, arraytax2[s].taxtyp, arraytax2[s].itmprc, taxc);


      	}//end of forloop
      	fclose(jp);//operartion to close file using file pointer


      	/*prints to the screen that the user's attempt to store entries in
         file was a success*/
      	printf("\n You have stored content in a file");
      	clrscr();//funciton to clear the screen of data printed
      }else{
      	/*prints the screen that because the user entered a number, too
         large or too small to fit of entries, it will cause a problem and
         refers them back to the menu*/
      	printf("\n\a\nWrong entry!!!!\n Array cannot hold more than 100 entries or less than 0, you will be returned to main menu\n\n");
      }//end of if statement


}//end of void itemandtaxdeduct
void getandcompute(){/*start of function getandcompute which takes in no
parameters and gets data from files above and computes several items and stores
 them in a new file along with date*/

float paytoemp;//declare float called paytoemp
FILE *fp;//declare file pointer called fp
FILE *jp;//declare file pointer called jp
FILE *kp;//declare file pointer called kp
int day, month, year;//declare 3 integers called day, month, year
int day2, month2, year2; //decalre 3 integers called day2, month2, year2
int month3, day3, year3;//declare 3 integers called month2, year3, day3
long count;//declare long called count
long compute1;//declare long called compute1
long compute2;//declare long called compute2
long compute3;//declare long called compute3
float medi;//declare float called medi
float soci;//declare float called soci
float star; //declare float called star
float star2;//declare float called star2
float j;//declare floar called j
int da_mon, da_year, sure;//declare 3 integers called da_mon da_year and sure
char taxtype2[15];//declare a string which takes in 15 bits called taxtype2
float tax2;//declare float called tax2
char taxtyp2[15]; //declare string called taxtyp2 which takes in 15 bits
float itmprc2, taxc;//declare 3 floats called itmprc2 and taxc

compute1 = 0;//assigns compute1, which was delcared before as a long, to 0
compute2 = 0;//assigns compute2, which was delcared before as a long, to 0
compute3 = 0;//assigns compute3, which was delcared before as a long, to 0
count = 0;//assigns count, which was delcared before as a long to 0




      //asks the user for the current month
      printf("what is the current month");
      //stores the entry within da_mon in memory
      scanf("%d", &da_mon);
      fflush(stdin);//ensure that space and enter are not regonized as variables
      /*asks the user for the current year*/
      printf("what is the current year?");
      /*stores the entry within da_year in memory*/
      scanf("%d",&da_year);
      fflush(stdin);//ensure that space and enter are not regonized as variables
      while(da_year<0){/*checks that year is not below 0, if so it doesnt termin
      ate until the correction is made*/
      	/*Tells the user that they have entered an incorrect assignment*/
      	printf("\a\a\a Incorrect Assignment\n");
         /*after telling the user that the entry is incorrect the program asks
         the user to enter the year again*/
         printf("Please enter the year:\t");
         /*stores the entry within da_year in memory writing the new entry to
         the variable*/
         scanf("%d",&da_year);
         fflush(stdin);/*ensure that space and enter are not regonized as variab
         les*/
      }
      if(da_mon<12){//checks that month enterd isnt over 12
      	/*asks the user for the amunt of profit earned (thus far) in the
          current year*/
         printf("What was the amount of profit you recieved this year?");
         //stores the entry within j in memory
         scanf("%fl",&j);
         fflush(stdin);/*ensure that space and enter are not regonized as varia
         bles*/
         /*checks if the taxfilenew.txt exsists and can be read from,
         undergoes several operations if this is so or goes to else portion is not true*/
      	if(jp = fopen("taxfilenew.txt","r")){
         	/*prints to the screen that tac file 1 been searched*/
      		printf("\n------------------------taxfile 1 been searched------------------------------\n");
            /*a while loop that terminates if the iteration has reached the
            end of the file which in memory using the file pointer jp*/
   			while(!feof(jp)){
            		//scanf all entries from taxfilenew.txt into several varialbes
            		fscanf(jp,"%d %d %d %s %fl\n", &day2, &month2, &year2, &taxtype2[0], &tax2);
                  /* a if statement to check is, while the entries of which
                  compute2 is to be calculated for is the current year that the user entered*/
                  if((month2<=da_mon)&&(year2 == da_year)){
                  	/*while not at the end of file it adds the tax amount
                     to a long named compute2*/
                  	compute2 = (tax2 + compute2);
                  }//end of if statement
            }//end of while loop
            /*operation to close file taxfile2.txt using file pointer fp*/
            fclose(jp);
         }else{//if the if statemnt isnt true it goes to else portion
         	/*prints to the screen that file is not found or unreadble*/
         	printf("file not found, or unreadable!!\n");
         }//end of if statement
         /*if statement to check if taxfile2.txt exsists and if data can be
         read from the while, if not goes to else portion*/
         if(fp = fopen("taxfile2.txt","r")){
         	/* prints to screen that tax file 2 been searched*/
         	printf("\n-----------------tax file 2 been searched-------------------------------------\n");
            while(!feof(fp)){/*a while loop that terminates if the iteration
            has reached the end of the file which in memory using the file pointer fp*/
               //scanf all entries from taxfilenew.txt into several varialbes
            	fscanf(fp, "%d %d %d %s %fl %fl\n", &day3, &month3, &year3, &taxtyp2[0], &itmprc2, &taxc);
                /* a if statement to check is, while the entries of which
                compute1, compute3 and count is to be calculated for is the
                current year that the user entered*/
                if((month3<=da_mon)&&(year3 == da_year)){
                	/*while not at the end of file adds up the amount of item
                   prices been which tax was been deducted form*/
               	compute1 = (compute1+itmprc2);
                  /*while not at the end of file adds te amount of tax on each
                  item*/
         		 	compute3 = (taxc+compute3);
                  /*while not at the end of the file counts each time the loop
                  goes around*/
         			count = (count+1);
               }//end of if statement
            }//end of while loop
            /*operation to close file taxfile2.txt using file pointer fp*/
            fclose(fp);

         }else{/*if file cant be read from it prints that it was nt found or
          was unreadable*/
         	printf("\a\a\a FILE NOT FOUND or...Unreadble file\n");
         }//end of if statement

         if((count == 0)&&(compute2 == 0)){/*ensures that compute 2 and count
         are only used if there is an item in the file which allows it to be
         used without returning zero*/
            /*prints to screen that nothing in file 1 and file 2 that can be
            used to calculate compute2 and count, thus the file if empty of
            entires for that year*/
         	printf("\nNothing in file 1 or file 2 for that year");
         }
         if(count == 0){/*ensures that count is not used unless there are
         entries in file by checking if, after going through the file the
         program finds nothing to count*/
            /*prints to screen that nothing in file 2 that can be used to
            calculate count, thus the file if empty of entires for that year*/
         	printf("\nNothing for this year in file 2");
         }
         if(compute2 == 0){/*ensures that compute2 is not used unless there
         are entries in file by checking if, after going through the file
         the program finds nothing to compute for*/
            /*prints to screen that nothing in file 1 that can be used to
            calculate compute2 thus the file if empty of entires for that year*/
         	printf("\nNothing for this year in file 1\n");
         }
         if(count != 0){/*ensures that star is only carried out if there are
         items in file which allows its components like count to be used without
          returnign zero*/
             /* undergoes an arithmetic operation to calcuate the average
             percent of tax deducted in the year by dividing the tax amount
              by the amount of transaction in place and dividing
             final figure by the amount of item prices accounted for*/
             star = (((compute3/count)/compute1)*100);
         }
         if(kp = fopen("function2file.txt","w")){/*if to check if file
         function2file.txt can be created and written into, if not it prints
         that the file cannot be found*/
            /*asks the user for the amount of money paid to employees in the
            form of salaries and wages for the year*/
         	printf("\nhow much money did you pay out to employees (salaries and wages) this year or up to this point?\t");
         	scanf("%fl",&paytoemp);/*stores variable for the money paid to
            employees that year in memory*/
            //ensure that space and enter are not regonized as variables
      		fflush(stdin);
            /*calculates the amount of medicare, which is a percentage of the
            amount paid to employees in the form of salaries*/
      		medi = ((3.25/100)*paytoemp);
            /*calcuates the amount of social security benefits which the company
              paid form the salaries paid to employees*/
      		soci = ((1.54/100)*paytoemp);
            /*calcualtes the percent of tax which will be paid by revenue*/
      		star2 = ((star/100)*paytoemp);
            /*prints to screen a statement followed by the amount paid and
            received in the year*/
      		printf("\n\nThe total amount you recieved/paid this year is:\t%.2ld\n", compute1);
            /*prints to screen  a statement followed by the amount of tax paid
             on its own for th eyear*/
      		printf("The total total amount of tax you paid (on its own) this year is:\t%.2ld\n",compute2);
            /*prints to screen a statement followed by the percent of tax
            deducted from items sold or bought in the year*/
         	printf("The total percent of tax deducted from items sold or bought this year is:\t%.2f\n\n", star);
            /*prints to screen a statement followed by the total percent of
             tax paid by revenue*/
      		printf("The total percent of tax which will be paid by your revenue is:\t%.2f\n", star2);
            /*prints to screen a statement followed by the amount paid to
            employees for medicare*/
         	printf("The total amount of you must write off as paid for medical care to employees is:\t%.1fl\n\n", medi);
            /*prints to screen a statement followed by the amount paid to
            employees for social security*/
      		printf("The total amount you must write off as paid for social security to employees is:\t%.1fl\n", soci);
            /*asks the user to enter the month*/
            printf("Please enter the month\t");
      		scanf("%d", &month);//stores the varaible for the month
             while(month!= da_mon){/*a while loop which implements if the
             new month entered in this particular point is not the same as
             the one previously entered at the start of the code*/
               /*prints to screen that the wrong entry was entered and that
                the month entered now must be the same as the one entered
                earlier*/
            	printf("\aError! incorrect entry must be same month as entered before\a\a\n");
               /*asks the user to enter the month because the last one was
               not the same as the one entered before*/
               printf("Please enter the month\t");
      			scanf("%d", &month);/*stores the varaible for the month in
               memory, effectively rewriting the previous entry in the
               variable*/
            	fflush(stdin);/*ensure that space and enter are not regonized
                as variables*/
            }//end of while loop
            //prints to screen a statement asking the user to enter the day
            printf("\nPlease enter the day\t");
      		scanf("%d",&day);//stores the entry in variable day to memory
            /*ensure that space and enter are not regonized as variables*/
            fflush(stdin);
            /* a while loop which checks if the day entered isnt above 30 for a
            month which has only 30 days and implements once this is so, the
            while loop terminates after the value has been corrected*/
            while(day>30){
					if((((month == 9)&&(month == 4)&&(month == 6)&&(month == 11)))){
               	/*tell the user that the entry is incorrect and that that
                  month has 30 days*/
      				printf("\a\nwrong entry entered, that month has 30 days\n");
                  /*asks the user to enter the day*/
         			printf("Please enter the day \t");
      				scanf("%d",&day);/*stores the varaible for the day in memory,
                   effectively rewriting the previous entry in the variable*/
            		fflush(stdin);/*ensure that space and enter are not regonized
                   as variables*/
            	}//end of if statement
				}//end of while loop
            while(day>31){/*checks that day isnt above 31, wont terminate until
             correction is made*/
            	//tells the user that the entry was incorrect
            	printf("\aERROr! incorrect entry\n");
               /*asks the user for the day*/
              	printf("Please enter the day\t");
      			scanf("%d",&day);/*stores the entry in day in memory, effectively
                rewriting the previous entry in the variable */
            	fflush(stdin);/*ensure that space and enter are not regonized as
                variables*/
            }//end of while loop
            printf("\nPlease enter the year\t");
      		scanf("%d", &year);
            fflush(stdin);
            while(year!= da_year){/*a while loop which implements if the new
            year entered in this particular point is not the same as the one
            previously entered at the start of the code*/
               /*prints to screen that the wrong entry was entered and that
               the year entered now must be the same as the one entered
               earlier*/
            	printf("ERROR \a!! wrong entry entered must be same year\a\a\n");
               /*asks the user to enter a new year because the one entered
               before was not the same as the year entered earlier*/
            	printf("Please enter the year\t");
      			scanf("%d", &year); /*stores the varaible for the year in
                memory, effectively rewriting the previous entry in the
                variable*/
            	fflush(stdin);/*ensure that space and enter are not regonized
                as variables*/
            }//end of while loop
            /*asks if the user wants to rewrite into a file which may have data
            in it that hasn't been stored permantly*/
            printf(" Are you sure you want to rewrite over this file, if may have");
            printf(" data stored in it that hasn't been stored permnantly, 1 for yes 2 for no");
            scanf("%d",&sure);
            //checks if sure is 1(meaning yes), if so it prints to file
            if(sure==1){
             	/*prints the day, month,year, paytoemp, compute1, compute2,
               star, j, star2, medi, soci in file using the fprintf assignment*/
            	fprintf(kp,"%d %d %d %fl %ld %fl %ld %fl %fl %fl %fl\n", day, month, year, paytoemp, compute1, j, compute2, star, star2, medi, soci);
            	printf("You must save this information in an archive by visiting\n the 3rd");
               printf(" feature on the menu if you dont want it gone the enxt time you run this feature\n\n Please enter any key to return to menu");
         		fclose(kp);/*assignment to close the file funciton2file.txt
                using file pointer kp*/
            }//end of if statement

         }else{/*if the file function2file.txt cannot be created and written
         into it prints the else portion of that if statement*/
         	/*prints to the screen that the file funciton2file.txt could not
            be found, meaning it could not be created or written into*/
         	printf("ERROR FILE NOT FOUND");
      	}//end of if statement
      }else{/*if the month is in fact over 11 then it will implement the else
      portion*/
      		/*prints to the screen that the month is above 11 and thus the
            due date for tax statements has passed.*/
      		printf("\a\a\a\nthe deadline for tax statements had passed!\n");
            printf("Please send an enquiry to the government explaining\n why");
            printf(" you could not submit them in time. Pres any key to contuine");
   	}//end of if statement
      getche();/*function to terminate function after the user entered any key*/
clrscr();//function to clear the screen of all previous entries printed.
}//end of function getandcompute

void storeindisk(){/*start of function storeindisk which allows the user
to store the entries calculated in the function2 file in memory before
those entries are wirrten over*/
int archdate;/*delcares a integer called archdate which will be used to
accept the year above which the user wants to sotre transactions*/
FILE *jp;/*declarations of file pointer called jp which will be used to
open function2file.txt to read*/
FILE *fp;/*delcaration of file pointer fp which will be used to read from
 and open archive-function3.txt*/
int year2, day2, month2;/*declaration of 3 integers caled year2, day2,
month2 which will be used to store the varialbes of the date form
 function2file.txt*/
float paytoemp2;//declaration of float paytoemp
long compute1b;//declaration of long compute1b
long compute2b;//delcaration of long compute2b
float starb;//delaration of float starb
float star2b;//declaration of float starb
float medib;//delcaration of float medib
float socib;//declaration of float socib
float j2;//declaration of float j2


	printf("you want to store all entries over which date? please enter the");
   printf(" year. \a\a\n\n Note it makes sense to store things entered in the same date as feature 2\t");
   scanf("%d",&archdate);//stores archdate in memory
   if(jp == fopen("function2file.txt","r")){/* checks if funciton2file.txt exsists and can
   open*/
   	while(!feof(jp)){/*start of end of file while loop which terminates
   	if the iteration has reached the end of the file which in memory using
		the file pointer fp*/
   		/*scans form file the day, month, year, paytoemp, compute1, j,
         compute2, star, star2, medi, soci and stores them in different
         variables than those used in function2*/
  	 		fscanf(jp,"%d %d %d %fl %ld %fl %ld %fl %fl %fl %fl\n", &day2, &month2, &year2, &paytoemp2, &compute1b, &j2, &compute2b, &starb, &star2b, &medib, &socib);
         if(year2>=archdate){/*if statement checking is the year in file
         is less than or equal to the year that the user wanted tax statement
         above to be stored*/
   			if(fp = fopen("archive-function3.txt","a")){/*checks if
            archive-function3.txt file can be created and if so appends to
            it several variables*/
            	/*prints to file using fprintf the entries read from file
               earlier and while not at the end of file also prints that
               the transactions were stored in file*/
         		fprintf(fp,"%d %d %d %fl %ld %fl %ld %fl %fl %fl %fl\n", day2, month2, year2, paytoemp2, compute1b, j2, compute2b, starb, star2b, medib, socib);
               /*prints to screen that the transactions form function2 file
               have not been correctly stored in a file for permanant storage*/
               printf("These tranactions have been stored in file");
   			}else{/*start of else statement which conditions that if the file
            "archive-function3.txt cannot be created not found must be printed
             on the screen*/
        	   	printf("not found!!");
      		}//end of if statement
            fclose(fp);/*assignment to close file archive-function3.txt using
            file pointer fp*/
        	}//end of if statement
        	if(year2<archdate){
      		printf("not necessary");
   		}//end of if statement
  		 }//end of while loop
   }else{
      printf("Not necessary");
   }
   fclose(jp); //assignment to close file function2file using file pointer jp

}//end of function


void allocateforitemandtax(){/*start of function allocateforitemandtax which
reads entries in taxfile2.txt and puts them in different files according to
the amount of the itemprice */
float bop;/*creates a float called bop*/
FILE *fp;/*creates a file pointer in memory called fp which can be used to
open, write, read, append and close a file in storage*/
FILE *jp;/*creates a file pointer in memory called jp which can be used to
 open, write, read, append and close a file in storage*/
FILE *kp;/*creates a file pointer in memory called kp which can be used to
 open, write, read, append and close a file in storage*/
FILE *sp;/*creates a file pointer in memory called sp which can be used to
open, write, read, append and close a file in storage*/
FILE *zp;/*creates a file pointer in memory called zp which can be used to
 open, write, read, append and close a file in storage*/
FILE *yp;/*creates a file pointer in memory called yp which can be used to
open, write, read, append and close a file in storage*/
int day3, month3,  year3;/*creates 3 integers called day3, month3 and year3
which will be used to store the varaibles of the date that was in the
taxfile2.txt*/
float taxc2, itmprc2, taxc;/*creates 3 floats called taxc, itmprc2 and
taxc which will be used to store the itemprice, tax percent and tax amount
 that was read from taxfile2.txt*/
char taxtyp2[15];/*creates 15 bit string which will be used to store the
taxtyp which will be read form taxfile2.txt*/


   /*an if statement to check if taxfile2.txt truly exsists, if not it will
    return nothing and the function
    will terminate. if so it will enter a while loop to read form file and
    store the things read into other files based on the amount*/
	if(fp = fopen("taxfile2.txt","r")){
   	while(!feof(fp)){/*a while loop that terminates if the iteration has
      reached the end of the file which in memory using the file pointer fp*/
         /*scanf all entries from taxfile2.txt into several varialbes*/
         fscanf(fp,"%d %d %d %s %fl %fl\n", &day3, &month3, &year3, &taxtyp2[0], &itmprc2, &taxc);
         bop = (itmprc2+bop);/*computes a arithmetic operation called bop
         which counts the amount of item prices entered.*/

         	if((itmprc2>=0)&&(itmprc2<=500)){/*if statement to check if itmprc
             is above or equal to 0 and yet less than or equal to 500,
            if so it stores(appends) the itmprc2, taxc2 and taxtyp2 in a file
            called function4-filea.txt and closes that file*/
               /*opens and creates the file function4-filea.txt using file
               pointer*/
               jp = fopen("function4-filea.txt","a");
               /*prints itmprc2, taxc2 and taxtyp2 to the file
               function4-filea.txt*/
               fprintf(jp,"%fl %fl %s\n",itmprc2, taxc2, taxtyp2);
               fclose(jp);/*assignment to close file function4-filea.txt
                using the file pointer jp*/
        		 }//end of if statement

         	if((itmprc2>=501)&&(itmprc2<=5000)){/*if statement to check if
            itmprc is above or equal to 501 and yet less than or equal to 5000,
            if so it stores(appends) the itmprc2, taxc2 and taxtyp2 in a
            file called function4-fileb.txt and closes that file*/
            	kp = fopen("function4-fileb.txt","a");/*opens and creates
               the file function4-fileb.txt using file pointer*/
               /*prints itmprc2, taxc2 and taxtyp2 to file function4-fileb.txt*/
               fprintf(kp,"%fl %fl %s\n",itmprc2, taxc2, taxtyp2);
               fclose(kp);/*assignment to close file function4-fileb.txt
                using the file pointer kp*/
         	}//end of if statement

         	if((itmprc2>=5001)&&(itmprc2<=50000)){/*if statement to check
            if itmprc is above or equal to 5001 and yet less than or equal
             to 50000,
            if so it stores(appends) the itmprc2, taxc2 and taxtyp2 in a
            file called function4-filec.txt and closes that file*/
               sp = fopen("function4-filec.txt","a");/*opens and creates
               the file function4-filec.txt using file pointer*/
               /*prints itmprc2, taxc2 and taxtyp2 to file function4-filec.txt*/
               fprintf(sp,"%fl %fl %s\n",itmprc2, taxc2, taxtyp2);
               fclose(sp);/*assignment to close file function4-filec.txt
                using the file pointer sp*/
         	}//end of is statement

         	if((itmprc2>=50001)&&(itmprc2<=1000000)){/*if statement to
            check if itmprc is above or equal to 50001 and yet less than
            or equal to 1000000,
            if so it stores(appends) the itmprc2, taxc2 and taxtyp2 in a
            file called function4-filed.txt and closes that file*/
            	zp = fopen("function4-filed.txt","a");/*opens and creates
               the file function4-filed.txt using file pointer*/
               /*prints itmprc2, taxc2 and taxtyp2 to file function4-filed.txt*/
               fprintf(zp,"%fl %fl %s\n",itmprc2, taxc2, taxtyp2);
               fclose(zp);/*assignment to close file function4-filed.txt
               using the file pointer zp*/
         		/*put itmprc2, taxc2, taxtyp2 in file d*/
        		 }//end of if statement
         	if(itmprc2>=1000001){/*if statement to check if itmprc is above
            or equal to 1000001,
            if so it stores(appends) the itmprc2, taxc2 and taxtyp2 in a
            file called function4-filee and closes that file*/
               /*opens and creates the file function4-filee.txt using file
               pointer*/
            	yp = fopen("function4-filee.txt","a");
               /*prints itmprc2, taxc2 and taxtyp2 to file function4-filee.txt*/
               fprintf(yp,"%fl %fl %s\n",itmprc2, taxc2, taxtyp2);
               fclose(yp);/*assignment to close file function4-filee.txt
               using file pointer yp*/
               /*put itmprc2,taxc2, taxtyp2 in file named e*/
            }//end of if statement
      }//end of while loop
      fclose(fp);//assignment to close taxfile2.txt using file pointer fp
      /*prints the amount of item prices accumulated over the period so far*/
      printf("the total amount you bought or sold and calculated taxes");
      printf(" on is:\t %fl", bop);

	}//end of if statement

}//end of function allocateforitemandtax

void allocatefortax(){/*start of function allocatefortax which reads form
taxfilenew and allocates its entries according the the amount of the tax amount*/
float bop2; //creates a float called bop
FILE *fp;/*creates a file pointer in memory called fp which can be used to
open, write, read, append and close a file in storage*/
FILE *jp;/*creates a file pointer in memory called jp which can be used to
 open, write, read, append and close a file in storage*/
FILE *kp;/*creates a file pointer in memory called kp which can be used to
 open, write, read, append and close a file in storage*/
FILE *sp;/*creates a file pointer in memory called sp which can be used to
open, write, read, append and close a file in storage*/
FILE *zp;/*creates a file pointer in memory called zp which can be used to
open, write, read, append and close a file in storage*/
FILE *yp;/*creates a file pointer in memory called yp which can be used to
 open, write, read, append and close a file in storage*/
int day3, month3,  year3; /*creates 3 integers called day3, month3 and year3
which will be used to store the varaibles of the date that was in the
taxfilenew.txt*/
float tax2;/*creates a float to store the value of the tax amout which is
retrieved form file so it cna be used in function*/
char taxtype2[15];/*creates 15 bit string which will be used to store the
tax type which will be read form taxfilenew.txt*/


   /*an if statement to check if taxfilenew.txt truly exsists, if not it
    will return nothing and the function
    will terminate. if so it will enter a while loop to read form file and
     store the things read into other files based on the amount*/
	if(fp = fopen("taxfilenew.txt","r")){
      /*a while loop that terminates if the iteration has
      reached the end of the file which in memory using the file pointer fp*/
   	while(!feof(fp)){
      	/*scanf all entries from taxfilenew.txt into several varialbes*/
         fscanf(fp,"%d %d %d %s %fl\n", &day3, &month3, &year3, &taxtype2[0], &tax2);
         bop2 = (tax2+bop2);/*calculates the amount of tax paid over the period
          by adding each amount while not at the end of file*/
             /*if statement to check if tax2 is above or equal to 0 and yet
             less than or equal to 500,
            if so it stores(appends) the tax2 and taxtype2 in a file called
            function5-filea.txt and closes that file*/
         	if((tax2>=0)&&(tax2<=500)){
               /*opens and created the file function5-filea.txt using file
               pointer*/
               jp = fopen("function5-filea.txt","a");
               //prints tax2 and taxtype2 to file function5-filea.txt
               fprintf(jp,"%fl %s\n",tax2, taxtype2);
               fclose(jp);/*assignment to close file function5-filea.txt
                using file pointer jp*/
         		/*put tax2, taxtype2 in file a*/
        		 }//end of if statement

             /*if statement to check if tax2 is above or equal to 501 and
              yet less than or equal to 5000,
            if so it stores(appends) the tax2 and taxtype2 in a file called
            function5-fileb.txt and closes that file*/
         	if((tax2>=501)&&(tax2<=5000)){
            	kp = fopen("function5-fileb.txt","a");/*opens and creates the
               file function5-fileb.txt using file pointer*/
               //prints tax2 and taxtype2 to file function5-fileb.txt
               fprintf(kp,"%fl %s\n",tax2, taxtype2);
               fclose(kp); /*assignment to close file function5-fileb.txt
               using file pointer kp*/
         		/*put tax2, taxtype2 in file b*/
         	}//end of if statement

             /*if statement to check if tax2 is above or equal to 5001 and
             yet less than or equal to 50000,
            if so it stores(appends) the tax2 and taxtype2 in a file called
            function5-filec.txt and closes that file*/
         	if((tax2>=5001)&&(tax2<=50000)){
               sp = fopen("function5-filec.txt","a");/*opens and creates file
                function5-filec.txt  using file pointer*/
               //prints tax2 and taxtype2 to file function5-filec.txt
               fprintf(sp,"%fl %s\n",tax2, taxtype2);
               fclose(sp);/*assignment to close file function5-filec.txt using
                file pointer sp*/
         		/*put tax2, taxtype2 in file c*/
         	}//end of if statement

              /*if statement to check if tax2 is above or equal to 50001 and
               yet less than or equal to 1000000,
            	if so it stores(appends) the tax2 and taxtype2 in a file called f
          		unction5-filed.txt and closes that file*/
         	if((tax2>=50001)&&(tax2<=1000000)){
               //opens and creates file function5-filed.txt using file pointer
            	zp = fopen("function5-filed.txt","a");
               //prints tax2 and taxtype2 to file function5-filed.txt
               fprintf(zp,"%fl %s\n",tax2, taxtype2);
               /*assignment to close file function5-filed.txt using file pointer
                zp*/
               fclose(zp);
         		/*put tax2, taxtype2 in file d*/
        		 }//end of if statement

              /*if statement to check if tax2 is above or equal to 1000001
            if so it stores(appends) the tax2 and taxtype2 in a file called
            function5-filee.txt and closes that file*/
         	if(tax2>=1000001){
               //opens and creates file function-filee.txt using file pointer
            	yp = fopen("function5-filee.txt","a");
               //prints tax2 and taxtype2 to file function5-filee.txt
               fprintf(yp,"%fl %s\n", tax2, taxtype2);
               fclose(yp);/*assignment to close file function5-filee.txt using
                file pointer yp*/
              /*put tax2, taxtype2 in file e*/
            }//end of if statement
      }//end of while loop
      fclose(fp);//assignment to close the file using the file pointer
      /*prints out the amount of tax paid over the period onto the screen
      formatted*/
      printf("the total amount you bought or sold and calculated taxes on");
      printf(" is:\t %fl", bop2);

	}//end of if statement

}//end of function allocatefortax


