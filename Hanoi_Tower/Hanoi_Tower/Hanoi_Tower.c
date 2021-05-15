//하노이의 탑 문제를 변형시킨 문제. N개의 기둥과 1부터 무한대까지의 정수가 적혀있는 공에 관한 문제.
//인접한 두 공의 합이 완전제곱수여야 하고 한 번에 하나씩, 번호가 커지는 순서로 기둥에 끼우는 게임이다.
//더 이상 끼울 수 없게 되면 게임은 끝난다. 목표는 최대한 많은 개수의 공을 끼우는 것임
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int search(int ball_num, int *arr, int count); //ball_num: 끼울 공의 번호, arr: 각 index들이 개별 기둥의 역할을 하는 배열
//공을 어느 기둥에 끼워야할지 찾는 함수. 끼울 기둥의 번호를 반환한다.
int dis_sqrt(int sum); //ball_num이 완전제곱수인지 판별하는 함수.

int main(void) {
	int *arr;	//기둥의 개수를 입력받은 후 동적배열로 사이즈를 정해준다.
	int ball_num = 1;
	int count = 0; // 몇 번째 기둥인지 알려줌.
	float sum = 0.0;
	int size = 0;
	int stick = 0;

	printf("기둥의 개수를 입력하시오.");
	scanf("%d", &size);

	arr = (int*)calloc(size, sizeof(int));
	/*for (int i = 0; i < size; i++) {
		printf("%d\t", arr[i]);
	}*/
		

	int i = 1;
	while (1) {
		count = 0;
		stick = search(i, arr, count);//count가 뻑이 나기 전까지 돌림
		if (stick == -1)
			break;
		arr[stick] = i; //search를 통해 찾은 기둥에 공을 넣음.
		//printf("arr[%d] : %d", stick, arr[stick]);
		i++;
	}
	printf("%d", i - 1);

	free(arr);
	return 0;
}

int search(int ball_num, int *arr, int count) {
	if (count == _msize(arr) / sizeof(int)) {
		//count가 배열의 크기를 넘어가면 뻑
		return -1;
	}
	if (dis_sqrt(ball_num + arr[count]) == 1) {//ball_num이 완전제곱수인 경우
		//printf("%d는 %d에 꼈습니다.", ball_num, count);
		return count;
	}
	else { //ball_num이 완전제곱수가 아닌 경우
//이 경우 다른 기둥을 탐색한다.
		if (arr[count] == 0)
			return count;
		
		return search(ball_num, arr, ++count);
	}
}

int dis_sqrt(int sum) {
	if ((sqrt(sum) - (int)sqrt(sum)) == 0) //sum의 제곱근의 소수 부분이 0이면 sum은 완전제곱수이다.
		return 1;
	else
		return 0;
}