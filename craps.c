#include "craps.h"

enum colors
{
	black, red, green, yellow, blue, purple, cyan, white, gray
};

void text_color(i)
{
	printf("%c[%dm", 0x1B, i + 30);
}

void back_color(i)
{
	printf("%c[%dm", 0x1B, i + 40);
}

void game_menu(void)
{
	text_color(yellow);

	printf(" *****************************************************************************************************************\n");
	printf(" *                                              Welcome to Craps!                                                *\n");
	printf(" *                                              A game of chance!                                                *\n");
	printf(" *                                                                                                               *\n");
	printf(" *                       Select your option below:                                                               *\n");
	printf(" *                                                                                                               *\n");
	printf(" *                       1: Rules of the game                                                                    *\n");
	printf(" *                       2: Start game                                                                           *\n");
	printf(" *                       3: Exit game                                                                            *\n");
	printf(" *                                                                                                               *\n");
	printf(" *****************************************************************************************************************\n");

	text_color(white);
	return;
}

void print_game_rules(void)
{
	int exit = 0;

	printf("****************************************************************************************************************************************************************************************\n\n");
	printf(" > Rules to Craps:                                                                                                                                                                     *\n");
	printf(" - Input your bank balance. If you have a zero balance you have no funds and are not eligible to play.                                                                                 *\n");
	printf(" - Input your desired wager amount. A wager of zero will take you out of that game.                                                                                                    *\n");
	printf(" - Once the wager has been set the player will roll two (6 sided) die.                                                                                                                 *\n");
	printf(" - Once the dice have been rolled and come to rest the sum of the sides that face upward will be added together.                                                                       *\n");
	printf(" - If the sum of the rolled dice is 7 or 11 on the first roll the play wins!                                                                                                           *\n");
	printf(" - If the sum of the rolled dice is 2, 3, or 12 on the first roll the player loses and the house wins, 'craps'.                                                                        *\n"); 
	printf(" - If the sum of the rolled dice is 4, 5, 6, 8, 9, or 10 on the initial roll, then that sum becomes the players 'point'.                                                               *\n");
	printf(" - To win the game the player must continue rolling dice until the sum of the rolled dice is either equal to your initial point or a 7 is rolled. If a 7 is rolled, the player loses.  *\n\n");
	printf("****************************************************************************************************************************************************************************************\n\n");

	printf(" Think you got it? Press 1.\n", exit); 
	scanf("%d", &exit);

	system("cls");

	return;
}

int get_select_option()
{
	int selection = 0; 

	scanf("%d", &selection);

	return selection;
}

int valid_selection(int selection)
{
	int valid = 0; 

	if ((selection == 1) || (selection == 2) || (selection = 3))
	{
		valid = 1;
	}
	else
	{
		return 0;
	}
}

double get_bank_balance(void)
{
	double balance = 0.0;

	printf(" Please input your current bank balance.\n");
	scanf("%lf", &balance);

	return balance;
}

//double get_wager_amount(void)
//{
//	double wager = 0.0;
//
//	printf("Please input desired wager amount. \n");
//	scanf("%lf", &wager);
//
//	return wager;
//}

int roll_die(void)
{
	int value = 0; 

	value = (rand() % 6) + 1;

	return value;
}

void check_bank_balance(double bank_balance)
{
	int input = 0;

	printf(" You have a zero balance and have no funds to play.\n");
	printf(" Press 2 to continue to input window.\n");
	scanf("%d", &input);

	system("cls");
}

double check_wager_amount(double wager_amount, double bank_balance)
{
	/*int roll_wager = 0;
	
	if (wager_amount == 0 || wager_amount > bank_balance)
	{
		printf("Please enter a wager within your available balance.\n\n");
		printf("Available balance: %0.2lf\n\n", bank_balance);
		if (bank_balance == 0)
		{
			printf("Your balance is zero.\n");
			printf("Please input a valid balance.\n\n");
			bank_balance = get_bank_balance();
			printf("Please enter a wager.\n\n");
			scanf("%lf", &wager_amount);
			system("cls");
			printf("Press 1 for new roll.\n");
			scanf("%d", &roll_wager);

			return wager_amount;
		}
		else
		{
			printf("Please enter a wager.\n\n");
			scanf("%lf", &wager_amount);
			system("cls");
			return wager_amount;
		}
	}
	else
	{
		return wager_amount;
	}	*/
	// Youre clearing bank_balance somewhere in here -- fix that
	// you are trying to pass back bank balance and wager amount from this one function -- you will need a pointer
	int input = 0;
	/*while (wager_amount == 0 || wager_amount > bank_balance)
	{
		printf("Please enter a wager within your available balance.\n");
		printf("When finished, press any button to continue with first roll.\n\n");
		printf("Available balance: %0.2lf\n\n", bank_balance);
		scanf("%lf", &wager_amount);
		system("cls");
	}

	printf("Please enter a wager within your available balance.\n");
	printf("Available balance: %0.2lf\n\n", bank_balance);
	scanf("%lf", &wager_amount);*/
	if (wager_amount == 0 || wager_amount > bank_balance)
	{
		while (wager_amount == 0 || wager_amount > bank_balance)
		{
			if (bank_balance == 0)
			{
				printf(" Your balance is zero.\n\n");
				bank_balance = get_bank_balance();
			}
			printf(" Please enter a wager within your available balance.\n");
			printf(" When finished, press any button to continue with first roll.\n\n");
			printf(" Available balance: %0.2lf\n\n", bank_balance);
			scanf("d", &input);
			scanf("%lf", &wager_amount);
			//test
			system("cls");
		}
	}
	else
	{
		printf(" Please enter a wager within your available balance.\n");
		printf(" Available balance: %0.2lf\n\n", bank_balance);
		scanf("%lf", &wager_amount);
	}
	return wager_amount;
}

int calculate_sum_dice(int die0, int die1)
{
	int sum = 0;

	sum = die0 + die1;

	return sum; 
}

int display_die(int die)
{
	//printf("\n%c[%dm%c[%dm", 0x1B, 47, 0x1B, 30);
	printf("\n");
	text_color(black);
	back_color(white);

	if (die == 1)
	{
		printf("-------------- \n");
		printf("|             |\n");
		printf("|             |\n");
		printf("|      *      |\n");
		printf("|             |\n");
		printf("|             |\n");
		printf("-------------- \n\n");
	}
	if (die == 2)
	{
		printf("-------------- \n");
		printf("|             |\n");
		printf("|   *         |\n");
		printf("|             |\n");
		printf("|         *   |\n");
		printf("|             |\n");
		printf("-------------- \n\n");
	}
	if (die == 3)
	{
		printf("-------------- \n");
		printf("|           * |\n");
		printf("|             |\n");
		printf("|      *      |\n");
		printf("|             |\n");
		printf("| *           |\n");
		printf("-------------- \n\n");
	}
	if (die == 4)
	{
		printf("-------------- \n");
		printf("|  *       *  |\n");
		printf("|             |\n");
		printf("|             |\n");
		printf("|             |\n");
		printf("|  *       *  |\n");
		printf("-------------- \n\n");
	}
	if (die == 5)
	{
		printf("-------------- \n");
		printf("|  *       *  |\n");
		printf("|             |\n");
		printf("|      *      |\n");
		printf("|             |\n");
		printf("|  *       *  |\n");
		printf("-------------- \n\n");
	}
	if (die == 6)
	{
		printf("-------------- \n");
		printf("|  *       *  |\n");
		printf("|             |\n");
		printf("|  *       *  |\n");
		printf("|             |\n");
		printf("|  *       *  |\n");
		printf("-------------- \n\n");
	}
	//printf("%d", die);
	printf("\n");
	text_color(white);
	back_color(black);
}

int is_win_loss_or_point(int sum_dice)
{
	if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
	{
		return 0;
	}
	else if (sum_dice == 7 || sum_dice == 11)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_sub)
{
	double balance = bank_balance;

	if (add_or_sub == 1)
	{
		balance += wager_amount;
	}
	else
	{
		balance -= wager_amount;
	}
	return balance;
}

void winning_display(void)
{
	printf(" Look whos buying dinner, big winner!\n");
}

void losing_display(void)
{
	printf(" Better luck next time, champ.\n");
}

void print_bank_bal(double bank_balance)
{
	printf(" Current balance: %0.2lf\n\n", bank_balance);
}

int is_point_loss_or_neither(int dice_sum, int point_value)
{
	if (point_value == dice_sum)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void chatter_messages_win(FILE *infile)
{
	char random = "\0";
	fopen("chatter_win.dat", "r");

		fscanf(infile, "%c", &random);
		
		if (random == 'A')
		{
			printf(" Beginners luck..", random);
		}
}
