#include <iostream>

using namespace std;

long long FindNPOT(const long long n)
{
    long long CurrentNumber = n;
    long long power = 2;

    if (CurrentNumber <= 1)
    {
        return 2;
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

    long long* Inputs = new long long[Counter];

    cin >> Inputs[0];
	//Inputs[0] = ((long long)rand() << 47) + ((long long)rand() << 32) + ((long long)rand() << 17) + ((long long)rand() << 2) + (((long long)rand() % 2) * 2);

    long long Result = FindNPOT(Inputs[0]);

    for (int i = 1; i < Counter; ++i)
    {
        cin >> Inputs[i];
        //Inputs[i] = ((long long)rand() << 47) + ((long long)rand() << 32) + ((long long)rand() << 17) + ((long long)rand() << 2) + (((long long)rand() % 2) * 2);
		Result ^= FindNPOT(Inputs[i]);
    }

    cout << Result << endl;

    delete[] Inputs;

    return 0;
}