#include "header.h"

void initialize(){            // ������ �ʱ�ȭ �Լ� 
   srand((unsigned int)time(NULL));
   set_rand((int*)ubingo);
   set_rand((int*)cbingo);   
}

void set_rand(int*array){          //������ ����� �Լ� 
   int i;
   
   for(i=0; i<N*N; i++){
      array[i] = i+1;
   }
   for(i=0; i<N*N; i++){
      swap(&array[i], &array[rand() %N*N]);        // �������� �ٲ��ֱ� 
   }  
}

void swap(int*x, int*y){    
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;  
}

void print_bingo(int arr[N][N]){    // ������ ����ϴ� �Լ� 
   int x, y;

   for(y=0; y<N; y++){
      for(x=0; x<N; x++){
         if(arr[y][x] != 0){         //��κ� �׳� ��� 
            printf("%4d ", arr[y][x]);
         }
         else{                     //������ �߻��� ��� //���⼭ ������ �߻��� ��� �ܿ� üũ �� ��쿡 ��ŷ ��µ�
            printf("-1");
         }
      }
      printf("\n\n");       
   } 
}

void filled_bingo(int arr[N][N], int number){     //�Է¹��� number�� ���� ���� -1�� ����� �Լ�(��ĥ�� �κ�) 
   int x, y;
   
   for(y=0; y<N; y++){							//x,y�� ������ �ٲ㰡�鼭 number�� ������ Ȯ�� 
      for(x=0; x<N; x++){
         if(arr[y][x] == number){
            arr[y][x] = -1;
         }
      }
   }      
}

int get_number_byMe(int frm){					// ���� �Է��ϴ� ���� ����
 int number1;
 int retry;
 int cnt;
 
do{
    retry=0;
   if(frm == 0) {       // 0:��
     printf(">>1~%d ������ ���ڸ� �Է��ϼ���: ", N*N);
     scanf("%d", &number1);
     
     for(cnt=0; cnt<N*N; cnt++){
     	if(number1 == stored[cnt]){
     		printf("�̹� �� �����Դϴ�.\n");
     		
     		get_number_byMe(0);
		 }
	 }
     
     if(number1<1 || number1>N*N){     //retry=1�̸� �Է¿���
     retry=1;
     }
     else{
    retry=0;
     }
    }
} while(retry ==1);        //retry=1�̸� �ٽ� �Է��ؾ��ϹǷ� do�������� ���ư�

 printf(">����ڰ� '%d'�� �����߽��ϴ�. \n", number1);
 return number1;
}

int get_number_byCo(int frc){			//��ǻ�Ͱ� �Է��ϴ� ���� ����
 int number2;
 int retry;
 int cnt;
 int ar[N*N];
 int i;
 
 for(i=0; i<N*N; i++) {
 	ar[i] = i+1;
 }

do{
 retry = 0;
 if(frc == 1) {
 srand((unsigned int)time(NULL));          
 number2 = ar[rand() %(N*N)];
 for(cnt=0; cnt<N*N; cnt++){
 	if(number2 == stored[cnt]){
 		printf("OVERLAPPED \n");
 		get_number_byCo(1);
	 }
 }
 
 if(number2<1 || number2>N*N){ 			    //retry=1�̸� �Է¿���
    retry=1;
  }
 else{
   retry=0;
  }
}
} while(retry ==1);        //retry=1�̸� �ٽ� �Է��ؾ��ϹǷ� do�������� ���ư�

 printf(">��ǻ�Ͱ� '%d'�� �����߽��ϴ�. \n", number2);
 return number2;

}


int u_count_bingo(int arr[N][N]){         // ���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ 
   int x, y, sum;                     // �� ���� ���� -1*N�� �Ǹ� ���� �̹Ƿ� sum ���� ����
   int made_bingo = 0;
      
   for(y=0; y<N; y++){         //x�� Ȯ�� 
      sum = 0;            //�� �� ���� ���ؾ��ϹǷ� sum �ʱ�ȭ 
      for(x=0; x<N; x++){
         sum += arr[y][x];
      }
      if(sum == -1*N){
        made_bingo++;
      }   
   } 
   
   for(x=0; x<N; x++){               //y�� Ȯ�� 
      sum=0;                     //sum �ʱ�ȭ
      for(y=0; y<N; y++){
         sum += arr[y][x];
      } 
      if(sum == -1*N){
        made_bingo++;
      }
   }
   
   sum = 0;                  // �밢���� ���ٻ��̹Ƿ� for���� �ۿ��� sum�ʱ�ȭ
   for(x=0; x<N; x++){            // �밢�� Ȯ�� 
      sum += arr[x][x];
   } 
   if(sum == -1*N){
    made_bingo++;
   }
   
   sum =0;
   for(x=0; x<N; x++){            // �밢�� Ȯ�� 
      sum+= arr[x][N -x-1];
   }
   if(sum == -1*N){
    made_bingo++;
   }
   
   if(made_bingo >= M){                 //count�� ���ڰ� M���� ������ Ȯ�� 
      return 1;                  // count_bingo =1 �̵Ǹ� ����   
   }

   else{
      return 0;               // count_bingo=0 �̵Ǹ� ���� ���ڰ� �����Ƿ� main�Լ����� do_while���� �� ���. 
   } 
}

int c_count_bingo(int arr[N][N]){         // ���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ 
   int x, y, sum;                     // �� ���� ���� -1*N�� �Ǹ� ���� �̹Ƿ� sum ���� ����
   int made_bingo = 0;                        // ���� ���� �밢�� ���� ������� ���� 

   for(y=0; y<N; y++){         //x�� Ȯ�� 
      sum = 0;            //�� �� ���� ���ؾ��ϹǷ� sum �ʱ�ȭ 
      for(x=0; x<N; x++){
         sum += arr[y][x];
      }
      if(sum == -1*N){
          made_bingo++;
      }
   } 
   
   for(x=0; x<N; x++){               //y�� Ȯ�� 
      sum = 0;                     //sum �ʱ�ȭ
      for(y=0; y<N; y++){
         sum += arr[y][x];   
      } 
      if(sum == -1*N){
        made_bingo++;
    }
   }
   
   sum = 0;                        // �밢���� for���� �ۿ��� sum�ʱ�ȭ
   for(x=0; x<N; x++){               // �밢�� Ȯ�� 
        sum += arr[x][x];
    } 
   if(sum == -1*N){
       made_bingo++;
   }
   
   sum =0;
   for(x=0; x<N; x++){            // �밢�� Ȯ�� 
      sum+= arr[x][N-x-1];
    }
   if(sum == -1*N){
      made_bingo++;
    }
   
   if(made_bingo >= M){                 //count�� ���ڰ� M���� ������ Ȯ�� 
      return 1;                  // count_bingo =1 �̵Ǹ� ����   
   }
   
   else{
      return 0;               // count_bingo=0 �̵Ǹ� ���� ���ڰ� �����Ƿ� main�Լ����� do_while���� �� ���. 
   }   
}

void print_winner(int winner){  // ���ڸ� ����ϴ� �Լ�
   switch(winner){
      case 1:                     //uwin =1 �϶�(����ڰ� �̱���) 
         printf("����ڰ� �̰���ϴ�.\n");
         break;
      case 2:                     //cwin=1 �϶�(��ǻ�Ͱ� �̱� ���) 
         printf("��ǻ�Ͱ� �̰���ϴ�.\n");
         break;
      case 3:                   //uwin=cwin=1 �϶�  
         printf("�����ϴ�.\n");
         break;
      default:
         printf("�����Դϴ�. \n");  //������ �߻��� ���
         break; 
   } 
}

