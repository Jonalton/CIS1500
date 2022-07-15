/**************************judehamiltonJonaltonA1.c*******************************
Student Name: Jonalton Jude Hamilton				Email ID: jjudeham
Date: October 5th, 2018					        Course Name: CIS 1500
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
 compiling: gcc judehamiltonJonaltonA1.c -std=c99 -Wall -o judehamiltonJonaltonA1
 *********************************************************************************
			Running the program
 *********************************************************************************
 running:	./judehamiltonJonaltonA1
 The user is prompted for 11 different inputs before the output is generated
 **********************************************************************************/
#include <stdio.h>

int main(void){
	//initialize variables to start
    float dailyPractice, weeklyLabs, labExam1, labExam2, courseMark, markNeeded ;
    int labPerfect, courseGoal, markPercent;

	//Created an array to store the inputs for the assignments and their respective moss value
    float a[4];
    int moss[4];
	//Get the inputs from the user for their marks
    printf("Enter the following marks (each out of 100):\n");
    printf("\n");
    printf("\nWeekly Labs:");
    scanf("%f",&weeklyLabs);
    printf("\nDaily Practice:");
    scanf("%f",&dailyPractice);
    printf("\nLab Exam I:");
    scanf("%f",&labExam1);
    printf("\nLab Exam II:");
    scanf("%f",&labExam2);
	//for loop repeating three times getting the input for each of the assignments from the user
    for (int i = 1;i <= 3; i=i+1){
        printf("\nAssignment%d:",i);
	scanf("%f",&a[i]);
	 printf("\nMoss output for A%d (0 / 1):",i);
	 scanf("%d",&moss[i]);
	 if (moss[i] == 0){
	     a[i] = 0;
	 }
	 else{
         }
    }

	//continue getting input from user
    printf("\n");
    printf("\nHow much do you desire as an overall course grade:");
    scanf("%d",&courseGoal);

    printf("\n\n");

	//if the user got perfect on both lab exams and extra 3 marks are awarded otherwise nothing changes
    if ((labExam1 == 100) && (labExam2 == 100)){
	labPerfect = 3;
    }
    else{
        labPerfect = 0;
    }

	//if MOSS was 0 for all three assignments, print out the user can not pass the course
    if ((moss[1] == 0) && (moss[2] == 0) && (moss[3] == 0)){
        printf("\n*************************************************");
        printf("\nYou cannot pass the course - try harder next time.");
        printf("\n*************************************************\n");
    }
    else{
	        //calculation for the weightings off all the marks together
        courseMark = (weeklyLabs*0.1) + (dailyPractice * 0.1) + (labExam1 * 0.1) + (labExam2 * 0.1) + (a[1] * 0.05) + (a[2] * 0.1) + (a[3] * 0.1) + labPerfect;
	        //calculation for how many marks are needed to reach the course goal
        markNeeded = courseGoal - courseMark;
		//calculation for how many marks needed but in percent
        markPercent = (markNeeded/35) * 100;
		//printing out the weights of each individual mark, mark for each graded task
        printf("\n*********************************************************");
        printf("\nAssessment          Weight         Marks");
        printf("\n---------------------------------------------------------");
                //the %.2f is to make the float number only display two decimal places
        printf("\nWeekly Labs         10             %.2f",weeklyLabs);
        printf("\nDaily Practice      10             %.2f",dailyPractice);
        printf("\nLab Exam I          10             %.2f",labExam1);
        printf("\nLab Exam II         10             %.2f",labExam2);
		//bonus marks from getting perfect on both lab exams
        printf("\nBonus from lab exams:              %d",labPerfect);
        printf("\nAssignment1         5              %.2f",a[1]);
        printf("\nAssignment2         10             %.2f",a[2]);
        printf("\nAssignment3         10             %.2f",a[3]);
        printf("\nFinal Exam          35         To be determined");
        printf("\n");
        printf("\n*********************************************************");
        printf("\n");
		//printing the mark in the course without the final exam
        printf("\nCurrent course mark = %.2f / 65.00", courseMark);
		//printing how many marks are needed to reach the course goal and the percentage needed on the final exam
        printf("\nYou need %.2f / 35.00 to reach your goal (%d)",markNeeded, courseGoal);
        printf("\nIn percentage, you need %d %% to reach your goal (%d)",markPercent, courseGoal);
        printf("\n*********************************************************\n");
	}


    return 0;
}
