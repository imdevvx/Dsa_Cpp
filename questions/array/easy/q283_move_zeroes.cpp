#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int writePointer = 0;

    // move all non-zero elem forward
    for (int readPointer = 0; readPointer < nums.size(); readPointer++)
    {
        if (nums[readPointer] != 0)
        {
            nums[writePointer] = nums[readPointer];
            writePointer++;
        }
    }

    while (writePointer < nums.size()){
        nums[writePointer] = 0;
        writePointer++;
    }
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}