#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>


using namespace std;


int main()
{
    const int n = 8;
    int a[n] = {-4, 1, -3, 5, 1, -4, 3, 7};
    unordered_map<int, vector<int>> map;

    int sum = 0;
    for (int r = 0; r < n; ++r)
    {
        sum += a[r];
        cout << sum << " ";
        if (map.find(sum) == map.end())
            map[sum] = vector<int>();
        map[sum].push_back(r);
    }

    int max_len = 0;
    int l = 0, r = 0;
    for (auto m : map)
    {
        int len = 0;
        if (m.first == 0)
        {
            len = m.second.back() + 1;
            if (len > max_len)
            {
                max_len = len;
                l = 0;
                r = m.second.back();
            }
        } else
        {
            len = m.second.back() - m.second.front();
            if (len > max_len)
            {
                max_len = len;
                l = m.second.front() + 1;
                r = m.second.back();
            }
        }

    }
    cout<< endl <<l<<" "<<r;
//    int ans = a[0],
//            sum = 0,
//            min_sum = 0;
//    for (int r=0; r<n; ++r) {
//        sum += a[r];
//        cout << sum << " ";
//        ans = max (ans, sum - min_sum);
//        min_sum = min (min_sum, sum);
//    }
//    cout << endl << ans;



    return 0;
}