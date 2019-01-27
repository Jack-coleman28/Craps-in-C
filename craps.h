#ifndef CRAPS_H
#define CRAPS_H

#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include <time.h> 

#define NUM0 0
#define NUM1 1

void print_game_rules(void);
double get_bank_balance(void);
double get_wager_amount(void);
double check_wager_amount(double wager, double balance);
int roll_die(void);
int calculate_sum_dice(int die0, int die1);
int is_win_loss_or_point(int dice_sum); 
int is_point_loss_or_neither(int dice_sum, int point_value);
double adjust_bank_balance(double bank_balance, double wager_amount, int add_subtract);
void chatter_messages_win(FILE *infile); // not done
void chatter_messages_loss(FILE *infile);

void game_menu(void);
int get_select_option(void);
int valid_selection(int selection);
void check_bank_balance(double bank_balance);
int display_die(int die);
void winning_display(void);
void losing_display(void);
void print_bank_bal(double bank_balance);
void text_color(int);
void back_color(int);

#endif
