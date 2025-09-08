#include<iostream>
#include<cstdlib>
#include<ctime>

// 함수 선언
int med3(int* ary);
void swap(int* a, int* b);

int main(void)
{
    srand(time(NULL));
    int n = 3;

    // 동적 배열 할당
    int* ary = (int*)malloc(sizeof(int) * n);
    if (ary == NULL) {
        std::cerr << "메모리 할당 실패" << std::endl;
        return 1;
    }

    // 배열에 값 할당
    std::cout << "배열 내용: ";
    for (int i = 0; i < n; i++)
    {
        ary[i] = rand() % 100;
        std::cout << ary[i] << " ";
    }
    std::cout << std::endl;

    // 중간값 찾기
    int mid = med3(ary);

    std::cout << "중간값: " << mid << std::endl;

    // 메모리 해제
    free(ary);

    return 0;
}

int med3(int* ary)
{
    // ary[0]이 중간값인 경우:
    if
	((ary[1] >= ary[0] && ary[0] >= ary[2]) || (ary[1] <= ary[0] && ary[0] <= ary[2]))
        return ary[0];

    // ary[1]이 중간값인 경우:
    else if
	((ary[0] >= ary[1] && ary[1] >= ary[2]) || (ary[0] <= ary[1] && ary[1] <= ary[2]))
        return ary[1];

    // 그 외의 경우 (ary[2]가 중간값):
    else
        return ary[2];
}