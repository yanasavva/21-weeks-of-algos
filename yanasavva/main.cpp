#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("input.txt");
    int n,m;
    fin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    vector<int> ind;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> arr[i][j];
        }
    }

    fin.close();
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        int max = 0;
        int index_j = 0;
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                index_j = j;
            }
        }
        ind.push_back(index_j);
    }

    for (int j = 0; j < n; ++j) {
        int min = arr[0][j];
        int index_i = 0;
        for (int i = 0; i < m; ++i) {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
                index_i = i;
            }
            if (j == ind[index_i])
                ++cnt;
        }

    }
    cout << cnt<< endl;
    return 0;
}