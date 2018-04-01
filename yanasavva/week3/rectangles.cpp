#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    ifstream fin;
    fin.open("input.txt");
    int n;
    int cnt = 0;
    unordered_map<int, vector<int>> x_to_y;

    fin >> n;
    for (int i = 0; i < n; ++i) {
        int x,y;
        fin >> x >> y;
        x_to_y[x].push_back(y);
    }

    time_point<steady_clock> start = steady_clock::now();
    for(auto &x : x_to_y)
    {
        if (x.second.size() > 1)
        {
            for (int i = 0; i < x.second.size(); ++i) {
                int y1 = x.second[i];
                for (int j = i + 1; j < x.second.size(); ++j) {
                    int y2 = x.second[j];

                    for (auto &other_x : x_to_y) {
                        if (x != other_x)
                        {
                            if (find(other_x.second.begin(), other_x.second.end(), y1) != other_x.second.end() &&
                                    find(other_x.second.begin(), other_x.second.end(), y2) != other_x.second.end())
                                ++cnt;
                        }
                    }
                }
            }

        }
        x.second.resize(0);
    }
    time_point<steady_clock> end1 = steady_clock::now();
    nanoseconds elapsed = duration_cast<nanoseconds>(end1 - start);

    cout << cnt << endl;
    cout << "timing: " << elapsed.count() / 1e6;

    return 0;
}

