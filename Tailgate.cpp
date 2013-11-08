/*Sample progrm to print text on the screen*/

#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<string.h>



//declare a function called menu which takes no parameter and returns a integer
int menu();
int time(void)
{
  struct dostime_t t;

  _dos_gettime(&t);

  printf("The current time is: %2d:%02d:%02d.%02d\n", t.hour, t.minute,
    t.second, t.hsecond);

  return 0;
}
void ingate();
void tracker();
void outgate();
void moneycompute();
void countex();
void archive();
void _dos_gettime(struct dostime_t *timep);


//main function called void main which accepts no parameters is created here
void main()
//opening of void main function
{
	//calls the menu function and places the value of choice in option
   int option=menu();
   //performing a while loop which checks if the chioce entered is less than 6 and more than 0 then implements a certian action
   while(option>0&&option<8){

      //checks if the chioce entered is 1 then prints a statement that delcares option 1 is selected
   	if(option==1){
        	clrscr();/* a function to clear the things printed on screen, meant
         to make the program looks presentable.*/
      	//prints on the screen that Option 1 is selected after using an if statement to check this. it is conditional and will nto appear if Option 1 was not selected
   		printf("Option 1 selected\n");
         tracker();
         //calls back function menu which accepts no parameters into the void main function in which is serves the purpose of allowing the user to enter another option
         option=menu();
		}//if statement ends

      //checks if the choice entered is 2 then prints a statement declaring that option 2 is selected
   	if(option==2){
      	clrscr();/* a function to clear the things printed on screen, meant
         to make the program looks presentable.*/
         //prints on the screen that Option 2 is selected after using an if statement to check this. it is conditional and will not appear if Option 2 was not selected
   		printf("Option 2 selected\n");
         ingate();//start of function void ingate
         //calls back function menu which accepts no parameters into the void main function in which is serves the purpose of allowing the user to enter another option
         option=menu();
   	}//if statement ends

      //a function to check if the choice entered is 3 and  prints a statements declaring option 3 is selected
   	if(option==3){
      	clrscr();/* a function to clear the things printed on screen, meant
         to make the program looks presentable.*/
      	//prints on the screen that Option 3 is selected after using an if statement to check this. it is conditional and will not appear if Option 3 was not selected
      	printf("Option 3 selected\n");
         outgate();
         //calls back function menu which accepts no parameters into the void main function in which is serves the purpose of allowing the user to enter another option
         option=menu();
   	}//if statement ends

      //checks if the choice entered is 4 and prints a statement delcaring that option 4 is selected
   	if(option==4){
         clrscr();/* a function to clear the things printed on screen, meant
         to make the program looks presentable.*/
         //prints on the screen that Option 4 is selected after using an if statement to check this. it is conditional and will not appear if Option 4 was not selected
   		printf("Option 4 selected\n");
         moneycompute();
         //calls back function menu which accepts no parameters into the void main function in which is serves the purpose of allowing the user to enter another option
         option=menu();
   	}//if statement ends

      //checks if the choice entered is 5 and prints a statement declaring that option 5 is selected
   	if(option==5){
        	clrscr();/* a function to clear the things printed on screen, meant
         to make the program looks presentable.*/
      	//prints on the screen 'thanks for using' after an if statement is used to check if option 5 was selected. It will only appear if option 5 is selected
      	printf("Option 5 is selected\n");
         countex();
         //calls back function menu which accepts no parameters into the void main function in which is serves the purpose of allowing the user to enter another option
         option=menu();
      }
      if(option==6){
        	clrscr();/* a function to clear the things printed on screen, meant
         to make the program looks presentable.*/
      	//prints on the screen 'thanks for using' after an if statement is used to check if option 5 was selected. It will only appear if option 5 is selected
      	printf("Option 6 is selected\n");
         archive();
         //calls back function menu which accepts no parameters into the void main function in which is serves the purpose of allowing the user to enter another option
         option=menu();
      }
      if(option==7){
      	clrscr();/* a function to clear the things printed on screen, meant
         to make the program looks presentable.*/
         printf("\nThanks for using\n");
         //this call terminated the program after 10 seconds and is used when option 5 is selected and after thanks for using is printed on the screen
         sleep(10);
         //calls back function named menu, however option 6 does not exsist in menu so it terminates
         option=8;
   	}//if statement ends
   }//while statement ends

}//void main ends

int menu(){
	//creating a integer to named chioce to alow the user to choose one of the items in the menu, from 1 to 5
   int choice;
   //prints on the screen inside the function menu(); 'school manager module'
	printf("\n\t Carpark Manager Module");
   //prints a series of symbols on the screen after it prints school manger module, this is done inside the funciton menu();
   printf("\n\t===============================");
   //prints an option in the option menu inside the function menu();
   printf("\n           1. Check number of cars in lot           ");
   //prints an option in the option menu inside the function menu();
   printf("\n           2. Accept transaction at in gate         ");
   //prints an option in the option menu inside the function menu();
   printf("\n           3. Track car leaving carpark   			  ");
   //prints an option in the option menu inside the function menu();
   printf("\n           4. Compute money at out gate   	         ");
   //prints an option in the option menu inside the function menu();
   printf("\n           5. Accept and store money from outgate    ");
   //tells the user to input one of the options shown above inside the function menu();
    printf("\n          6. Archive files						      ");
   //prints an option in the option menu inside the function menu();
   printf("\n		 	7. Exit program									 ");
   printf("\n\n        Enter Options           ");
   //scans and inputs in computer one of the options above if it a numerical one
   scanf("%d",&choice);
   //call to enable choice to be returned
   return choice;
}
void tracker(){ //start of function tracker to track number of cars in the lot
//declare a file pointer called jp
FILE *jp;//declaration of assignment of file pointer
FILE *fp;//declaration of assignment of file pointer
int newentry, netamount, x;//declares 3 integers called newentry, netamount and x
int carin, carout;//declares 2 integers called carin and carout
	if(jp == fopen("outgate.txt","r")){//*operation to open the file
         /*a while loop that terminates if the iteration has reached the
         end of the file which in memory using the file pointer jp*/
   		while(!feof(jp)){
            		//scanf all entries from file
            		fscanf(jp,"%d %d\n", &carin, &carout);
         }//end of the while loop
         fclose(jp);
   }else{/*if file cant be read from it prints that it was nt found or
          was unreadable*/
         	printf("\a\a\a FILE NOT FOUND or...Unreadble file\n");
            //print statement to screen
   			printf("\n\aNo cars in carpark at the moment ");
         	// whatever is in newentry is reverted to null
         	newentry = 0;
         	//assigning x to newentry
         	x = newentry;
         	//opening file using file pointer
         	fp = fopen("tracker.txt","a");
         	//printing x into the file
         	fprintf(fp,"%d\n",x);
         	//function to close the file
        		 fclose(fp);
            printf("\a\a file created");
   }//end of if statement
   if((carin == 0)&&(carout == 0)){//checks that a netry exists for carin and carout in the file
         //print statement to screen
   		printf("\n\aNo cars in carpark at the moment ");
         // whatever is in newentry is reverted to null
         newentry = 0;
         //assigning x to newentry
         x = newentry;
         //opening file using file pointer
         fp = fopen("tracker.txt","a");
         //printing x into the file
         fprintf(fp,"%d\n",x);
         //function to close the file
         fclose(fp);
   }else{//else statement for if, if first requirement is not met it comes to else portion
        //computing for netamount to arrive at the number of cars in the carpark at the moment,
        netamount = (carin-carout);
        //computing for newentry
        newentry = (500-netamount);
        //start of if statement to see if newentry is 0
        if(newentry == 0){
            //prints statement to screen
        		printf(" Gate must be closed");
        }//end of if statement
        x = newentry;
        //opening file using file pointer
        fp = fopen("tracker.txt","a");
        //printing variable x to file,
        fprintf(fp,"%d\n",x);
        //assignment to close the file
        fclose(fp);
   }//end of if statement
}//end of function tracker
void ingate(){//start of new function void ingate
FILE *jp;//declaration of assignment of file pointer
FILE *fp;//declaration of assignment of file pointer
int min, money, x;//declaration of integer named min, x, money and idnum
int gateopen, carin, gateclose;//delcaration of gateopen, gateclose and carin
float hour, idnum;//declaration of hour float
	if(jp == fopen("tracker.txt","r")){//*operation to open the file
         /*a while loop that terminates if the iteration has reached the
         end of the file which in memory using the file pointer jp*/
   		while(!feof(jp)){
            		//scanf all entries from file
            		fscanf(jp,"%d\n", &x);
         }//end of the while loop
         fclose(jp);//assignment to  close file using file pointer jp
   		if(x>0){
   			printf("Please give your money\n");
     			 scanf("%d",&money);
      		printf("Please enter car ID\n");
      		scanf("%f",&idnum);
      		gateopen = (gateopen+1);
      		gateclose = (gateclose+1);
      		carin = (carin+1);

            struct dostime_t t;
            _dos_gettime(&t);

      		//opening file using file pointer
      		fp = fopen("ingate.txt","a");
      		//printing variable x to file,
      		fprintf(fp,"%d %d %d %f %d %d %d\n",t.hour, t.minute, money, idnum, gateopen, gateclose, carin);
      		//assignment to close the file
      		fclose(fp);
          }else{
          	printf(" Car park if full please don't open gate until space is available\n");
          }
   }else{//else statement for if, if first requirement is not met it comes to else portion
   	printf("\n\t\tFILE NOT FOUND!!!\a\a\a");
   }//end of if statement
   fclose(jp);
}
void outgate(){
int carin, netamount, carout, min;
char outgatename[50];
FILE *fp;
float hour;
int gateopen;
int gateclose;
float idnum;//declaration of hour float
	printf("\nPlease enter the ticket: car idnumber");
   scanf("%f",&idnum);
   printf("\nPlease enter name of exit gate\t");
   scanf("%s",outgatename[0]);
   fflush(stdin);//ensures space isnt accepted as a variable*/
         int r = strlen(outgatename);/*checks if there is actually
         something inside the stirng entered, if not it asks the user to enter
         the stirng again.*/
      	while(r == 0){/*start of while loop qhich implements if the lenth of
         the stirng is 0*/
         	printf("\nImpossible assignment, must be a string\a\n");/*prints
            error to screen*/
     	   	printf("\n Please enter the amount of the tax you are storing\t");/*
            asks user to enter a string*/
      		scanf("%fl",&outgatename[0]);/*stores new entry in memory,
            overwriting the previous one*/
      		fflush(stdin);//ensures that space is not accepted as a variable
         }//end of while loop
   gateopen = (gateopen+1);
	gateclose = (gateclose+1);
	carin = (carin+1);
   carout = (carout+1);
   netamount = (netamount+1);
   printf("Please enter the hour of the day(in hundred hours)\t  and the minute");
   scanf("%f",&hour);
   scanf("%d",&min);
   //opening file using file pointer
   fp = fopen("outgate.txt","w");
   //printing variable x to file,
   fprintf(fp,"%f %s %f %d %d %d %d %d %d\n",idnum, outgatename, hour, min, gateopen, gateclose, carin, carout, netamount);
   //assignment to close the file
   fclose(fp);

}
void moneycompute(){
int carin, netamount, carout, min;
int amount2pay;
char outgatename[50];
FILE *fp;
FILE *jp;
float hour, idnum;//declaration of hour float
int carin2, netamount2, carout2, min2;
char outgatename2[50];
int gateopen2;
int gateclose2;
float nettime;
float hour2, idnum2;
	printf("\nPlease enter the ticket: car idnumber");
   scanf("%f",&idnum);
   printf("\nPlease enter name of exit gate\t");
   scanf("%s",outgatename[0]);
   printf("Please enter the hour of the day(in hundred hours)\t  and the minute");
   scanf("%f",&hour);
   scanf("%d",&min);
   fflush(stdin);//ensures space isnt accepted as a variable*/
   int r = strlen(outgatename);/*checks if there is actually
   something inside the stirng entered, if not it asks the user to enter
   the stirng again.*/
   while(r == 0){/*start of while loop qhich implements if the lenth of
   the stirng is 0*/
   	printf("\nImpossible assignment, must be a string\a\n");/*prints
      error to screen*/
      printf("\n Please enter the amount of the tax you are storing\t");/*
      asks user to enter a string*/
      scanf("%fl",&outgatename[0]);/*stores new entry in memory,
      overwriting the previous one*/
      fflush(stdin);//ensures that space is not accepted as a variable
   }//end of while loop
   if(fp == fopen("outgate.txt","r")){//*operation to open the file
         /*a while loop that terminates if the iteration has reached the
         end of the file which in memory using the file pointer fp*/
   		while(!feof(fp)){
            		//scanf all entries from file
                 fscanf(fp,"%f %s %f %d %d %d %d %d %d\n",&idnum2, &outgatename2, &hour2, &min2, &gateopen2, &gateclose2, &carin2, &carout2, &netamount2);
          			nettime = (hour2-hour);
                  amount2pay = ((nettime/100)*100);

         }
   }else{
   	printf("FILE NOT FOUNd!!!\a\a\a\a\a\a\a");
   }
   fclose(fp);
   jp = fopen("moneycompute.txt","w");
   //printing variable x to file,
   fprintf(jp,"\n %d %d",amount2pay,nettime);
   //assignment to close the file
   fclose(jp);
}
void countex(){
FILE *fp;
FILE *jp;
int amount2pay, nettime, gateopen, gateclose;
   if(fp == fopen("moneycompute.txt","r")){
   	while(!feof(fp)){
      	fscanf(fp,"%d %d",&amount2pay, &nettime);
      }
   }else{
   	printf("ERROR!!!, File not found");
   }
	printf(" Please cash the amount\t %d", amount2pay);
   printf("\nOpen gate");
   gateopen = (gateopen+1);
   printf("\n Close gate");
	gateclose = (gateclose+1);
   jp = fopen("countex.txt","w");
   //printing variable x to file,
   fprintf(jp,"\n %d %d %d %d",amount2pay,nettime, gateopen, gateclose);
   //assignment to close the file
   fclose(jp);
}
void archive(){
FILE *fp;
FILE *jp;
FILE *np;
int carin, netamount, gateopen, gateclose, carout, min;
int amount2pay;
char outgatename[50];
float hour, idnum;//declaration of hour float
int carin2, netamount2, carout2, min2;
char outgatename2[50];                          
int gateopen2;
int gateclose2, money;
float nettime;
float hour2, idnum2;
if(fp == fopen("ingate.txt","r")){//*operation to open the file
         /*a while loop that terminates if the iteration has reached the
         end of the file which in memory using the file pointer jp*/
   		while(!feof(np)){
            		//scanf all entries from file
                 fscanf(fp,"%f %s %f %d %d %d %d %d %d\n",&idnum2, &outgatename2, &hour2, &min2, &gateopen2, &gateclose2, &carin2, &carout2, &netamount2);
                 nettime = (hour2-hour);
                 amount2pay = ((nettime/100)*100);
                  fp = fopen("ingate.txt","r");
                  while(!feof(np)){
                 			fscanf(fp,"%f %d %d %f %d %d %d\n",&hour, &min, &money, &idnum, &gateopen, &gateclose, &carin);
      						//assignment to close the file
                  }
                 jp = fopen("archive.txt","a");
   				//printing variable x to file,
   				fprintf(jp,"%f %s:%f %d %d %d %d %d %d %f - %f %d\n",idnum, outgatename, hour, min, gateopen, gateclose, carin, carout, netamount, nettime, amount2pay);
   				//assignment to close the file
   				fclose(jp);

         }
   }else{
   	printf("FILE NOT FOUNd!!!\a\a\a\a\a\a\a");
   }
   fclose(fp);
}














