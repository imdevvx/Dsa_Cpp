#include <iostream>
#include <vector>
using namespace std;

int findMajorityElement(vector<int> &nums)
{
    int candidate = 0;
    int count = 0;

    for (int num : nums)
    {
        if (count == 0)
        {
            candidate = num;
            count = 1;
        }
        else if (num == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    int actualCount = 0;
    for (int num : nums)
    {
        if (num == candidate)
        {
            actualCount++;
        }
    }

    if (actualCount > nums.size() / 2)
    {
        return candidate;
    }

    return -1;
}

int main()
{
    std::vector<int> numbers = {2, 2, 1, 1, 1, 2, 2};

    int result = findMajorityElement(numbers);

    if (result != -1)
    {
        std::cout << "The majority element is: " << result << std::endl;
    }
    else
    {
        std::cout << "No majority element found." << std::endl;
    }

    return 0;
}