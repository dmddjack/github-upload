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

#ifndef GAME_H
#define GAME_H

#include "tinymt32.h"

tinymt32_t state ;

#define BOARD_SIZE 4
#define EMPTY_CELL 0
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define INVALID -1
#define SWAP(A, B) {int tmp = A ; A = B ; B = tmp ;}
#define MERGE(DEST, START) {DEST += START; START = EMPTY_CELL ;}

void print_board(int game_board[BOARD_SIZE][BOARD_SIZE]);

void cpy_board(int dest[BOARD_SIZE][BOARD_SIZE], int source[BOARD_SIZE][BOARD_SIZE]);

int score(int game_board[BOARD_SIZE][BOARD_SIZE]);

void add_rand_cell(int game_board[BOARD_SIZE][BOARD_SIZE]);

void init_board(int game_board[BOARD_SIZE][BOARD_SIZE]);

int is_same_board(int game_board_0[BOARD_SIZE][BOARD_SIZE], int game_board_1[BOARD_SIZE][BOARD_SIZE]);

int is_game_over(int game_board[BOARD_SIZE][BOARD_SIZE]);

void pull(int game_board[BOARD_SIZE][BOARD_SIZE], int direction);

void merge(int game_board[BOARD_SIZE][BOARD_SIZE], int direction);

void move(int game_board[BOARD_SIZE][BOARD_SIZE], int direction);

int human_player(int game_board[BOARD_SIZE][BOARD_SIZE]);

#endif 
