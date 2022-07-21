/* the program to find the tyoe of the numbers
    * Prime numbmers
    * Even nummbers
    * odd numbers 
    * Fibonacci series
    * Palindrome number
    * Armstrong numbers
*/

#include <stdio.h>
#include <stdlib.h>

int Primenumbers();
int Evennumbers();
int Oddnumbers();
int Fibonacci();
int Palindrome();
int Armstrong();


int main(){
    int choice;
    printf("\n\t\t\t\tWELCOME TO THE NUMBER ZONE!");
    printf("\n\n\t\t1. Prime Numbers\t\t\t\t2. Even numbers");
    printf("\n\n\t\t3. Odd Numbers  \t\t\t\t4. Fibonacci series");
    printf("\n\n\t\t5. Palindrome Numbers\t\t\t\t6. Armstrong numbers");
    printf("\n\nEnter your choice [1 - 6]: ");
    scanf("%d", &choice);

    switch(choice){
        
        case 1:
        	system("cls");
            Primenumbers();
            break;

        case 2:
       	    system("cls");
            Evennumbers();
            break;
        
        case 3:
            system("cls");
            Oddnumbers();
            break;

        case 4:
            system("cls");
            Fibonacci();
            break;
        
        case 5:
            system("cls");
            Palindrome();
            break;
        
        case 6:
            system("cls");
            Armstrong();
            break;

        default:
            printf("\n\n\a Ooops, Input invalid\vEnter your choice in correct format!!!");
            getch();
            system("cls");
            main();
        
    }
   return 0;
}



int Primenumbers() {

    int count, stop, i;
    do{
        printf("\nEnter the start : ");
        scanf("%d", &count );
        printf("Enter the end : ");
        scanf("%d", &stop);
    }while((count < 0 || stop < 0) && (stop >= count));
    
    printf("Prime numbers from %d to %d:\n", count, stop);

    for(i = count ; i <= stop; i++){
        
        if(i >= 1 && i <= 3){
           printf("\t%d\n", i);
        }
           
        if(i !=1 && i % 2 != 0 && i % 3 != 0){
            printf("\t%d\n", i);
        }    
    }
  
}

int Oddnumbers(){
    int count, stop, i;
    do{
        printf("\nEnter the start : ");
        scanf("%d", &count );
        printf("Enter the end : ");
        scanf("%d", &stop);
    }while((count < 0 || stop < 0)&& (stop >= count));
    
    printf("Odd numbers from %d to %d:\n", count, stop);

    for(i = count ; i <= stop; i++){
           
        if(i % 2 != 0 ){
            printf("\t%d\n", i);
        }    
    }
	
}

int Evennumbers(){
	int count, stop, i;
    do{
        printf("\nEnter the start : ");
        scanf("%d", &count );
        printf("Enter the end : ");
        scanf("%d", &stop);
    }while((count < 0 || stop < 0) && (stop>= count));
    
    printf("\nEven number from %d to %d:\n", count, stop);

    for(i = count ; i <= stop; i++){
           
        if(i % 2 == 0 ){
            printf("\t%d\n", i);
        }    
    }
    
}

int Fibonacci(){
    //0 1 1 2 3 5;
    int terms, i;

    do{
    printf("\nEnter the number of terms: ");
    scanf("%d", &terms);
    }while(terms <= 0);

    printf("%d\n", 0);
    for(i = 1; i < terms; i++ ){
        int x = 0, y = 1, z;
        z = x + y;
        printf("%d\n", z);
        x = y;
        y = z;
    }

}

int Palindrome(){
    // get an input from the user if it is the same no provided the digits are reversed then declare it palindrome.

    int num, rem, temp ;   //two vaiables are defined for the input so the other can be used for checking while the one is overwritten in while loop.

    int rev = 0;
      
    printf("\nEnter number: ");
    scanf("%d", &num);  
	
	temp = num;  	 

    while(num != 0){
        rem = num % 10;
        rev = rev * 10 + rem;
        num = num / 10;
    }
	
    if(rev == temp){
        printf("%d is a Plaindrome number.", temp);
    }
    else {
        printf("%d is not a Palindrome number", temp);
    }
    

}

int Armstrong(){
    //prompt user for an input say xyz if xyz = x^3 + y^3 + z^3 then declare ti as armstrong number;
    //two vaiables num and temp are defined for the input so the other can be used for checking while the one is overwritten in while loop.
    int num, rem, temp ;  
    int rev = 0;
      
    printf("\nEnter number: ");
    scanf("%d", &num);  
	
	temp = num;  	 

    while(num != 0){
        rem = num % 10;
        rev = rev + (rem * rem * rem);
        num = num / 10;
    }
	
    if(rev == temp){
        printf("%d is an Armstrong number.", temp);
    }
    else {
        printf("%d is not an Armstrong number", temp);
    }

 }

}



