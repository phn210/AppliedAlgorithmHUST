#include <bits/stdc++.h>

using namespace std;

map<char, int> number_pad =
{
            {'a', 1}, {'b', 2}, {'c', 3},
            {'d', 1}, {'e', 2}, {'f', 3},
            {'g', 1}, {'h', 2}, {'i', 3},
            {'j', 1}, {'k', 2}, {'l', 3},
            {'m', 1}, {'n', 2}, {'o', 3},
            {'p', 1}, {'q', 2}, {'r', 3}, {'s', 4},
            {'t', 1}, {'u', 2}, {'v', 3},
            {'w', 1}, {'x', 2}, {'y', 3}, {'z', 4},
            {' ', 1}
};

int N;
string S[10000];

int main()
{
    cin >> N;
    cin.ignore();
    int cnt = 0;
    for (int i = 0; i < N; ++i) getline(cin, S[i]);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < S[i].size(); ++j)
        {
            cnt += number_pad[S[i][j]];
        }
        cout << "Case #" << i+1 << ": " << cnt << endl;
        cnt = 0;
    }
    return 0;
}
