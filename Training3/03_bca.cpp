#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> T;
int conflict[30][30];

void input()
{
    int tmp1, tmp2, tmp3;
    vector<int> tmp;
    cin >> m >> n;
    for(int i = 0; i < m; ++i)
    {
        cin >> tmp1;
        for(int j = 0; j < tmp1; ++j)
        {
            cin >> tmp2;
            tmp.push_back(tmp2);
        }
        T.push_back(tmp);
    }
    cin >> tmp3;
    for(int i = 0; i < tmp3; ++i)
    {
        cin >> tmp1 >> tmp2;
        conflict[tmp1-1][tmp2-1] = 1;
        conflict[tmp2-1][tmp1-1] = 1;
    }
}

void solve()
{

}

int main()
{
    input();
    solve();
    return 0
}
