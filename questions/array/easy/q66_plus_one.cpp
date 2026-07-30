#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> plusOne(vector<int>& digits) {

    for (int i = digits.size() - 1; i >= 0; i--) {

        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        }

        digits[i] = 0;
    }

    digits.insert(digits.begin(), 1); // for edge cases like {9, 9, 9, 9}

    return digits;
}

int main()
{
    vector <int> digits = {1, 2, 3, 4, 9};
    auto result = plusOne(digits);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}




// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// int main()
// {
//     vector<int> digits = {4, 3, 2, 1};

//     int num = 0;
//     for (int i = 0; i < digits.size(); i++)
//     {
//         num = (num * 10) + digits[i];
//     }
//     num++;
//     string strNum = to_string(num);
//     int numLength = strNum.length();
//     digits.resize(numLength);

//     // cout << strNum << " " << strNum[1];

//     for (int i = 0; i < numLength; i++)
//     {
//         digits[i] = strNum[i] - '0'; // convert each ch back to int
//     }


//     for (int i = 0; i < numLength; i++)
//     {
//         cout << digits[i];
//     }
    

//     return 0;
// }