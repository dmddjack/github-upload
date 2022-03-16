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
#define DEBUG_AI
#undef  DEBUG_AI

#define HUMAN_PLAYER
#undef  HUMAN_PLAYER

#define MASS_TEST
#undef MASS_TEST

#ifndef  HUMAN_PLAYER
#define AI_PLAYER
#include "aiplayer_1155174666.h"
#endif

#ifndef MASS_TEST
int main()
#else
int sub_main(unsigned int seed)
#endif
{
	#ifndef MASS_TEST
	unsigned int seed ;
	scanf("%d", & seed) ;
	#endif
	int input ;
	uint32_t pseudo_seed = seed ;
	tinymt32_init( & state , pseudo_seed ) ;
	int game_board[BOARD_SIZE][BOARD_SIZE] ;
	#ifndef DEBUG
	init_board(game_board) ;
	while(1)
	{
		#ifdef HUMAN_PLAYER
		input = human_player(game_board) ;
		#endif
		#ifdef AI_PLAYER
		input = aiplayer_1155174666(game_board) ;
		#ifdef DEBUG_AI
		switch(input)
		{
			case UP:{
				printf("UP\n") ;
				break;
			}
			case DOWN:{
				printf("DOWN\n") ;
				break;
			}
			case LEFT:{
				printf("LEFT\n") ;
				break;
			}
			case RIGHT:{
				printf("RIGHT\n") ;
				break;
			}
		}
		printf("can move? %d\n", can_move_1155174666(game_board, input)) ;
		if(!can_move_1155174666(game_board, input))
		{
			printf("illegal move!\n") ;
			return 0 ;
		}
		
		#endif
		#endif
		
		move(game_board, input) ;
		add_rand_cell(game_board) ;
		//printf("here\n");
		#ifndef MASS_TEST
		print_board(game_board)	;
		#endif
		if(is_game_over(game_board))
		{
			#ifndef MASS_TEST
			printf("Under this scenario:\n") ;
			printf("Your score is %d\nThe game is over!\n", score(game_board)) ;
			#endif
			break ;
		}
	}
	
	#endif
	
	#ifdef DEBUG
	int sample_board[BOARD_SIZE][BOARD_SIZE] =  \
						{{   4,   4,   2,   0}, \
						 {  32,   8,   4,   2}, \
						 {  64,  16,   8,   4}, \
						 {   2,  32,  16,   8}} ;
	print_board(sample_board) ;
	add_rand_cell(sample_board) ;
	print_board(sample_board) ;
	#endif
	#ifndef MASS_TEST
	return 0 ;
	#else
	return score(game_board) ;
	#endif
}

#ifdef MASS_TEST
#include <math.h>

int main()
{
	double data[10000] ;
	double sum = 0.0, mean, SD = 0.0;
	int i ;
	for(i = 0; i < 10; i++)
	{
		printf("%d\n", i + 148967189) ;
		data[i] = (double)sub_main(i + 148967189) ;
		sum += data[i] ;
		printf("score of seed %d: %lf\n", i + 148967189 , data[i]) ;
	}
	//count /= 10000 ;
	//printf("avg score: %d", count) ;
	//printf("min score: %d\n", count) ;
	//printf("min seed: %d", min_seed) ;
	
    mean = sum / 10;
    for (i = 0; i < 10; ++i)
        SD += pow(data[i] - mean, 2);
        
    SD = sqrt(SD / 10);
    printf("mean = %lf\n", mean) ;
    printf("sd = %lf", SD);
	return 0 ;
}

#endif
