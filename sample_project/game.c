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
#include "game.h"

void print_board(int game_board[BOARD_SIZE][BOARD_SIZE])
{
	printf(" ____ ____ ____ ____ \n") ;
	for(int i = 0; i < BOARD_SIZE; i++)
	{
		for(int j = 0; j < BOARD_SIZE; j++)
		{
			printf("|") ;
			if(game_board[i][j] == EMPTY_CELL)
				printf("    ") ;
			else
				printf("%4d", game_board[i][j]) ;
		}
		printf("|\n") ;
		printf("|____|____|____|____|\n") ;
	}
	printf("\n") ;
}

void cpy_board(int dest[BOARD_SIZE][BOARD_SIZE], int source[BOARD_SIZE][BOARD_SIZE])
{
	for(int i = 0; i < BOARD_SIZE; i++)
		for(int j = 0; j < BOARD_SIZE; j++)
			dest[i][j] = source[i][j] ;
}

int score(int game_board[BOARD_SIZE][BOARD_SIZE])
{
	int count = 0 ;
	for(int i = 0; i < BOARD_SIZE; i++)
		for(int j = 0; j < BOARD_SIZE; j++)
			count += game_board[i][j] ;
	return count ;
}


void add_rand_cell(int game_board[BOARD_SIZE][BOARD_SIZE])
{
	int i , j ; // i and j store the position of the new cell
	while (1)
	{
		i = tinymt32_generate_uint32(&state) % 4 ; // row num.
		j = tinymt32_generate_uint32(&state) % 4 ; // col. num.
		//printf("i = %d, j = %d\n", i, j) ; 
		if ( game_board[i][j] == EMPTY_CELL ) // e.g., 0
		{
			game_board[i][j] = 2 ;
			break ;
		}
	}
}

void init_board(int game_board[BOARD_SIZE][BOARD_SIZE])
{
	for(int i = 0; i < BOARD_SIZE; i++)
		for(int j = 0; j < BOARD_SIZE; j++)
			game_board[i][j] = EMPTY_CELL ;
	
	add_rand_cell(game_board) ;
	//print_board(game_board) ;
}

int is_same_board(int game_board_0[BOARD_SIZE][BOARD_SIZE], int game_board_1[BOARD_SIZE][BOARD_SIZE])
{
	for(int i = 0; i < BOARD_SIZE; i++)
		for(int j = 0; j < BOARD_SIZE; j++)
			if(game_board_0[i][j] != game_board_1[i][j])
				return 0 ;
	
	return 1 ;
}

int is_game_over(int game_board[BOARD_SIZE][BOARD_SIZE])
{
	int test_board[BOARD_SIZE][BOARD_SIZE] ;
	for(int direction = UP; direction <= RIGHT; direction++)
	{
		cpy_board(test_board, game_board) ;
		move(test_board, direction) ;
		if(!is_same_board(test_board, game_board))
			return 0 ;
	}  
	return 1 ;
}

void pull(int game_board[BOARD_SIZE][BOARD_SIZE], int direction)
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

void merge(int game_board[BOARD_SIZE][BOARD_SIZE], int direction)
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

void move(int game_board[BOARD_SIZE][BOARD_SIZE], int direction)
{
	pull(game_board, direction) ;
	merge(game_board, direction) ;
	pull(game_board, direction) ;
}

int human_player(int game_board[BOARD_SIZE][BOARD_SIZE])
{
	char input ;
	
	while(1)
	{
		do
		{
			input = getchar() ;
		}
		while(input == ' ' || input == '\n' || input == '\r') ;
		
		switch(input)
		{
			case 'U':{
				input = UP ;
				break ;
			}
			case 'D':{
				input = DOWN ;
				break ;
			}
			case 'L':{
				input = LEFT ;
				break ;
			}
			case 'R':{
				input = RIGHT ;
				break ;
			}
			default :{
				input = INVALID ;
				break ;
			}
		}
		if(input == INVALID)
		{
			printf("[Error 00] invalid input!\nPlease enter again:\n") ;
			continue ;
		}
		else
		{
			int test_board[BOARD_SIZE][BOARD_SIZE] ;
			cpy_board(test_board, game_board) ;
			move(test_board, input) ;
			if(is_same_board(test_board, game_board))
			{
				printf("[Error 01] invalid movement!\nPlease enter again:\n") ;
				continue ;
			}
			else
			{
				return input ;
			}			
		}
	}
}



