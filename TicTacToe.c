#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


//global varible declaration
int  player, count = 0, sign, winner, choice ;

//function prototype
void game();
void status();
void manual();

int main(){
    
	printf("\n\n\n\n");
    printf("\t\t\t\t\t\t****   TIC TAC-TOE   ****");
    printf("\n\n\n\t\t\t\t PLayer Options: ");
    printf("\n\n\n\t\t\t\t\t  1. 2-player\t\t 2. Computer");
	printf("\n\n\n\t\t\t\t\t  3. Manual  \t\t 4. Exit");
    printf("\n\n\n\t\t\t\t Enter your choice: ");
    scanf("%d", &choice);    
   
    switch(choice){

        case 1:
        	system("cls");
            game();
            break;

        case 2:
			system("cls");
			game();     
            break;
        
        case 3: 
        	system("cls");
        	manual();
        	break;

        case 4: 
        	system("cls");
        	printf("\n\n\n\n\a\t\t\t\tSee you again!!!\n\n\n\n");
        	exit(0);
        
		default:
			printf("\a\n\t\t\t\t Invalid Choice!!!");
			status();
			
    }
    return 0;
}

void game(){
    	
    int co_ord, i, num; 
    char position[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
			
    while(count < 9 && winner != 1){
		system("cls");
		printf("\n\n\n\n");

		if(choice == 1){
			printf("\n\t\t\t\tPLAYER 1 : 'x'\n\t\t\t\tPLAYER 2 : 'O'\n\n\n\n");
		}
		else{
			printf("\n\t\t\t\tPLayer 1 (COMPUTER)  : 'x'\n\t\t\t\tPlayer 2 (HUMAN)     : 'O'\n\n\n\n");
		}

    	printf("\t\t\t\t\t  %c  |  %c  |  %c\n", position[0], position[1], position[2]);
    	printf("\t\t\t\t\t-----+-----+-----\n");
     	printf("\t\t\t\t\t  %c  |  %c  |  %c\n", position[3], position[4], position[5]);
    	printf("\t\t\t\t\t-----+-----+-----\n");   			
    	printf("\t\t\t\t\t  %c  |  %c  |  %c\n", position[6], position[7], position[8]);
    		
		if(count % 2 == 0){
			player = 1;
			sign = 'x';
		} 	
		else{
			player = 2;
			sign = 'O';
		}	
				
		// Input from the computer if the player'c choice is 2, i.e. with computer;
		if(choice == 2){
			if(count % 2 == 0){

				srand(time(NULL)); 
				num = ((rand() % 9) + 1); 		// To generate the number between 1 and 10;
					
				for(i = num - 1; i < 9; i++){
					if(position[i] != 'x' && position[i] != 'O'){
						printf("\n\n\t\t\t\tPLayer 1 [Computer's] move:  " );
						co_ord = i+1;
						printf("%d", co_ord);
						sleep(1);        		//takes second as an parameter.
						break;
					}
					else{
						srand(time(NULL));
						num = ((rand() % 9) + 1); 
					}
				}
			}
			else{
				printf("\n\n\n\n\t\t\t\tYour move Player %d: ", player);
				scanf("%d", &co_ord);
			}
		}
		//Input if the choice of the user is 1 i.e. 2-player
		else {
			printf("\n\n\n\n\t\t\t\tMove for Player %d: ", player);
			scanf("%d", &co_ord);
		}
				
		/*-----< To check the validity of the move	>------*/
		if(co_ord > 9 || co_ord <0){
			printf("\a\n\t\t\t\tInvalid move!!");
			getch();
			continue;
		}
					
		if(position[co_ord - 1] == 'x' || position[co_ord -1] == 'O'){
			printf("\a\n\t\t\t\tALready occupied!!");
			getch();
			continue;
		}
			
		//terminates the program in the middle of the game.
		if(co_ord == 0){
			system("cls");
			printf("\a\n\t\t\t\tGoodbye\n\n!!!");
			exit(0);
		}
				
		//Assign the sign to the position
		position[co_ord - 1]=sign; 
		count ++;
				
		/* ------< LOGIC >-------*/
		
		/*		0		1		2
				3		4		5
				6		7		8
		*/
			
	    /*----------< checks the horizontal >----------*/
		if((position[0]!= 0) && (position[0] == position[1]) && (position[1] == position[2])){
			printf("\a\n\t\t\t\t\tPLAYER %d WON !!!", player);
			winner = 1;
		}
		else if(position[3]!= 0 && (position[3] == position[4]) && (position[4] == position[5])){
			printf("\a\n\t\t\t\t\tPlayer %d won !!!", player);
			winner = 1;
		}
		else if(position[6]!= 0 && (position[6] == position[7]) && (position[7]== position[8])){
			printf("\a\n\t\t\t\t\tPLAYER %d WON !!!", player);
			winner = 1;
		}
			
	    /*-------< checks the vertical >---------*/
		else if(position[0]!= 0 && (position[0] == position[3]) && (position[3] == position[6])){
			printf("\a\n\t\t\t\t\tPLAYER %d WON !!!", player);
			winner = 1;
		}
		else if(position[1]!= 0 && (position[1] == position[4]) && (position[4] == position[7])){
			printf("\a\n\t\t\t\tPLAYER %d WON !!!", player);
			winner = 1;
		}
		else if(position[2]!= 0 && (position[2] == position[5]) && (position[5] == position[8])){
			printf("\a\n\t\t\t\t\tPLAYER %d WON !!!", player);
			winner = 1;
		}
			
		/*-------< checks the diagonal 	>-------*/
		else if(position[0]!= 0 && (position[0] == position[4]) && (position[4] == position[8])){
			printf("\a\n\t\t\t\t\tPLAYER %d WON !!!", player);
			winner = 1;
		}
		else if(position[2]!= 0 && (position[2] == position[4]) && (position[4] == position[6])){
			printf("\a\n\t\t\t\t\tPLAYER %d WON !!!", player);
			winner = 1;
		}
		
	    /*------< checks the match draw >--------*/
		else{
			if(count == 9){
				printf("\a\n\t\t\t\t\t\aMATCH DRAW.\a");
			}
		}
			
	}
	status();
		
}

void status(){
	int status;
	//resetting the variables into initial status.
	winner = 0;
	count = 0;
	choice = 0;
	
	printf("\n\n\t\t\t\t Do you want to continue ?\n");
	printf("\n\t\t\t\t Enter '1' to continue or '0' to quit: ");
	scanf("%d", &status);
		
	if(status == 1){
		system("cls");
		main();
	}
	else{
		system("cls");
		printf("\n\n\t\tSee You Again!!!\n\n");
		exit(0);
	}
		
}
	
void manual(){

	printf("\n\n\n\n\n\t\t\t\t\t |GAME MANUAL| ");
	printf("\n\n\n\t\t\t1. The first player will be given 'x' and the other 'O'.");
	printf("\n\n\t\t\t2. The first to get three in a row, coloumn or diagonal will win.");
	printf("\n\n\t\t\t3. The cell once filled cannot be used twice.");
	printf("\n\n\t\t\t4. Incase you want to quit in the middle of the game enter '0'.");
	printf("\n\n\t\t\t5. Input any other than given parameter may have malfunction."); 
	printf("\n\n\t\t\t   Do it in your own risk !!!");
	printf("\n\n\n\n\n\t\t\tPress any key to go back...");
	getch();
	system("cls");
	main();

 }




         

    
