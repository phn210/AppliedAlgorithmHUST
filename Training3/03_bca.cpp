#include <bits/stdc++.h>
using namespace std;

#define MAX_COURSES 30+1
#define MAX_TEACHERS 10+1

int C, T; // T = m, C = n
vector<int> t[MAX_COURSES]; // array of teachers available for each course
int conflict[MAX_COURSES][MAX_COURSES];
int x[MAX_COURSES];
int load[MAX_TEACHERS];
int best = numeric_limits<int>::max();
bool found = false;

void input()
{
    int tmp1, tmp2, tmp3;
    cin >> T >> C;

    for(int i = 1; i <= C; ++i)
    {
        t[i].empty();
    }

    for(int i = 0; i < T; ++i)
    {
        cin >> tmp1;
        for(int j = 0; j < tmp1; ++j)
        {
            cin >> tmp2;
            t[tmp2].push_back(i+1);
        }
    }

    cin >> tmp3;
    for(int i = 0; i < tmp3; ++i)
    {
        cin >> tmp1 >> tmp2;
        conflict[tmp1][tmp2] = 1;
        conflict[tmp2][tmp1] = 1;
    }

}

bool check(int g, int k)
{
    for(int i = 1; i < k; ++i)
    {
        if(conflict[i][k] && x[i] == g) return false;
    }
    return true;
}

void solution()
{
    found = true;
    int res = 0;
    for(int i = 1; i <= T; ++i)
    {
        if(load[i] > res) res = load[i];
    }
    if(res < best) best = res;
}

void TRY(int k) //try for each course
{
    for(int i = 0; i < t[k].size(); ++i)
    {
        int g = t[k][i];
        if(check(g, k))
        {
            x[k] = g;
            load[g]++;
            if(k == C) solution();
            else
            {
                if (load[g] < best) TRY(k+1);
            }
            load[g]--;
        }
    }
}

void solve()
{
    TRY(1);
    if(!found) best = -1;
    cout << best;
}

int main()
{
    input();
    solve();
    return 0;
}
