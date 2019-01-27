#include "craps.h"

int main(void)
{
	system("cls");
	int die[2] = { 0, 0 }, selection = 0, valid = 0, i = 0, sum_dice = 0, point = 0, input = 0;
	double bank_balance = 0.0, wager_amount = 0.0;
	srand((unsigned int)time(NULL));
	FILE *infile = NULL;

	do
	{
		do
		{
			game_menu();
			selection = get_select_option();
			valid = valid_selection(selection);
			system("cls");
		} while (!valid);

		switch (selection)
		{
		case 1:

			print_game_rules();

			break;

		case 2:
			printf(" Game started.\n\n");

			bank_balance = get_bank_balance();
			while (bank_balance <= NUM0)
			{
				check_bank_balance(bank_balance);
				bank_balance = get_bank_balance();

				system("cls");
			}
				do
				{
					print_bank_bal(bank_balance);
					wager_amount = check_wager_amount(wager_amount, bank_balance);
				
					for (i = 0; i < 2; i++)
					{
						die[i] = roll_die();
					}

					sum_dice = calculate_sum_dice(die[0], die[1]);

					display_die(die[0]);
					display_die(die[1]);
					printf("Roll:%d\n\n", sum_dice);

					switch (is_win_loss_or_point(sum_dice))
					{
					case 1:
						winning_display();
						bank_balance = adjust_bank_balance(bank_balance, wager_amount, NUM1);
						print_bank_bal(bank_balance);
						break;

					case 0:
						losing_display();
						bank_balance = adjust_bank_balance(bank_balance, wager_amount, NUM0);
						print_bank_bal(bank_balance);
						break;

					default:
						point = sum_dice;

						do
						{
							if (bank_balance > NUM0)
							{
								printf(" You made a point.\n");
								printf(" To roll again, press 2.\n");
								scanf("%d", &input);
								//chatter

								for (i = 0; i < 2; i++)
								{
									die[i] = roll_die();
								}

								sum_dice = calculate_sum_dice(die[0], die[1]);

								display_die(die[0]);
								display_die(die[1]);
								printf(" Roll:%d\n\n", sum_dice);
							}
							else if (bank_balance <= NUM0)//here
							{
								check_bank_balance(bank_balance);
								bank_balance = get_bank_balance();
							}

						} while (sum_dice != point && sum_dice != 7);

						switch (is_point_loss_or_neither(sum_dice, point))
						{
						case 1:
							winning_display();
							bank_balance = adjust_bank_balance(bank_balance, wager_amount, NUM1);
							print_bank_bal(bank_balance);
							//chatter_messages_win(infile);
							break;

						case 0:
							losing_display();
							bank_balance = adjust_bank_balance(bank_balance, wager_amount, NUM0);
							print_bank_bal(bank_balance);
							//chatter

							break;
						}
				}

				//chatter
				printf(" Do you want to keep playing? If so press 1, if not press 2.\n");
				scanf("%d", &selection);
				system("cls");

			} while (selection == NUM1);

			system("cls");

			break;

		default:
			printf("\n\n");
			printf(" *                                        Game over, go home and don't tell your wife that you were gambling.                                                   *\n\n");
			break;
		}
	} while (selection != 3);

	return 0;
}
