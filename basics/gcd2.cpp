// GCD
#include <iostream>
using namespace std;

int factorCount(int num);
int *factors(int n);
void printFactors(int arr[], int size);
int computeGcd(int arr1[], int size1, int arr2[], int size2);

int main()
{
    int n1, n2;
    cout << "Enter two numbers to find GCD: ";
    cin >> n1 >> n2;

    cout << "factors of " << n1 << " are: ";
    int factors_n1 = factorCount(n1);
    int *arr1 = factors(n1);
    printFactors(arr1, factors_n1);

    cout << endl;
    
    cout << "factors of " << n2 << " are: ";
    int factors_n2 = factorCount(n2);
    int *arr2 = factors(n2);
    printFactors(arr2, factors_n2);
    
    cout << endl;

    int gcd = computeGcd(arr1, factors_n1, arr2, factors_n2);
    cout << "GCD is: " << gcd;

    delete[] arr1;
    delete[] arr2;

    return 0;
}

int factorCount(int num)
{
    int factors = 0;

    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            factors++;
        }
    }

    return factors;
}

int *factors(int n)
{
    int idx = 0;
    int factors_n = factorCount(n);
    int *factors_arr = new int[factors_n];

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            factors_arr[idx] = i;
            idx++;
        }
    }

    return factors_arr;
}

void printFactors(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int computeGcd(int arr1[], int size1, int arr2[], int size2)
{
    int gcd = 1;
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                if (arr1[i] > gcd)
                {
                    gcd = arr1[i];
                }
            }
        }
    }
    return gcd;
}