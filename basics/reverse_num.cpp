// Reverse a number
#include <iostream>
#include <string>
using namespace std;

int main(){
    int n = 54321;
    string strnum = to_string(n);

    for (int i = strnum.length() - 1; i >= 0; i--)
    {
        cout << strnum[i];
    }
    
    return 0;
}



