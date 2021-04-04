#include <bits/stdc++.h>
using namespace std;

int N;
vector<tuple<int, int, vector<int>, vector<int>>> tests;
/*
struct pair_hash {
    std::size_t operator () (const pair<int, int> &p) const {
        auto h1 = std::hash<int>{}(p.first);
        auto h2 = std::hash<int>{}(p.second);

        return h1 ^ h2;
    }
};
*/
void input()
{
    cin >> N;
    int tmpL, tmpC, tmp;
    vector<int> tmp1, tmp2;
    for (int i = 0; i < N; ++i)
    {
        cin >> tmpL >> tmpC;
        for(int j = 0; j < tmpL*tmpC; ++j)
        {
            cin >> tmp;
            tmp1.push_back(tmp);
        }
        for(int j = 0; j < tmpL*tmpC; ++j)
        {
            cin >> tmp;
            tmp2.push_back(tmp);
        }
        tests.push_back(make_tuple(tmpL, tmpC, tmp1, tmp2));
        tmp1.clear();
        tmp2.clear();
    }
}

void solve()
{
    vector<pair<int, int>> m1_points, m2_points;

    for(int i = 0; i < N; ++i)
    {
        m1_points.clear(); m2_points.clear();
        int largest = 0;

        tuple<int, int, vector<int>, vector<int>> test(tests.at(i));
        int L = get<0>(test);
        int C = get<1>(test);
        vector<int> matrix1(get<2>(test));
        vector<int> matrix2(get<3>(test));
        pair<int, int> tmp;
        int res[2*L-1][2*C-1];
        for(int j = 0; j < 2*L-1; ++j)
            for(int k = 0; k < 2*C-1; ++k)
                res[j][k] = 0;

        for(int j = 0; j < L*C; ++j)
        {
            if(matrix1.at(j) == 1) m1_points.push_back(make_pair(j/C, j%C));
            if(matrix2.at(j) == 1) m2_points.push_back(make_pair(j/C, j%C));
        }

        for(int j = 0; j < m1_points.size(); ++j)
        {
            for(int k = 0; k < m2_points.size(); ++k)
            {
                int x = m2_points.at(k).first - m1_points.at(j).first;
                int y = m2_points.at(k).second - m1_points.at(j).second;
                res[x+L-1][y+C-1]++;
                //cout << "{" << x << "," << y << "} = " << res[x+L-1][y+C-1] << endl;
            }
        }
        for(int j = 0; j < 2*L-1; ++j)
            for(int k = 0; k < 2*C-1; ++k)
                if(res[j][k] > largest) largest = res[j][k];

        cout << largest << endl;
    }
    /*
    unordered_map<pair<int, int>, int, pair_hash> cnt;
    vector<pair<int, int>> m1_points, m2_points;

    for(int i = 0; i < N; ++i)
    {
        cnt.clear(); m1_points.clear(); m2_points.clear();
        int largest = 0;

        tuple<int, int, vector<int>, vector<int>> test(tests.at(i));
        int L = get<0>(test);
        int C = get<1>(test);
        vector<int> matrix1(get<2>(test));
        vector<int> matrix2(get<3>(test));
        pair<int, int> tmp;

        for(int j = 0; j < L*C; ++j)
        {
            if(matrix1.at(j) == 1) m1_points.push_back(make_pair(j/C, j%C));
            if(matrix2.at(j) == 1) m2_points.push_back(make_pair(j/C, j%C));
        }


        for(int j = 0; j < m1_points.size(); ++j)
        {
            for(int k = 0; k < m2_points.size(); ++k)
            {
                tmp = make_pair(m2_points.at(k).first - m1_points.at(j).first, m2_points.at(k).second - m1_points.at(j).second);
                auto f = cnt.find(tmp);
                if(f != cnt.end()) f->second++;
                else cnt.insert(make_pair(tmp, 1));
            }
        }

        for(unordered_map<pair<int, int>, int, pair_hash>::iterator it = cnt.begin(); it != cnt.end(); it++)
        {
            if (it->second > largest) largest = it->second;
        }
        cout << largest << endl;

    }
    */

}

int main()
{
    input();
    solve();
    return 0;
}
