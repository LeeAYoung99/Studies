#include <iostream>

using namespace std;

// �Լ� �����ε��� C�� �ٸ� C++�� Ư¡����
// �Լ��̸��� ���Ƶ� ������ �ڷ����� �ٸ��ų�, ������ ������ �ٸ��� �ٸ� ����� �����ϰ� ���ش�!

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
