#include <iostream>

using namespace std;

int FindNPOT(const int n)
{
    int CurrentNumber = n;
    int power = 1;

    if (CurrentNumber <= 0)
    {
        return 0;
    }

    while (true)
    {
        if (CurrentNumber > power)
        {
            power *= 2;
        }
        else
        {
            return power;
        }
    }
}

int main()
{
    int Counter = 0;
    string CounterString[3] = { "First :  ", "Second : ", "Thrid :  " };

    cout << "Number of Inputs : ";
    cin >> Counter;

    int* Inputs = new int[Counter];
    int Result = 0;

    for (int i = 0; i < Counter; i++)
    {
        cout << CounterString[i];
        cin >> Inputs[i];
    }

    Result = FindNPOT(Inputs[0]);

    for (int i = 1; i < Counter; i++)
    {
        Result ^= FindNPOT(Inputs[i]);
    }

    cout << Result << endl;

    return 0;
}