#include "header.h"

void main() {
   int number1, number2, uwin, cwin;
   int try_count=0;
   int i=0;
   int overlap = 0;
   
   initialize();         //������ �ʱ�ȭ
   
   do{
      printf("--<�����̰� ���� ������>--\n");
      print_bingo(ubingo);        //����� ������ ��� 
      
      number1 = get_number_byMe(0); 		//������� ��ȣ ���� 
      number2 = get_number_byCo(1);   		//��ǻ���� ��ȣ ����
     
	 /* number1, number2 ���� �����ϴ� �迭�� ����� �;���. �迭���� ������� number1,2 �� ����
	 ������ �� ���� number1, number2�� ���Ͽ� ���� ���� ������ filled_bingo�Լ� ����*/
	 
      stored[2*i] = number1;   				//¦��ĭ�� number1 �� �ֱ� 
      stored[2*i+1] = number2;   			//Ȧ��ĭ�� number2 �� �ֱ� ����������� 
	  
	  overlap++;
	  
	  try_count++;
      
      if(number1 != number2){				//number1�� number2�� �ٸ� ��� ���� -1�� ä��� 
      filled_bingo(ubingo, number1);
      filled_bingo(cbingo, number1);
      
      filled_bingo(ubingo, number2);
      filled_bingo(cbingo, number2);
 	 }
      else{									//do ������ ������� ������ ��
      	uwin=0; cwin=1; 
	  }
      uwin = u_count_bingo(ubingo);      // ���� �ϼ� Ȯ�� 
      cwin = c_count_bingo(cbingo);
     
      printf("�õ� Ƚ���� %d �Դϴ�\n\n", try_count); 
      
   } 
   while((uwin == 0) && (cwin ==0));   //1�� �Ǹ� ���ڰ� ����ϱ� �̴�� ���� 
   
   printf("--<����� ���-->\n");
   print_bingo(ubingo);         //������� ������ ��� 
   printf("\n");
   
   printf("--<��ǻ�� ���>--\n");
   print_bingo(cbingo);         //��ǻ���� ������ ��� 
   printf("\n");
   
   print_winner(cwin*2 + uwin);
   // ����ڰ� �̱��(uwin=1), case=1
   // ��ǻ�Ͱ� �̱��(cwin=1), case=2
   // ����(uwin=cwin=1), case=3 , �� �ܴ̿� ���� 
}


