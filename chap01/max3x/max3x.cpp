#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm> // std::max를 사용하기 위해 추가

void max3(int* a, int* b, int* c);
int input();
void print(int *n);
void loop(int *n);

int main(void)
{
    srand(time(NULL));

    int n = rand() % 10 + 1;

    // n의 값을 출력
    std::cout << "최대 반복 횟수: " << n << std::endl;

    loop(&n);

    return 0;
}

void loop(int *n)
{
    for (int i = 0; i < *n; ++i)
    {
        int a = input();
        int b = input();
        int c = input();

        // 값(value)을 전달하여 print 함수 호출
        std::cout << "a: ";
    	print(&a);
        std::cout << "b: ";
    	print(&b);
        std::cout << "c: ";
    	print(&c);

        max3(&a, &b, &c);

        std::cout << "--------------------" << std::endl;
    }
}

int input()
{
    return rand() % 100;
}

void print(int *n)
{
    std::cout << *n << std::endl;
}

// max3 함수가 값을 반환하도록 수정
void max3(int* a, int* b, int* c)
{
    int n=std::max({ *a, *b, *c });
    std::cout << "max: ";
    print(&n);
}