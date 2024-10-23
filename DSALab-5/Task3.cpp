#include<iostream>
using namespace std;

class Progression
{
protected:
    int current;

public:
    Progression(int start = 0)
    {
        current = start;
    }
    virtual int nextValue()
    {
        return ++current;
    }
    void printProgression(int n)
    {
        cout <<"\t"<< current;
        for (int i = 1; i < n; i++)
        {
            cout << " " << nextValue();
        }
        cout << endl;
    }
};

class AbsDiffProgression : public Progression
{
private:
    int prev;

    int abs(int x)
    {
        if (x < 0)
        {
            return -x;
        }
        else
        {
            return x;
        }
    }

public:
    AbsDiffProgression()
    {
        current = 200;
        prev = 2;
    }

    AbsDiffProgression(int first, int second)
    {
        current = second;
        prev = first;
    }

    virtual int nextValue() override
    {
        int temp = current;
        current = abs(current - prev);
        prev = temp;
        return current;
    }
};

int main()
{
    int numTerms;

    cout << "\n\tEnter the number of terms you want to print: ";
    cin >> numTerms;

    cout << "\n\tDefault Progression (starting with 2 and 200): " << endl;
    AbsDiffProgression defaultProg;
    defaultProg.printProgression(numTerms);

    int first, second;
    cout << "\n\tEnter the first value for custom progression: ";
    cin >> first;
    cout << "\tEnter the second value for custom progression: ";
    cin >> second;

    AbsDiffProgression customProg(first, second);
    customProg.printProgression(numTerms);

    return 0;
}
