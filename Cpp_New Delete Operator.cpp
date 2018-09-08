/**
학생 수를 입력하세요: 5

1번 학생의 점수: 1

2번 학생의 점수: 2

3번 학생의 점수: 3

4번 학생의 점수: 4

5번 학생의 점수: 5

모든 학생의 평균: 3


다음 예제를 new delete연산자로 만들자!!
원본 문제 출처: http://blog.eairship.kr/164?category=402649
*/

#include <iostream>

using namespace std;

int main()
{
    int studentNum;
    int *studentScore; // 동적 할당할 변수를 포인터변수로 선언

    cout<< "학생 수를 입력하세요: ";
    cin >>studentNum;

    studentScore=new int[studentNum];

    //변수=new 자료형[길이]
    //malloc과 다른 점: 반환하는 자료형이 정해져있음 malloc은 void형 포인터로 반환됨
    //int* ptr=new int(3); 의 경우에는
    //ptr에 3개짜리 공간을 배열하는 것이 아니라 ptr의 값을 3으로 초기화 시킨다는 점이다. 주의!!!

    for(int i=0;i<studentNum;i++)
    {

        cout << studentNum+1 <<"번 째 학생의 점수:";
        cin >> studentScore[i];
    }

    for(int i=0;i<studentNum;i++)
    {
        cout <<studentNum+1 <<"번 째 학생의 점수는"<<studentNum[i]<<"입니다."<<endl;
    }

    delete []studentScore;

    //객체 배열을 삭제할 경우에는 delete[]를 쓴다.
    // 그냥 쓰면 0번째 배열의 값만 삭제됨.

    return 0;
}
