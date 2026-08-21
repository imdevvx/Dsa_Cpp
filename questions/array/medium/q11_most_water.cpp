#include <iostream>
#include <vector>
using namespace std;

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.

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