#include<iostream>
#include <cmath>
using namespace std;

class Progression
{
protected:
    double current;

public:
    Progression(double start = 0.0) : current(start) {}

    virtual double nextValue()
    {
        return ++current;
    }

    void printProgression(int n)
    {
        cout << "\t"<<current;
        for (int i = 1; i < n; i++)
        {
            cout << " " << nextValue();
        }
        cout << endl;
    }
};

class SqrtProgression : public Progression
{
public:
    SqrtProgression() : Progression(65536.0) {}

    SqrtProgression(double start) : Progression(start) {}

    virtual double nextValue() override
    {
        current = sqrt(current);
        return current;
    }
};

int main()
{
    int numTerms;
    cout << "\n\tEnter the number of terms you want to print: ";
    cin >> numTerms;

    cout << "\n\tDefault Square Root Progression (starting with 65,536):" << endl;
    SqrtProgression defaultProg;
    defaultProg.printProgression(numTerms); 

    int userValue;
    cout << "\n\tEnter a value for custom progression: ";
    cin >> userValue;

    cout << "\n\tCustom Square Root Progression (starting with "<<userValue<<"): " << endl;
    SqrtProgression customProg(userValue);
    customProg.printProgression(numTerms); 
    return 0;
}