#include <iostream>
#include <vector>
#include <numeric> // required for accumulate
#include <cmath>   // required for accumulate
using namespace std;

/*
You are given a positive integer n. Determine whether n is divisible by the sum of the following two values:
The digit sum of n (the sum of its digits).
The digit product of n (the product of its digits).
Return true if n is divisible by this sum; otherwise, return false.
*/

bool checkDivisibility(int num)
{
    if (num == 0)
        return false; // division by 0 is undefined

    int temp = abs(num);
    int digit_sum = 0;
    int digit_product = 1;

    while (temp > 0)
    {
        int digit = temp % 10;

        digit_sum += digit;
        digit_product *= digit;

        temp /= 10;
    }

    int combined_sum = digit_sum + digit_product;

    if (combined_sum == 0)
        return false;

    return (num % combined_sum == 0);
}

int main()
{
    int n = 99;
    bool result = checkDivisibility(n);
    cout << result;
    return 0;
}