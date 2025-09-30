#include <iostream>

using namespace std;

unsigned long long FindNPOT(const unsigned long long n)
{
    unsigned long long CurrentNumber = n;
    unsigned long long power = 2;

    if (CurrentNumber <= 1)
    {
        return power;
    }

    while (true)
    {
        if (CurrentNumber > power)
        {
            power = power << 1;
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

    if (Counter <= 0 || Counter > (1 << 18))
    {
        cout << 0 << endl;
        return 0;
	}

    unsigned long long* Inputs = new unsigned long long[Counter];

    //cin >> Inputs[0];
	Inputs[0] = ((unsigned long long)rand() << 48) + ((unsigned long long)rand() << 33) + ((unsigned long long)rand() << 18) + ((long long)rand() << 3) + (((unsigned long long)rand() % 4) << 1);

    unsigned long long Result = FindNPOT(Inputs[0]);

    for (int i = 1; i < Counter; ++i)
    {
        //cin >> Inputs[i];
        Inputs[i] = ((unsigned long long)rand() << 48) + ((unsigned long long)rand() << 33) + ((unsigned long long)rand() << 18) + ((unsigned long long)rand() << 3) + (((unsigned long long)rand() % 4) << 1);
		Result ^= FindNPOT(Inputs[i]);
    }

    cout << endl << Result << endl;

    delete[] Inputs;

    return 0;
}