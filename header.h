#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5            // ���� ũ�� N�� ��ȣ����� ���� ���� 
#define M 3           // ������ �̱�� ���� M�� ��ȣ ����� ���� ���� 

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
 
 
int stored[N*N]; 				// number1�� number2���� �������� �迭 


int ubingo[N][N];               //������� ������ = ��������    
int cbingo[N][N];               //��ǻ���� ������ 

