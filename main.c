/*
Authors: Ayah Sa'fin 
        * A simple C program to manipulate two one dimensional arrays
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100 // Maximun size of array
#define NAMESIZE 50 //Maimum size of a book name
void displayMainMenu(char[][NAMESIZE],int [],double [],int*);        // displays the main menu shown above
void addBook( char [][NAMESIZE], int [], double [], int *);       // adds information for a new book
void removeBook(char [][NAMESIZE],int[],double [],int*);      // removes information of old book
void searchForBook(char [][NAMESIZE],int [],double [],int*);      // searches for a book in the store
void PrintBooks(char [][NAMESIZE],int[],double [],int*);      //display books list
void uploadDataFile(char [][NAMESIZE],int [],double [],int*);         // uploads book data from file
void updateDataFile(char[][NAMESIZE],int [],double [],int*);        // saves book data updates to



int main(){
int i;
int x,bins[MAX_SIZE];
double  price[MAX_SIZE];
char names [MAX_SIZE][NAMESIZE];
x=0; //initiolization for x to know the cuurent size of array
int *size=&x;
printf("uploadin data file...\n");
printf("data file uploaded\n\n\n");
for(i=0;i<MAX_SIZE;i++){
	bins[i]=0;
	price[i]=0;
	}//initialize the array

uploadDataFile(names,bins,price,size);
while(1){
displayMainMenu(names,bins,price,size);

}
printf("updating data file...\n");
printf("data file updated");
return 0;
}

void displayMainMenu(char names [][NAMESIZE],int bins[],double price[], int* size){

printf("please enter your choice:\n");
      printf("1-Add a book:\n");
       printf("2-Remove a book:\n");
       printf("3-search For a book:\n");
       printf("4-Print books list:\n");
       printf("5-exit system:\n");
int choice;
scanf("%d",&choice);
switch (choice){
case 1: addBook(names,bins,price,size);
break;
case 2: removeBook(names,bins,price,size);

break;
case 3: searchForBook(names,bins,price,size);
break;
case 4: PrintBooks(names,bins,price,size);
break;
case 5:
updateDataFile(names,bins,price,size);
exit(0) ;
break ;
default: printf("no such operation please try again\n") ;
break;
}
//getchar();

}        // displays the main menu shown above

void addBook( char names[][NAMESIZE], int bins[], double price[], int *size){
int x,i,j;
float y;
char z[NAMESIZE];

printf("Enter book's name : ");
scanf("%s",names[*size]);
printf("Enter book's bin : ");//ask user to enter book's bin
scanf("%d",&x);
 for (i = 0; i < *size; i++) {//to sort strings
      for (j = 0; j < *size; j++) {
         if (strcmp(names[j - 1], names[j]) > 0) {
            strcpy(z, names[j - 1]);
            strcpy(names[j - 1], names[j]);
            strcpy(names[j], z);
         }
      }
   }
printf("Enter book's price : "); //ask user to enter books price
scanf("%f",&y);



for(i=0;i<*size;i++){

if(bins[i]==x){//to check if element is exist
printf("%d is exist",bins[i]);
if(strcmp(z,names[i])==0){//to check if element is exist
printf("%s is exist\n",names[i]);
return;

}

}
}

int temp1;
double temp2;
char temp3;
bins[*size]=x;
price[*size]=y;
*size+=1;
for (i= 1 ; i <= *size - 1; i++) {
    j = i;

    while ( j > 0 && bins[j] < bins[j-1]) {//to change array element by element
      temp1          = bins[j];
      bins[j]   = bins[j-1];
      bins[j-1] = temp1;

      temp2          = price[j];
      price[j]   = price[j-1];
      price[j-1] = temp2;


    temp3 = names [MAX_SIZE][NAMESIZE];
    names [MAX_SIZE][NAMESIZE]  = names [MAX_SIZE-1][NAMESIZE];
    names [MAX_SIZE-1][NAMESIZE]= temp3;



      j--;
    }

}

return;
}
   // adds information for a new book

void removeBook(char names[][NAMESIZE], int bins[], double price[], int *size){
    int x, i=0, j;

     if (*size == 0){
      printf("List is empty\n");
      }
     else
      {
          printf("Enter element to Remove\n");
          scanf("%d",&x);
          while ((x != bins[i]) && (i<*size)){
            i++;
            }

          if (i == *size)
            printf("Element %d not in list\n",x);
          else
           {
            for (j=i; j<*size; j++){
             bins[j] = bins[j+1];
             price[j]=price[j+1];
             names [MAX_SIZE][NAMESIZE]=names [MAX_SIZE+1][NAMESIZE];
		 }

		    printf("Element %d is removed\n",x);
           *size-=1;

}
}     // removes information of old book
}

void searchForBook(char names[][NAMESIZE], int bins[], double price[], int *size){
int x,i;
    printf("Enter element to search:");
    scanf("%d",&x);
for(i=0;i<*size;i++){

if(bins[i]==x){ //to check if element is exist
printf("%d\n",bins[i]);
printf("%s\n",names[i]);
printf("%f\n",price[i]);

}
else{
printf("Book not found \n");
}
}


}      // searches for a book in store
void PrintBooks(char names[][NAMESIZE], int bins[], double price[], int *size){
   int i;
      printf("Books in List are:\n");
      for (i=0; i<*size;i++){
       printf("books name is %s\t book's bin is %d\tbook's price is %.2f\t\n",names[i],bins[i],price[i]);


       }

}//display books list

void uploadDataFile(char names[][NAMESIZE], int bins[], double price[], int *size){
int temp,i,j;
double temp2;
char temp3;
printf("Book info taken from file \n");
FILE *in = fopen("books.txt","r");
while((fscanf(in,"%s %d %lf",names[*size],&bins[*size],&price[*size]))!=-1){
*size+=1;
	};//read elements from file

for (i= 1 ; i <= *size - 1; i++) {
    j = i;

    while ( j > 0 && bins[j] < bins[j-1]) {
      temp         = bins[j];
      bins[j]   = bins[j-1];
      bins[j-1] = temp;

      temp2          = price[j];
      price[j]   = price[j-1];
      price[j-1] = temp2;


      temp3 = names [MAX_SIZE][NAMESIZE];
     names [MAX_SIZE][NAMESIZE]  = names [MAX_SIZE-1][NAMESIZE];
      names [MAX_SIZE-1][NAMESIZE]= temp3;




      j--;
    }

}


fclose(in);


}         // uploads book data from file

void updateDataFile(char names[][NAMESIZE], int bins[], double price[], int *size){
int i;
printf("Book info file update \n");
FILE * out;
out= fopen("books.txt","w");
for(i=0;i<*size;i++){
fprintf(out,"%d %f %s\n",bins[i],price[i],names[i]);//print updated array in the file
}
fclose(out);

}        // saves book data updates to fill
