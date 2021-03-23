#include <bits/stdc++.h>

using namespace std;

#define MAX 100

int N;
string wlist[MAX], tmp;

int main()
{
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; ++i) getline(cin, wlist[i]);
    for (int i = 0; i < N; ++i)
    {
        tmp = wlist[i];
        if (tmp.size() > 10)
        {
            cout << tmp[0] << tmp.size() - 2 << tmp[tmp.size()-1] << endl;
        }
        else cout << tmp << endl;
    }

    return 0;
}
