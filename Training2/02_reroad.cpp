#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> road;
vector<pair<int, int>> fixes;

void input()
{
    int tmp;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> tmp;
        road.push_back(tmp);
    }
    int tmp1, tmp2;
    cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        cin >> tmp1 >> tmp2;
        fixes.push_back(make_pair(tmp1, tmp2));
    }
}

void solve()
{
    int bump = 1;
    for (int i = 0; i < (N - 1); ++i)
        if (road.at(i) != road.at(i+1)) bump++;
    for (int i = 0; i < Q; ++i)
    {
        pair<int, int> fix = make_pair(fixes.at(i).first-1, fixes.at(i).second);
        if(!(fix.second == road.at(fix.first)))
        {
            if(fix.first > 0)
            {
                if(road.at(fix.first) == road.at(fix.first - 1)) bump++;
                else if(fix.second == road.at(fix.first - 1)) bump--;
            }

            if(fix.first < (N - 1))
            {
                if(road.at(fix.first) == road.at(fix.first + 1)) bump++;
                else if(fix.second == road.at(fix.first + 1)) bump--;
            }
            road.at(fix.first) = fix.second;
        }
        cout << bump << endl;
    }
}

int main()
{
    input();
    solve();
    return 0;
}
