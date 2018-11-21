#include "header.h"

void main() {
   int number1, number2, uwin, cwin;
   int try_count=0;
   int i=0;
   int overlap = 0;
   
   initialize();         //빙고판 초기화
   
   do{
      printf("--<상은이가 만든 빙고판>--\n");
      print_bingo(ubingo);        //사용자 빙고판 출력 
      
      number1 = get_number_byMe(0); 		//사용자의 번호 선택 
      number2 = get_number_byCo(1);   		//컴퓨터의 번호 선택
     
	 /* number1, number2 값을 저장하는 배열을 만들고 싶었음. 배열에는 순서대로 number1,2 값 저장
	 저장한 후 다음 number1, number2와 비교하여 같은 수가 없으면 filled_bingo함수 실행*/
	 
      stored[2*i] = number1;   				//짝수칸에 number1 값 넣기 
      stored[2*i+1] = number2;   			//홀수칸에 number2 값 넣기 순서상관없이 
	  
	  overlap++;
	  
	  try_count++;
      
      if(number1 != number2){				//number1과 number2가 다를 경우 빙고 -1로 채우기 
      filled_bingo(ubingo, number1);
      filled_bingo(cbingo, number1);
      
      filled_bingo(ubingo, number2);
      filled_bingo(cbingo, number2);
 	 }
      else{									//do 구문을 벗어나지만 않으면 됨
      	uwin=0; cwin=1; 
	  }
      uwin = u_count_bingo(ubingo);      // 빙고 완성 확인 
      cwin = c_count_bingo(cbingo);
     
      printf("시도 횟수는 %d 입니다\n\n", try_count); 
      
   } 
   while((uwin == 0) && (cwin ==0));   //1이 되면 승자가 생기니까 이대로 진행 
   
   printf("--<사용자 결과-->\n");
   print_bingo(ubingo);         //사용자의 빙고판 출력 
   printf("\n");
   
   printf("--<컴퓨터 결과>--\n");
   print_bingo(cbingo);         //컴퓨터의 빙고판 출력 
   printf("\n");
   
   print_winner(cwin*2 + uwin);
   // 사용자가 이기면(uwin=1), case=1
   // 컴퓨터가 이기면(cwin=1), case=2
   // 비기면(uwin=cwin=1), case=3 , 그 이외는 에러 
}


