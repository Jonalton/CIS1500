/**************************judehamiltonJonaltonA2.c*******************************
Student Name: Jonalton Jude Hamilton                            Email ID: jjudeham
Date: November 9th, 2018                                         Course Name: CIS 1500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity.
2) I have completed the Computing with Integrity Tutorial on Moodle.
3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all
material (data, images, ideas, or words) that I have used, wheether directly quoted
or paraphased. Furthermore, I certify that this assignment was prepared by me
specifically for this course.
***********************************************************************************/


/*********************************************************************************
                Compiling the program
 *********************************************************************************
 The program should be compiled using the following flags:
 -std=c99
 -Wall
 compiling: gcc judehamiltonJonaltonA2.c -std=c99 -Wall -o judehamiltonJonaltonA2
 *********************************************************************************
                        Running the program
 *********************************************************************************
 running:       ./judehamiltonJonaltonA2
 **********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


#define MAX_QUESTIONS 7
//initialize all prototypes
void promptPlayerForName(char nameForGame[50]);
void printWelcomeMessage(char nameForGame[50]);
void popUpCurrentQuestion4choices(int currentAwardAmount);
void popUpCurrentQuestion2choices(int currentAwardAmount);
void generateRandomGreeting(char greet[20]);
int calculateCurrentAward(int questionNumber, int awardPreviousQuestion);
int calculateReducedAward(int questionNumber, int currentAwardAmount);
char askPlayerForLifeLine(void);
char acceptPlayersFinalAnswer(void);
bool isCorrectFinalAnswer(char finalAnswer, int questionNumber, char allCorrectAnswers[MAX_QUESTIONS]);

int main(){
	
	char allCorrectAnswers [MAX_QUESTIONS + 1] = "CBCBACA";   // for my set of questions
	char greet [20];
	char nameForGame[50];
	int lifeLineUsed = 0; 
	int questionNumber = 1;
	char playersResponseLifeLine;
	char finalAnswer;
	int currentAwardAmount ;
    int reducedAmount;
    
	promptPlayerForName(nameForGame);
	
	printWelcomeMessage(nameForGame);
	
	while (questionNumber <= MAX_QUESTIONS)
    {
	
		currentAwardAmount = calculateCurrentAward(questionNumber, currentAwardAmount);
		
		popUpCurrentQuestion4choices(currentAwardAmount);
	
		if (lifeLineUsed == 0)
        {
			playersResponseLifeLine = askPlayerForLifeLine();
		
			if (playersResponseLifeLine == 'Y' || playersResponseLifeLine == 'y')
            {
		
				popUpCurrentQuestion2choices(currentAwardAmount);
				lifeLineUsed ++; 
				printf("\nReminder - You get only 1 50-50 lifeline - and you are using it now \n\n");
			}
		}
		
		finalAnswer = acceptPlayersFinalAnswer ();
		
		if (isCorrectFinalAnswer (finalAnswer, questionNumber, allCorrectAnswers) )
        {
		
		 	generateRandomGreeting(greet);
			printf("%s - You just won $ %d\n", greet, currentAwardAmount);
			
			if (questionNumber < MAX_QUESTIONS)
            {
				printf("Let us play the next question now\n\n"); 
			}
		}
		
		else {
			printf  ("Oops - that was incorrect.");
            
            reducedAmount = calculateReducedAward (questionNumber, currentAwardAmount);

			printf("You still won $%d. Well done.\n\n", reducedAmount);
			
            questionNumber = MAX_QUESTIONS;
		}
		questionNumber ++;
	}
	
	printf("It was fun playing with you \n\n");
	
	return 0;
}

//this function asks the player for their first and last name
void promptPlayerForName(char nameForGame[50]){
    //initialize a string for the user's last name
    char lastName[25];
    //scan for user's first name and store it into variable nameForGame
    printf("Enter your first name: ");
    scanf("%s", nameForGame);
    //scan for user's last name and store it into variable lastName
    printf("Enter your last name: ");
    scanf("%s", lastName);
    //append a space to nameForGame, and the append lastName to nameForGame, this makes nameForGame have the user's full name
    strcat(nameForGame, " ");
    strcat(nameForGame, lastName);
}

//this function prints the welcome message including all the stars
void printWelcomeMessage(char nameForGame[50]){
    //for loop for printing the first set of stars, first line has one star, second line has two stars, third line has three stars
    for(int i=0; i < 3; ++i){
        for(int j=0;j<=i;++j){
            printf("*");
        }
         printf("\n");
    }
    //for loop that prints stars equal to the length of nameForGame plus 8 more stars
    for(int i=0;i<(strlen(nameForGame)+8);++i){
        printf("*");
    }
    //print's the welcome message
    printf("\nWelcome %s\n", nameForGame);
    printf("Let us play WDWM!\n");
    //for loop that prints stars equal to the length of nameForGame plus 8 more stars
    for(int i=0;i<(strlen(nameForGame)+8);++i){
        printf("*");
    }
    printf("\n");
    //for loop for printing the last set of stars, first line has 3 stars, second line has 2 stars, third line has 1 star
    for(int i=0;i<3;++i){
        for(int j=3;j>i;--j){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

//this function calculates the how much money the user wins depending on the question number
int calculateCurrentAward(int questionNumber,int awardPreviousQuestion){
    //if the user gets the first question right they win $100
    if (questionNumber == 1){
        awardPreviousQuestion = 100;
    }
    //if the question number is even, the previous award amount is multiplied by 5 to get the new award amount
    else if (questionNumber %2 == 0){
        awardPreviousQuestion = awardPreviousQuestion * 5;
    }
    //if the question number is odd, the previous award amount is multiplied by 3 to get the new award amount
    else if(questionNumber %2 == 1){
        awardPreviousQuestion = awardPreviousQuestion * 2;
    }
    //returns how much the user won
    return awardPreviousQuestion;
}

//this function diplays the question and the possible answers to the question
void popUpCurrentQuestion4choices(int currentAwardAmount){
    //the question the user is given corresponds on how much money the user is eligible to win
    //for example if the user can win $100 the program prints the first question, this process repeats up until the last question
    if (currentAwardAmount == 100){
        printf("Here is the $ 100 question:\n\n");
        printf("Which of the following programming languages is taught in CIS1500 at the University of Guelph?\n\n");
        printf("A. Python             B. Cobra\n");
        printf("C. C                  D. Java\n\n");
    }
    else if (currentAwardAmount == 500){
        printf("Here is the $ 500 question:\n\n");
        printf("Which Canadian chain first opened in Hamilton in 1964?\n\n");
        printf("A. McDonalds              B. Tim Hortons\n");
        printf("C. Wendy                  D. Mr.Sub\n\n");
    }
    else if (currentAwardAmount == 1000){
        printf("Here is the $ 1000 question:\n\n");
        printf("What is Canada's national sport?\n\n");
        printf("A. Hockey                                    B. Lacrosse\n");
        printf("C.Hockey and Lacrosse                        D. Baseball\n\n");
    }
    else if (currentAwardAmount == 5000){
        printf("Here is the $ 5000 question:\n\n");
        printf("Which Canadian city ranks as the most educated in the country?\n\n");
        printf("A. Montreal                          B. Ottawa\n");
        printf("C. Vancouver                         D. Toronto\n\n");
    }
    else if (currentAwardAmount == 10000){
        printf("Here is the $ 100000 question:\n\n");
        printf("What is Canada's highest mountain?\n\n");
        printf("A. Mount Logan, Yukon       B. Whistler Mountain, BC\n");
        printf("C. Mont Tremblant, Quebec   D. Tip Top Mountain, Ontario\n\n");
    }
    else if (currentAwardAmount == 50000){
        printf("Here is the $ 50000 question:\n\n");
        printf("What is the easternmost province of Canada\n\n");
        printf("A. Ontario                  B. Prince Edward Island\n");
        printf("C. Newfoundland             D. Nova Scotia\n\n");
    }
    else if (currentAwardAmount == 100000){
        printf("Here is the $ 100000 question:\n\n");
        printf("The southernmost point of mainland Canada is called Point Pelee. What province is it in?\n\n");
        printf("A. Ontario                  B. Quebec\n");
        printf("C. Newfoundland             D. Nova Scotia\n\n");
    }
}

//this function asks the user if they would like to use the lifeline
char askPlayerForLifeLine(void){
    //intialize a character for the what the user will input if they want to use the life line
    char optionLifeLine;
    //print statement asking if the user wants to use the life line
    printf("Would you like to use a lifeline (50-50)?\n");
    //while loop the will continue to run as long as optionLifeLine is not equal to 'Y','N','y', or 'n'
    while ((optionLifeLine != 'Y') && (optionLifeLine != 'y') && (optionLifeLine != 'N') && (optionLifeLine!= 'n')){
        //print statment telling the user to enter a valid input, and then scans for user input
        printf("Enter Y or y, N or n: ");
        scanf(" %c", &optionLifeLine);
        printf("\n");
        //if user inputs 'Y','N','y', or 'n', break out of the loop
        if ((optionLifeLine == 'Y') || (optionLifeLine == 'y') || (optionLifeLine == 'N') || (optionLifeLine == 'n')){
            break;
        }
        //if user enters an invalid  character for optionLifeLine print "Invalid option entered" and continue with the loop
        else{
            printf("Invalid option entered\n\n");
        }
    }
    //return the value of optionLifeLine
    return optionLifeLine;
}

//this functiondisplays the questions and corresponding answers after the life line has been used
void popUpCurrentQuestion2choices(int currentAwardAmount){
    printf("OK - here are your 2 choices after using the 50-50 lifeline\n\n");
    //the question the user gets is depends on how much money they are eligible to win, however there are only two possible answers displayed	
    if (currentAwardAmount == 100){
        printf("C. C\n");
        printf("D. Java\n");
    }
    else if (currentAwardAmount == 500){
        printf("A. McDonalds\n");
        printf("B. Tim Hortons\n");
    }
    else if (currentAwardAmount == 1000){
        printf("C.Hockey and Lacrosse\n");
        printf("D. Baseball\n");
    }
    else if (currentAwardAmount == 5000){
        printf("A. Montreal\n");
        printf("B. Ottawa\n");
    }
    else if (currentAwardAmount == 10000){
        printf("A. Mount Logan, Yukon\n");
        printf("B. Whistler Mountain, BC\n");
    }
    else if (currentAwardAmount == 50000){
        printf("C. Newfoundland\n");
        printf("D. Nova Scotia\n");
    }
    else if (currentAwardAmount == 100000){
        printf("C. Newfoundland\n");
        printf("D. Nova Scotia\n");
    }
}
	
//this funciton asks the user to input an answer for the question
char acceptPlayersFinalAnswer(void){
    //initialize a variable to store the answer the user will input
    char answer;
    //initialize a variable for the while loop
    int loop = 0;
    //while loop will continue as long as loop is equal to one
    //while loop tells user to enter an answer: 'A', 'B', 'C', OR 'D'
    //if the answer is equal to any of the four options loop is equal to 1 and breaks out of the loop
    while(loop == 0){
	printf("Enter your FINAL ANSWER('A', 'B', 'C' OR 'D') here: ");
	scanf(" %c", &answer);
        if (answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D'){
            loop = 1;
        }
    }
    //returns the answer the user inputted
    return answer;
}

//this function checks if the answer the user inputted is correct
bool isCorrectFinalAnswer(char finalAnswer,int questionNumber, char allCorrectAnswers[MAX_QUESTIONS]){
    //initialize variable to store if the answer is right or wrong 
    bool answer;
    //switch for the question number
    //if the answer the user inputted is equal to the answer key the, boolean of answer is true, otherwise it is false
    switch (questionNumber){
        case 1:
            if (finalAnswer == allCorrectAnswers[questionNumber-1]){
                answer = true;
                break;
            }
            else{
                answer = false;
                break;
            }
        case 2:
            if (finalAnswer == allCorrectAnswers[questionNumber-1]){
                answer = true;
                break;
            }
            else{
                answer = false;
                break;
            }
        case 3:
            if (finalAnswer == allCorrectAnswers[questionNumber-1]){
                answer = true;
                break;
            }
            else{
                answer = false;
                break;
            }
        case 4:
            if (finalAnswer == allCorrectAnswers[questionNumber-1]){
                answer =  true;
                break;
            }
            else{
                answer = false;
                break;
            }
        case 5:
            if (finalAnswer == allCorrectAnswers[questionNumber-1]){
                answer = true;
                break;
            }
            else{
                answer = false;
                break;
            }
        case 6:
            if (finalAnswer == allCorrectAnswers[questionNumber-1]){
                answer = true;
                break;
            }
            else{
                answer = false;
                break;
            }
        case 7:
            if (finalAnswer == allCorrectAnswers[questionNumber-1]){
                answer = true;
                break;
            }
            else{
                answer = false;
                break;
            }
    }
    //return boolean true or false
    return answer;
}

//this function creates a random greeting for the user after they answer a question correctly
void generateRandomGreeting(char greet[20]){
    //initialize an integer  to store a random number between 1 to 5
    int randomNum;
    randomNum = (rand() %5) + 1;
    printf("\n");
    //a greeting is stored into a string depending on a number from 1 to 5
    if (randomNum == 1){
        strcpy(greet, "Bravo");
    }
    else if (randomNum == 2){
        strcpy(greet, "Congrats");
    }
    else if (randomNum == 3){
        strcpy(greet, "Well done");
    }
    else if (randomNum == 4){
        strcpy(greet, "Very nice");
    }
    else if (randomNum == 5){
        strcpy(greet, "Proud of you");
    }
}

//this function calculates the amount of money the user wins if they lose the game
int calculateReducedAward(int questionNumber, int currentAwardAmount){
    //NOTE:My TA told me you get $100 just for playing the game whether you win or lose
    //NOTE:However, I have heard from other students that you don't get any money at all, and from others you only get $50
    //if the user gets the first question wrong, the user still wins $100
    if (questionNumber == 1){
        currentAwardAmount = 100;
    }
    //if the user loses on an even numbered question, divide the current award amount by 5 in order to get the previous award amount
    else if (questionNumber %2 == 0){
        currentAwardAmount = currentAwardAmount/5;
    }
    //if the user loses on an odd numbered question, divide the current award amount by 2 in order to get the previous award amount
    else if (questionNumber %2 == 1){
        currentAwardAmount = currentAwardAmount/2;
    }
    //return the correct award amount for losing the game
    return currentAwardAmount;
}
