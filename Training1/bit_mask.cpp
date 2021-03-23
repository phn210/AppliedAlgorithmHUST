#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a_size, b_size, tmp;
    set<int> a;
    vector<int> b;

    cin >> a_size;
    for (int i = 0; i < a_size; ++i)
    {
        cin >> tmp;
        a.insert(tmp);
    }

    cin >> b_size;
    for (int i = 0; i < b_size; ++i)
    {
        cin >> tmp;
        b.push_back(tmp);
    }

    for (int i = 0; i < b_size; ++i)
    {
        if(a.find(b.at(i)) == a.end())
        {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}
