/**
�л� ���� �Է��ϼ���: 5

1�� �л��� ����: 1

2�� �л��� ����: 2

3�� �л��� ����: 3

4�� �л��� ����: 4

5�� �л��� ����: 5

��� �л��� ���: 3


���� ������ new delete�����ڷ� ������!!
���� ���� ��ó: http://blog.eairship.kr/164?category=402649
*/

#include <iostream>

using namespace std;

int main()
{
    int studentNum;
    int *studentScore; // ���� �Ҵ��� ������ �����ͺ����� ����

    cout<< "�л� ���� �Է��ϼ���: ";
    cin >>studentNum;

    studentScore=new int[studentNum];

    //����=new �ڷ���[����]
    //malloc�� �ٸ� ��: ��ȯ�ϴ� �ڷ����� ���������� malloc�� void�� �����ͷ� ��ȯ��
    //int* ptr=new int(3); �� ��쿡��
    //ptr�� 3��¥�� ������ �迭�ϴ� ���� �ƴ϶� ptr�� ���� 3���� �ʱ�ȭ ��Ų�ٴ� ���̴�. ����!!!

    for(int i=0;i<studentNum;i++)
    {

        cout << studentNum+1 <<"�� ° �л��� ����:";
        cin >> studentScore[i];
    }

    for(int i=0;i<studentNum;i++)
    {
        cout <<studentNum+1 <<"�� ° �л��� ������"<<studentNum[i]<<"�Դϴ�."<<endl;
    }

    delete []studentScore;

    //��ü �迭�� ������ ��쿡�� delete[]�� ����.
    // �׳� ���� 0��° �迭�� ���� ������.

    return 0;
}
