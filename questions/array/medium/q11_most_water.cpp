#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;

    int max_area = 0;

    while (left < right)
    {
        int current_height = min(height[left], height[right]);
        int width = right - left;
        max_area = max(current_height * width, max_area);

        if (height[left] < height[right])
            left++;
        else // if height[left] > height[right] or height[left] == height[right]
            right--;
    }

    return max_area;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = maxArea(height);
    cout << result;
    return 0;
}