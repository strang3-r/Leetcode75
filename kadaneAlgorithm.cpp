// Time Complexity = O(n)
/*
    It calculates the maximum sum subarray ending at a particular position by using the maximum sum subarray ending at the previous position
*/

#include <iostream>
using namespace std;

int largestSubarraySum(int *arr, int n)
{
    int currentSum = 0;
    int largestSum = 0;
    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];
        if (currentSum < 0) // Does not calculates negative as it will only cause reduction in maximum sum
            currentSum = 0; // Instead of -ve it adds 0 for it
        largestSum = max(largestSum, currentSum);
    }

    return largestSum;
}

int main()
{
    system("CLS");
    int arr[] = {-10, 20, -30, 40, 50, 60, -70, 80, -90};
    int n = sizeof(arr) / sizeof(int);
    cout << largestSubarraySum(arr, n);

    return 0;
}
