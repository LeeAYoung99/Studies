#include <iostream>

using namespace std;

//std::cout std::cin

namespace A
{
    void print()
    {
        cout << "AAAAA" << endl;
    }
}

namespace B
{
    void print()
    {
        cout << "BBBBB" << endl;
    }
}

int main()
{
    A::print();
    B::print();

    return 0;
}
