#include <iostream>
using namespace std;

// By the time the inner loop finishes a single run, 
// the absolute smallest remaining element is successfully locked into position i

/* Exchange Sort */
int main(){
    int arr[] = {3, 2, 4, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}