#include <stdio.h> // scanf �Լ��� ����ϱ� ���� ����.
#include "AppIO.h" // AppIO.h�� ���ǵǾ� �ִ� �Լ��� �����ϱ� ���ؼ� ���. 

void AppIO_out_msg_startSolvingLinearEquation() { // ���� �޽��� ���
	printf("<<< ���������� Ǯ�̸� �����մϴ� >>>\n");
}
void AppIO_out_msg_endSolvingLinearEquation() { // ���� �޽��� ���.
	printf("\n<<< ���������� Ǯ�̸� �����մϴ� >>>\n");
}

Boolean AppIO_in_solvingIsRequested() { // ���������� Ǯ�̸� �� ������ ���� �޼ҵ�.
	char answer;
	printf("\n�������� Ǯ���� 'y', Ǯ�̸� �����Ϸ��� �ٸ� �ƹ� Ű�� ġ�ÿ�:");

	char inputLine[255];
	scanf("%s", inputLine); // return key�� �Է� �Ϸ�� �� ���� ������.
	answer = inputLine[0]; // ���ڿ��� ù ��° ���ڸ� �Է°����� �޴´�.
	if (answer == 'y')
		return TRUE;
	else
		return FALSE;
}