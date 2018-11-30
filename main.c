
#include <math.h>

#include "Common.h"
#include "AppIO.h"

float LinearEquation_solve(float c0, float c1) { // 주어진 계수를 갖는 일차방정식의 해를 구한다.
	if (FloatValueIsZero(c1)) { // 1차항의 계수가 0인지를 검사
		if (c1*c0 >= 0.0) { // 두 계수의 부호가 같다면
			return -MAXFLOAT; // 1차항의 계수가 0이면 결과는 -무한
		}
		else {
			return +MAXFLOAT; // 1차항의 계수가 0이면 결과는 +무한
		}
	}
	else {
		return (-c0) / c1; // 정상적인 경우에 해를 return 한다.
	}
}
// 구현해야한다.

void AppIO_out_linearEquation(float c0, float c1) {
	printf(">주어진 방정식 : (%.1f)x + (%.1f) = 0 \n", c1, c0); // 입력받은 계수의 정보를 출력한다.
} 

void AppIO_out_root(float root) { // 계산한 해를 출력한다.
	printf(">방정식의 해는 다음과 같습니다:\n");
	printf("x = %.1f\n", root);
}

void AppIO_in_linearEquation(float* p_c0, float* p_c1) { // 1차항, 상수항의 계수를 입력받는다.
	printf("1차 항의 계수를 입력하시오:");
	scanf_s("%f", p_c1);
	printf("상수항의 계수를 입력하시오:");
	scanf_s("%f", p_c0);
}

void AppIO_out_msg_firstOrderTermCoefficientIsZero() { // 1차항의 계수가 0일 경우 에러 메시지를 띄운다.
	printf("[오류] 1차항의 계수가 0이여서, 방정식을 풀 수 없습니다.\n");
}

int main(void) {
	Boolean solvingIsRequested;
	float c0, c1;
	float root;

	AppIO_out_msg_startSolvingLinearEquation();
	solvingIsRequested = AppIO_in_solvingIsRequested();

	while (solvingIsRequested) {
		//반복을 완성한 다음, 이곳을 채운다.
		AppIO_in_linearEquation(&c0, &c1); // 일차 방정식의 계수를 입력 받는다.
		AppIO_out_linearEquation(c0, c1); // 입력 받은 일차방정식을 보여준다.
		if (FloatValueIsZero(c1)) { // 일차항의 계수가 0이면
			AppIO_out_msg_firstOrderTermCoefficientIsZero(); // 일차항의 계수가 0이라는 메시지 출력
		}
		else {
			root = LinearEquation_solve(c0, c1); // 일차방정식을 푼다.
			AppIO_out_root(root); // 일차방정식의 해를 출력한다.
		}
		solvingIsRequested = AppIO_in_solvingIsRequested();
	}
	AppIO_out_msg_endSolvingLinearEquation();

	system("pause");
	return 0;
}