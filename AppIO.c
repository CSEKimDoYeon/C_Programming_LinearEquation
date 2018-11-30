#include <stdio.h> // scanf 함수를 사용하기 위해 선언.
#include "AppIO.h" // AppIO.h에 정의되어 있는 함수를 구현하기 위해서 사용. 

void AppIO_out_msg_startSolvingLinearEquation() { // 시작 메시지 출력
	printf("<<< 일차방적식 풀이를 시작합니다 >>>\n");
}
void AppIO_out_msg_endSolvingLinearEquation() { // 종료 메시지 출력.
	printf("\n<<< 일차방정식 풀이를 종료합니다 >>>\n");
}

Boolean AppIO_in_solvingIsRequested() { // 이차방정식 풀이를 할 것인지 묻는 메소드.
	char answer;
	printf("\n방정식을 풀려면 'y', 풀이를 종료하려면 다른 아무 키나 치시오:");

	char inputLine[255];
	scanf("%s", inputLine); // return key로 입력 완료된 한 줄을 가져옴.
	answer = inputLine[0]; // 문자열의 첫 번째 문자를 입력값으로 받는다.
	if (answer == 'y')
		return TRUE;
	else
		return FALSE;
}