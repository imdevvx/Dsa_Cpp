#include <iostream>
#include <vector>
using namespace std;

double myPow(double x, int n)
{
    long long binForm = n;
    if (n < 0)
    {
        x = 1.0 / x;
        binForm = -binForm;
    }

    double ans = 1.0;

    while (binForm > 0)
    {
        if (binForm % 2 == 1)
            ans *= x;
        x *= x;
        binForm /= 2;
    }

    return ans;
}

int main()
{
    double result = myPow(2, 5);
    cout << result;
    return 0;
}