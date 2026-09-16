#include <iostream>
using namespace std;

long long catalan(int n)
{
    long long result = 1; // C0 = 1

    for (int i = 1; i <= n; i++)
    {
        result = result * 2 * (2 * i - 1) / (i + 1);
    }

    return result;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << catalan(n) << endl;

    return 0;
}

long long catalan2(int n)
{
    long long ans = 1;
    // Calculate C(2n, n)
    for (int i = 1; i <= n; i++)
    {
        ans = ans * (n + i) / i;
    } 
    // Catalan = C(2n, n) / (n + 1)
    return ans / (n + 1);
}
/*
catalan2 explaination -:
We know 
C(2n, n) = (2n)! / (n! × (2n-n)!) & thus
C(2n, n) = (2n)! / (n! × n!)

if n = 4; we have
C(8, 4) = 8! / 4!4!
= (8 × 7 × 6 × 5 × 4!) / (4 × 3 × 2 × 1 × 4!)
= (8 × 7 × 6 × 5) / (4 × 3 × 2 × 1)
= (5 × 6 × 7 × 8)/ (1 × 2 × 3 × 4)

now instead of calculating 8! and 4!, we calculate step by step
ans = 1,
1 × 5/1 = 5 // ans = 5
5 × 6/2 = 15 // ans = 15
15 × 7/3 = 35 ..
35 × 8/4 = 70 ..

So C(8, 4) = 70
and catalan = C4 = C(8, 4)/ (n + 1) = 70/5 = 14
*/

/*
Catalan number recurrence relation:

C(n) = C(n-1) × 2(2n - 1)/(n + 1)
*/

/*
Catalan number formula:

C(n) = 1/(n+1) × C(2n, n)

1. Expand the binomial coefficient

C(2n, n) = (2n)! / (n! (2n-n)!),
C(2n, n) = (2n)! / (n! × n!)

Substitute this into the Catalan formula:

C(n) = 1/(n+1) × (2n)! / (n! × n!)

2. Combine the terms

C(n) = (2n)! / ((n+1) × n! × n!)

Now notice that,
(n+1) × n! = (n+1)!

because, by definition,
(n+1)! = (n+1) × n!

Therefore: C(n) = (2n)! / ((n+1)! × n!)
*/