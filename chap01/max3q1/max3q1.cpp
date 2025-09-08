#include<iostream>
#include<cstdlib>
#include<ctime>
//#include<algorithm>

int input();
int* create_array(int size);
int MAX(int* ary, int size);
int MIN(int* ary, int size);
void print_array(int* ary, int size);

int main(void)
{
    srand(time(NULL));

    int size = 4;
    int* p = create_array(size);

    // 동적 할당된 배열의 값이 정상적으로 들어갔는지 확인
    std::cout << "배열 내용: ";
    print_array(p, size);

    int max = MAX(p, size);
    int min = MIN(p, size);

    std::cout << "max: " << max << std::endl;
    std::cout << "min: " << min << std::endl;

    // 메모리 해제
    free(p);
    p = nullptr;

    return 0;
}

// 동적 배열을 생성하고 값을 채워 반환
int* create_array(int size)
{
    int* ary = (int*)malloc(size * sizeof(int));
    if (ary == NULL) 
    {
        std::cerr << "메모리 할당 실패" << std::endl;
        exit(1);
    }

    for (int i = 0; i < size; ++i)
    {
        ary[i] = input();
    }
    return ary;
}

// 0-99 사이의 무작위 정수 반환
int input()
{
    return rand() % 100;
}

// 배열을 순회하며 최댓값 반환
int MAX(int* ary, int size)
{
    if (size <= 0) 
        return -1; // 예외 처리

    int max_val = ary[0];
    for (int i = 1; i < size; ++i)
    {
        if (max_val < ary[i])
            max_val = ary[i];
    }
    return max_val;
}

// 배열을 순회하며 최솟값 반환
int MIN(int* ary, int size)
{
    if (size <= 0) 
        return -1; // 예외 처리

    int min_val = ary[0];
    for (int i = 1; i < size; ++i)
    {
        if (min_val > ary[i])
            min_val = ary[i];
    }
    return min_val;
}

// 배열 내용 출력
void print_array(int* ary, int size)
{
    for (int i = 0; i < size; ++i) 
    {
        std::cout << ary[i] << " ";
    }
    std::cout << std::endl;
}