//�ϳ����� ž ������ ������Ų ����. N���� ��հ� 1���� ���Ѵ������ ������ �����ִ� ���� ���� ����.
//������ �� ���� ���� �������������� �ϰ� �� ���� �ϳ���, ��ȣ�� Ŀ���� ������ ��տ� ����� �����̴�.
//�� �̻� ���� �� ���� �Ǹ� ������ ������. ��ǥ�� �ִ��� ���� ������ ���� ����� ����
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int search(int ball_num, int *arr, int count); //ball_num: ���� ���� ��ȣ, arr: �� index���� ���� ����� ������ �ϴ� �迭
//���� ��� ��տ� ���������� ã�� �Լ�. ���� ����� ��ȣ�� ��ȯ�Ѵ�.
int dis_sqrt(int sum); //ball_num�� �������������� �Ǻ��ϴ� �Լ�.

int main(void) {
	int *arr;	//����� ������ �Է¹��� �� �����迭�� ����� �����ش�.
	int ball_num = 1;
	int count = 0; // �� ��° ������� �˷���.
	float sum = 0.0;
	int size = 0;
	int stick = 0;

	printf("����� ������ �Է��Ͻÿ�.");
	scanf("%d", &size);

	arr = (int*)calloc(size, sizeof(int));
	/*for (int i = 0; i < size; i++) {
		printf("%d\t", arr[i]);
	}*/
		

	int i = 1;
	while (1) {
		count = 0;
		stick = search(i, arr, count);//count�� ���� ���� ������ ����
		if (stick == -1)
			break;
		arr[stick] = i; //search�� ���� ã�� ��տ� ���� ����.
		//printf("arr[%d] : %d", stick, arr[stick]);
		i++;
	}
	printf("%d", i - 1);

	free(arr);
	return 0;
}

int search(int ball_num, int *arr, int count) {
	if (count == _msize(arr) / sizeof(int)) {
		//count�� �迭�� ũ�⸦ �Ѿ�� ��
		return -1;
	}
	if (dis_sqrt(ball_num + arr[count]) == 1) {//ball_num�� ������������ ���
		//printf("%d�� %d�� �����ϴ�.", ball_num, count);
		return count;
	}
	else { //ball_num�� ������������ �ƴ� ���
//�� ��� �ٸ� ����� Ž���Ѵ�.
		if (arr[count] == 0)
			return count;
		
		return search(ball_num, arr, ++count);
	}
}

int dis_sqrt(int sum) {
	if ((sqrt(sum) - (int)sqrt(sum)) == 0) //sum�� �������� �Ҽ� �κ��� 0�̸� sum�� �����������̴�.
		return 1;
	else
		return 0;
}