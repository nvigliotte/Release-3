/*
  Nicholas Vigliotte
  ITT-310
  June 12, 2021

 Jeremy Wright
------------------------

 CHORE-TELLER
   Ver. 3.0
*/

#include <stdio.h>
#include <stdlib.h>

//Structure for rating and feedback
struct rateFeed
{
	int rating;

	char feed[200];
};

//Variable for entering current day of the week
int dayOfWeek;

//Declare & Initialize choreCost array - defined payouts for each chore
int choreCost[4] = { 5, 10, 15, 20 };

//File for the register
FILE *Finance;

//Main function that contains loop and decision for chores
int main()
{

	errno_t err;
	
	//Prints the welcome message and prompts the user for day of the week
	printf("Welcome to the Chore-Teller!");
	printf("\nPlease enter the day of the week (Monday = 1, Sunday = 7): ");
	scanf_s("%d", &dayOfWeek);


	//Switch function that tells chore and the corresponding payout 
	switch (dayOfWeek)
	{
	case 1:
		printf("\nChore of the Day: Sweep Floors\n");
		printf("Payout: $%d\n", choreCost[2]);
		break;
	case 2:
		printf("\nChore of the Day: Dust the House\n");
		printf("Payout: $%d\n", choreCost[1]);
		break;
	case 3:
		printf("\nChore of the Day: Take out Trash\n");
		printf("Payout: $%d\n", choreCost[0]);
		break;
	case 4:
		printf("\nChore of the Day: Clean Bathroom\n");
		printf("Payout: $%d\n", choreCost[2]);
		break;
	case 5:
		printf("\nChore of the Day: Clean the Kitchen\n");
		printf("Payout: $%d\n", choreCost[1]);
		break;
	case 6:
		printf("\nChore of the Day: Laundry Day!\n");
		printf("Payout: $%d\n", choreCost[0]);
		break;
	case 7:
		printf("\nChore of the Day: No Chores :) Enjoy the Day!\n");
		printf("Payout: $%d\n", choreCost[3]);
		break;
	default: printf("Input was not valid!");
		break;
	}
	//End of chore to day switch

	//Using variables from rateFeed strctures with "rate1"
	struct rateFeed rate1;

	//User inputs rating from 1 - 5
	printf("\nCleanliness Rating (1 being worst, 5 being best): ");
	scanf_s("%d", &rate1.rating);

	//User enters a 75 character max description on the condition of the chore
	printf("Briefly describe the condition: ");
	scanf_s(" %49[^\n]", rate1.feed, sizeof(rate1.feed));

	//Output rating and review
	printf("\nRating is: %d\n", rate1.rating);
	printf("Our first review!: %s\n", rate1.feed);

	err = fopen_s(&Finance, "C://Users//Nick V//source//repos//Release 3//Finances.txt", "w+");
	if (err == 0)
	{
		printf("\n ENTRY HAS BEEN LOGGED. THIS IS AN OFFICAL RECORD OF CHORE-TELLER - ALL RIGHTS RESERVED.");
	}
	else
	{
		printf("ERROR - FILE DOES NOT EXIST.");
	}



	//End Function
	return 0;
}
