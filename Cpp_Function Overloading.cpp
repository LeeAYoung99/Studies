#include <iostream>

using namespace std;

// 함수 오버로딩은 C와 다른 C++의 특징으로
// 함수이름이 같아도 인자의 자료형이 다르거나, 인자의 개수가 다르면 다른 기능을 수행하게 해준다!

int func(int a, int b)
{
    return a+b;
}

int func(double a, double b)
{
    return a/b;
}

int func(char a)
{
    return a;
}

int main()
{
    int x=2,y=3;
    double c=2.5,d=7.3;
    char e='e';

    cout<<func(x,y)<<func(c,d)<<func(e)<<endl;

    return 0;
}
