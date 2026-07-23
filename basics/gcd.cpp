// GCD
#include <iostream>
using namespace std;

int main(){
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }

    cout << "GCD is: " << a;
    return 0;
}

/*
DRY RUN {a = 18 and b = 24}

Iteration 1 -:
int temp = b; // temp = 24
b = a % b; // b = 18 % 24 = 18
a = temp; // a = 24

Iteration 2 -:
int temp = b; // temp = 18
b = a % b; // b = 24 % 18 = 6
a = temp; // a = 18

Iteration 3 -:
int temp = b; // temp = 6
b = a % b; // b = 18 % 6 = 0
a = temp; // a = 6

Now since `b != 0`, the loop stops.
*/