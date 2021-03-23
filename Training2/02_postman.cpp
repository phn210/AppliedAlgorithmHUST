#include <bits/stdc++.h>
using namespace std;

int N, k;

class mycomparison
{
    bool reverse;
public:
    mycomparison(const & revparam = false)
    { reverse = revparam;}
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) const
    {
        if (reverse) return (lhs.first > rhs.first);
        else return (lhs.first < rhs.first);
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> customers_n;
priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> customers_p;

void input()
{
    int tmp1, tmp2;
    cin >> N >> k;
    for (int i = 0; i < N; ++i)
    {
        cin >> tmp1 >> tmp2;
        if (tmp1 > 0) customers_p.push(make_pair(tmp1, tmp2));
        else customers_n.push(make_pair(-tmp1, tmp2));
    }
}

void solve()
{
    unsigned long long d = 0, pre = 0;
    while(!customers_n.empty())
    {
        pair<int, int> top = customers_n.top();
        if (pre >= top.second)
        {
            pre -= top.second;
        }
        else
        {
            int r = ((top.second-pre)%k == 0) ? 0 : 1;
            d += 2*top.first*((top.second-pre)/k + r);
            pre = (k - (top.second-pre) % k) % k;
        }
        customers_n.pop();
    }
    pre = 0;
    while(!customers_p.empty())
    {
        pair<int, int> top = customers_p.top();
        if (pre >= top.second)
        {
            pre -= top.second;
        }
        else
        {
            int r = ((top.second-pre)%k == 0) ? 0 : 1;
            d += 2*top.first*((top.second-pre)/k + r);
            pre = (k - (top.second-pre) % k) % k;
        }
        customers_p.pop();

    }
    cout << d << endl;
}

int main()
{
    input();
    solve();
    return 0;
}
