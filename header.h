#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5            // 빙고 크기 N은 기호상수로 조절 가능 
#define M 3           // 빙고에서 이기는 조건 M은 기호 상수로 조절 가능 

void initialize();
void set_rand(int*array);
void swap(int*x, int*y);
void print_bingo(int arr[N][N]);
int get_number_byCo(int frc);           // 0:USER 1:COM
int get_number_byMe(int frm);          // 0:USER 1:COM
void filled_bingo(int arr[N][N], int number);
int u_count_bingo(int arr[N][N]);
int c_count_bingo(int arr[N][N]);
void print_winner(int winner);
 
 
int stored[N*N]; 				// number1과 number2값을 저장해줄 배열 


int ubingo[N][N];               //사용자의 빙고판 = 전역변수    
int cbingo[N][N];               //컴퓨터의 빙고판 

