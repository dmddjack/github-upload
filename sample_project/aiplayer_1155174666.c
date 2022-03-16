/**
* ESTR 1002 Problem Solving by Programming
*
* Course Project
*
* I declare that the assignment here submitted is original
* except for source material explicitly acknowledged,
* and that the same or closely related material has not been
* previously submitted for another course.
* I also acknowledge that I am aware of University policy and
* regulations on honesty in academic work, and of the disciplinary
* guidelines and procedures applicable to breaches of such
* policy and regulations, as contained in the website.
*
* University Guideline on Academic Honesty:
* http://www.cuhk.edu.hk/policy/academichonesty/
* Faculty of Engineering Guidelines to Academic Honesty:
* http://www.erg.cuhk.edu.hk/erg-intra/upload/documents/ENGG_Discipline.pdf
*
* Student Name : FONG, Shi Yuk
* Student ID : 1155174666
* Date : 18 Nov, 2021
*/

#include <stdio.h>
#include "aiplayer_1155174666.h"

void cpy_board_1155174666(int dest[BOARD_SIZE][BOARD_SIZE], int source[BOARD_SIZE][BOARD_SIZE])
{
	for(int i = 0; i < BOARD_SIZE; i++)
		for(int j = 0; j < BOARD_SIZE; j++)
			dest[i][j] = source[i][j] ;
}

int score_1155174666(int game_board[BOARD_SIZE][BOARD_SIZE])
{
	int count = 0 ;
	for(int i = 0; i < BOARD_SIZE; i++)
		for(int j = 0; j < BOARD_SIZE; j++)
			count += game_board[i][j] ;
	return count ;
}

int is_same_board_1155174666(int game_board_0[BOARD_SIZE][BOARD_SIZE], int game_board_1[BOARD_SIZE][BOARD_SIZE])
{
	for(int i = 0; i < BOARD_SIZE; i++)
		for(int j = 0; j < BOARD_SIZE; j++)
			if(game_board_0[i][j] != game_board_1[i][j])
				return 0 ;
	
	return 1 ;
}

int is_game_over_1155174666(int game_board[BOARD_SIZE][BOARD_SIZE])
{
	int test_board[BOARD_SIZE][BOARD_SIZE] ;
	for(int direction = UP; direction <= RIGHT; direction++)
	{
		cpy_board_1155174666(test_board, game_board) ;
		move_1155174666(test_board, direction) ;
		if(!is_same_board_1155174666(test_board, game_board))
			return 0 ;
	}  
	return 1 ;
}

void pull_1155174666(int game_board[BOARD_SIZE][BOARD_SIZE], int direction)
{
	switch(direction)
	{
		case UP:{
			for(int i = 1; i < BOARD_SIZE; i++)
				for(int j = 0; j < BOARD_SIZE; j++)
					if(game_board[i][j] != EMPTY_CELL)
						for(int k = 0; k < i; k++)
							if(game_board[k][j] == EMPTY_CELL)
								SWAP(game_board[k][j], game_board[i][j])
			break ;
		}
		case DOWN:{
			for(int i = BOARD_SIZE - 2; i >= 0; i--)
				for(int j = 0; j < BOARD_SIZE; j++)
					if(game_board[i][j] != EMPTY_CELL)
						for(int k = BOARD_SIZE - 1; k > i; k--)
							if(game_board[k][j] == EMPTY_CELL)
								SWAP(game_board[k][j], game_board[i][j])
			break ;
		}
		case LEFT:{
			for(int i = 0; i < BOARD_SIZE; i++)
				for(int j = 1; j < BOARD_SIZE; j++)
					if(game_board[i][j] != EMPTY_CELL)
						for(int k = 0; k < j; k++)
							if(game_board[i][k] == EMPTY_CELL)
								SWAP(game_board[i][k], game_board[i][j])
			break ;
		}
		case RIGHT:{
			for(int i = 0; i < BOARD_SIZE; i++)
				for(int j = BOARD_SIZE - 2; j >= 0; j--)
					if(game_board[i][j] != EMPTY_CELL)
						for(int k = BOARD_SIZE - 1; k > j; k--)
							if(game_board[i][k] == EMPTY_CELL)
								SWAP(game_board[i][k], game_board[i][j])
			break ;
		}	
	}
	return ;
}

void merge_1155174666(int game_board[BOARD_SIZE][BOARD_SIZE], int direction)
{
	switch(direction)
	{
		case UP:{
			for(int i = 0; i < BOARD_SIZE - 1; i++)
				for(int j = 0; j < BOARD_SIZE; j++)
					if(game_board[i][j] != EMPTY_CELL && game_board[i][j] == game_board[i + 1][j])
						MERGE(game_board[i][j], game_board[i + 1][j])
						
			break ;
		}
		case DOWN:{
			for(int i = BOARD_SIZE - 1; i >= 1; i--)
				for(int j = 0; j < BOARD_SIZE; j++)
					if(game_board[i][j] != EMPTY_CELL && game_board[i][j] == game_board[i - 1][j])
						MERGE(game_board[i][j], game_board[i - 1][j])
			break ;
		}
		case LEFT:{
			for(int i = 0; i < BOARD_SIZE ; i++)
				for(int j = 0; j < BOARD_SIZE - 1; j++)
					if(game_board[i][j] != EMPTY_CELL && game_board[i][j] == game_board[i][j + 1])
						MERGE(game_board[i][j], game_board[i][j + 1])
			break ;
		}
		case RIGHT:{
			for(int i = 0; i < BOARD_SIZE; i++)
				for(int j = BOARD_SIZE - 1; j >= 1; j--)
					if(game_board[i][j] != EMPTY_CELL && game_board[i][j] == game_board[i][j - 1])
						MERGE(game_board[i][j], game_board[i][j - 1])
			break ;
		}
	}
	return ;
}

void move_1155174666(int game_board[BOARD_SIZE][BOARD_SIZE], int direction)
{
	pull_1155174666(game_board, direction) ;
	merge_1155174666(game_board, direction) ;
	pull_1155174666(game_board, direction) ;
}

int can_move_1155174666(int game_board[BOARD_SIZE][BOARD_SIZE], int direction)
{
	int test_board[BOARD_SIZE][BOARD_SIZE] ;
	cpy_board_1155174666(test_board, game_board) ;
	move_1155174666(test_board, direction) ;
	if(is_same_board_1155174666(test_board, game_board))
		return 0 ;
	return 1 ;
}

int can_merge_row_1155174666(int game_board[BOARD_SIZE][BOARD_SIZE], int row)
{
	for(int j = 0; j < BOARD_SIZE - 1; j++)
		if(game_board[row][j] != EMPTY_CELL && game_board[row][j] == game_board[row][j + 1])
			return 1 ;
	return 0 ;
}

int can_merge_col_1155174666(int game_board[BOARD_SIZE][BOARD_SIZE], int row)
{
	for(int j = 1; j < BOARD_SIZE; j++)
		if(game_board[row][j] != EMPTY_CELL && game_board[row][j] == game_board[row - 1][j])
			return 1 ;
	return 0 ;
}

int not_empty_1155174666(int game_board[BOARD_SIZE][BOARD_SIZE], int row)
{
	for(int j = 0; j < BOARD_SIZE; j++)
		if(game_board[row][j] == EMPTY_CELL)
			return 0 ;
	return 1 ;
}

int gradient_1155174666(int game_board[BOARD_SIZE][BOARD_SIZE])
{
	int count = 0 ;
	for(int i = 0; i < BOARD_SIZE; i++)
		for(int j = 0; j < BOARD_SIZE; j++)
		{
			//in order to minimize the gradient, the cells must align in a special way 
			if(i + 1 < BOARD_SIZE && game_board[i][j] != EMPTY_CELL && game_board[i + 1][j] != EMPTY_CELL)
			{
				int ratio = log2((double)game_board[i][j] / (double)game_board[i + 1][j]) ;
				count += ratio <= 0 ? (int)(fabs(ratio) + 0.5) : (int)(fabs(ratio) + 0.5) * 2;
			}
			if(j + 1 < BOARD_SIZE && game_board[i][j] != EMPTY_CELL && game_board[i][j + 1] != EMPTY_CELL)
			{
				int ratio = log2((double)game_board[i][j] / (double)game_board[i][j + 1]) ;
				count += ratio >= 0 ? (int)(fabs(ratio) + 0.5) : (int)(fabs(ratio) + 0.5) * 2;
			}
		}
	return count ;
}

void add_worse_case_cell_1155174666(int game_board[BOARD_SIZE][BOARD_SIZE])//add a cell that maximizes the gradient
{
	int loc_x = 0, loc_y = 0, max_score = 0 ;
	for(int i = 0; i < BOARD_SIZE; i++)
		for(int j = 0; j < BOARD_SIZE; j++)
		{
			if(game_board[i][j] != EMPTY_CELL)
				continue ;
				
			game_board[i][j] = 2 ;
			
			if(max_score <= gradient_1155174666(game_board))
			{
				max_score = gradient_1155174666(game_board) ;
				loc_y = i ;
				loc_x = j ;
			}
			
			game_board[i][j] = EMPTY_CELL ;
		}
	game_board[loc_y][loc_x] = 2 ;
}

int min_max_1155174666(int game_board[BOARD_SIZE][BOARD_SIZE], int step, const int init_step)
{
	if(step == 0)
	{
		return gradient_1155174666(game_board) ;
	}
	else
	{
		int test_board[4][BOARD_SIZE][BOARD_SIZE] ;
		int min_score = 65535 , move = INVALID ;
		for(int direction = UP; direction <= RIGHT; direction++)
		{
			int score[4] = {0} ;
			cpy_board_1155174666(test_board[direction], game_board) ;
			if(can_move_1155174666(test_board[direction], direction))
			{
				move_1155174666(test_board[direction], direction) ;
				add_worse_case_cell_1155174666(test_board[direction]) ;
				score[direction] = gradient_1155174666(test_board[direction]) + min_max_1155174666(test_board[direction], step - 1, init_step); 
			}
			else
			{
				score[direction] = 1023 ;
			}
			if(score[direction] <= min_score && score[direction] != 1023)
			{
				min_score = score[direction] ;
				move = direction ;
			}
		}
		if(step == init_step)
		{
			if(can_move_1155174666(game_board, move))
				return move ;
			else
				return INVALID ;
		}
		else
			return min_score ;	
	}
}
 
int aiplayer_1155174666(int game_board[BOARD_SIZE][BOARD_SIZE])
{
	static int count = 0, next_move = -1 ;
	int min_max_move = -1 ;
	// next_move stores the output when function is called again, when != -1 ;
	count++ ;
	//printf("%d\n", count) ;
	//can be implemented for count <=20 or sth
	if(game_board[3][0] >= 4096)
		min_max_move = min_max_1155174666(game_board, 10, 10) ;
	else
		min_max_move = min_max_1155174666(game_board, 9, 9) ;
	if(min_max_move == INVALID || count < 50)
	{
		if(next_move != -1 && can_move_1155174666(game_board, next_move))
		{
			//printf("impl. by prev. move.\n") ;
			int tmp = next_move ;
			next_move = -1 ;
			return tmp ;
		}
		else if(can_merge_row_1155174666(game_board, 3))
		{
			next_move = DOWN ;
			//printf("can_merge\n") ;
			return LEFT ;
		}
		else if(!can_merge_row_1155174666(game_board, 3) && not_empty_1155174666(game_board, 3) && can_move_1155174666(game_board, RIGHT) && count % 4 == 0 )
		{
			return RIGHT ;
		}
		else if(can_move_1155174666(game_board, LEFT) && can_move_1155174666(game_board, DOWN))
		{
			return count % 2 ? DOWN : LEFT;
		}
		else if(!can_move_1155174666(game_board, LEFT) && can_move_1155174666(game_board, DOWN))
		{
			return DOWN ;
		}
		else if(!can_move_1155174666(game_board, DOWN) && can_move_1155174666(game_board, LEFT))
		{
			return LEFT ;
		}
		else if(can_move_1155174666(game_board, RIGHT))
		{
			next_move = LEFT ;
			return RIGHT ;
		}
		else
		{
			next_move = DOWN ;
			return UP ;
		}
	}
	else
		return min_max_move ;
	return -1 ;
}
