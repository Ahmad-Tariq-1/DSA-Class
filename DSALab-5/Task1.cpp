#include <iostream>
using namespace std;

void testFunction1()
{
    while (false)
    {
        cout << "\nUseless while loop" << endl;
    }
}

void testFunction2()
{
    if (false)
    {
        cout << "\nThis if block will never run" << endl;
    }
}

void testFunction3()
{
    return;

    cout << "\nThis code will never be executed" << endl;
}

int main()
{
    testFunction1();
    testFunction2();
    testFunction3();

    return 0;
}
