#include <iostream>

using namespace std;

int FindNPOT(const int n)
{
    int CurrentNumber = n;
    int power = 2;

    if (CurrentNumber <= 1)
    {
        return 2;
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

    cin >> Counter;

    if (Counter <= 0)
    {
        cout << 0 << endl;
        return 0;
	}

    int* Inputs = new int[Counter];

    for (int i = 0; i < Counter; ++i)
    {
		cout << "Enter number " << i + 1 << " : ";
        cin >> Inputs[i];
    }

    int Result = FindNPOT(Inputs[0]);

    for (int i = 1; i < Counter; ++i)
    {
        Result ^= FindNPOT(Inputs[i]);
    }

    cout << Result << endl;

    return 0;
}