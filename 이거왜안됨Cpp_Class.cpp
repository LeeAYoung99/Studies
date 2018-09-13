#include <iostream>
#include <cstring>

using namespace std;

class Student
{
    public:
    void SetInfo(char* _name, int _age, double _height)
    {
        strcpy(name,_name);
        age=_age;
        height=_height;
    }
        
    void Print()
    {
        cout << name <<endl;
        cout << age << endl;
        cout << height << endl;
    }
        
    private: //default가 private입니다.
    char* name;
    int age;
    double height;
        
};

int main()
{
    Student a;
    a.SetInfo("이아영",20,155.6);
    a.Print();

    return 0;
}
