// Prime number
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n < 2)
    {
        cout << "Not prime";
        return 0;
    }

    bool prime = true;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            prime = false;
            break;
        }
    }

    cout << (prime ? "Prime" : "Not Prime");

    return 0;
}
