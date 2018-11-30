
#include <math.h>

#include "Common.h"
#include "AppIO.h"

float LinearEquation_solve(float c0, float c1) { // �־��� ����� ���� ������������ �ظ� ���Ѵ�.
	if (FloatValueIsZero(c1)) { // 1������ ����� 0������ �˻�
		if (c1*c0 >= 0.0) { // �� ����� ��ȣ�� ���ٸ�
			return -MAXFLOAT; // 1������ ����� 0�̸� ����� -����
		}
		else {
			return +MAXFLOAT; // 1������ ����� 0�̸� ����� +����
		}
	}
	else {
		return (-c0) / c1; // �������� ��쿡 �ظ� return �Ѵ�.
	}
}
// �����ؾ��Ѵ�.

void AppIO_out_linearEquation(float c0, float c1) {
	printf(">�־��� ������ : (%.1f)x + (%.1f) = 0 \n", c1, c0); // �Է¹��� ����� ������ ����Ѵ�.
} 

void AppIO_out_root(float root) { // ����� �ظ� ����Ѵ�.
	printf(">�������� �ش� ������ �����ϴ�:\n");
	printf("x = %.1f\n", root);
}

void AppIO_in_linearEquation(float* p_c0, float* p_c1) { // 1����, ������� ����� �Է¹޴´�.
	printf("1�� ���� ����� �Է��Ͻÿ�:");
	scanf_s("%f", p_c1);
	printf("������� ����� �Է��Ͻÿ�:");
	scanf_s("%f", p_c0);
}

void AppIO_out_msg_firstOrderTermCoefficientIsZero() { // 1������ ����� 0�� ��� ���� �޽����� ����.
	printf("[����] 1������ ����� 0�̿���, �������� Ǯ �� �����ϴ�.\n");
}

int main(void) {
	Boolean solvingIsRequested;
	float c0, c1;
	float root;

	AppIO_out_msg_startSolvingLinearEquation();
	solvingIsRequested = AppIO_in_solvingIsRequested();

	while (solvingIsRequested) {
		//�ݺ��� �ϼ��� ����, �̰��� ä���.
		AppIO_in_linearEquation(&c0, &c1); // ���� �������� ����� �Է� �޴´�.
		AppIO_out_linearEquation(c0, c1); // �Է� ���� ������������ �����ش�.
		if (FloatValueIsZero(c1)) { // �������� ����� 0�̸�
			AppIO_out_msg_firstOrderTermCoefficientIsZero(); // �������� ����� 0�̶�� �޽��� ���
		}
		else {
			root = LinearEquation_solve(c0, c1); // ������������ Ǭ��.
			AppIO_out_root(root); // ������������ �ظ� ����Ѵ�.
		}
		solvingIsRequested = AppIO_in_solvingIsRequested();
	}
	AppIO_out_msg_endSolvingLinearEquation();

	system("pause");
	return 0;
}