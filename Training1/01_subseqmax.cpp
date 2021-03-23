#include <bits/stdc++.h>
using namespace std;

#define MAX (unsigned int) 1e6

int n;
int input[MAX];
int s[MAX];
int max_sum = 0;


int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> input[i];

    s[0] = input[0];
    max_sum = s[0];
    for (int i = 1; i < n; ++i)
    {
        if (s[i-1] > 0) s[i] = s[i-1] + input[i];
        else s[i] = input[i];
        if (s[i] > max_sum) max_sum = s[i];
    }

    cout << max_sum;

    return 0;
}
