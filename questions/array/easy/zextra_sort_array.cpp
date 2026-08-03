#include <iostream>
#include <vector>
using namespace std;

void mySort(vector<int> &nums);
void bubbleSort(vector<int> &nums);
void selectionSort(vector<int> &nums);


void printVector(vector<int> vec)
{
    for (int num : vec)
    {
        cout << num << " ";
    }
}

int main()
{
    vector<int> nums = {5, 3, 6, 4, 1, 2};

    // mySort(nums);
    // bubbleSort(nums);
    // selectionSort(nums);

    printVector(nums);

    return 0;
}

void mySort(vector<int> &nums)
{
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (nums[i] > nums[j])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

void bubbleSort(vector<int> &nums)
{
    int size = nums.size();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

void selectionSort(vector<int> &nums)
{
    int size = nums.size();
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (nums[j] < nums[minIndex])
            {
                minIndex = j;
            }
        }

        swap(nums[i], nums[minIndex]);
    }
}

