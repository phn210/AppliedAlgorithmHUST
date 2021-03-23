#include <iostream>
using namespace std;

int max(int a, int b, int c)
{
    int res = (a > b) ? a : b;
    if (res < c) res = c;
    return res;
}

int maxCrossingSum(int arr[], int left, int mid, int right)
{
    int sum = 0, max_sum = 0;
    for (int i = mid; i >= left ; --i)
    {
        sum += arr[i];
        max_sum = (max_sum >= sum)? max_sum : sum;
    }

    for (int i = mid + 1; i <= right ; ++i)
    {
        sum += arr[i];
        max_sum = (max_sum >= sum)? max_sum : sum;
    }
    return max_sum;
}


int maxSubArraySum(int arr[], int left, int right)
{
    if (left == right) return arr[left];

    int mid = (left + right)/2;

    return max(maxSubArraySum(arr, left, mid), maxSubArraySum(arr, mid+1, right), maxCrossingSum(arr, left, mid, right));
}

int main()
{
    int max_sum = 0;

    int n;
    cin >> n;

    int input[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> input[i];
    }

    /* algorithm */
    max_sum = maxSubArraySum(input, 0, n-1);


    cout << max_sum;

    return 0;
}
