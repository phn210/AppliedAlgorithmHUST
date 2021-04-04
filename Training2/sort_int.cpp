#include <bits/stdc++.h>
using namespace std;

int N;
int a[1000001];

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for(int i = 0; i < n1; ++i)
        L[i] = arr[l+i];
    for(int i = 0; i < n2; ++i)
        R[i] = arr[m+1+i];

    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2)
    {
        a[l+k] = (L[i] < R[j]) ? L[i++] : R[j++];
        k++;
    }

    while(i < n1)
    {
        a[l+k] = L[i++];
        k++;
    }
    while(j < n2)
    {
        a[l+k] = R[j++];
        k++;
    }
}

void merge_sort(int arr[], int l, int r)
{
    if (l >= r) return;
    int m = (l+r)/2;
    merge_sort(arr, l, m);
    merge_sort(arr, m+1, r);
    merge(arr, l, m, r);
}

int main()
{
    cin >> N;
    int tmp;
    for(int i = 0; i < N; ++i)
    {
        cin >> tmp;
        a[i] = tmp;
    }
    merge_sort(a, 0, N-1);
    for(int i = 0; i < N; ++i) cout << a[i] << " ";
    return 0;
}
