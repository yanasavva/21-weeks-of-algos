//
// Created by Lucky13 on 13.03.2018.
//

#include <iostream>
#include <unordered_map>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    int arr[N];
    for (int i = 0; i < N; ++i)
        std::cin >> arr[i];

    std::unordered_map<int, std::vector<int>> unordered_map;
    int sum[N];
    sum[0] = arr[0];
    unordered_map[sum[0]].push_back(0);
    for (int i = 1; i < N; ++i)
    {
        sum[i] = sum[i - 1] + arr[i];
        unordered_map[sum[i]].push_back(i);
    }

    std::pair<int, int> max_pair;
    for (auto &&pair : unordered_map)
    {
        int start = 0, end;
        if (pair.first == 0)
            end = pair.second[pair.second.size() - 1];
        else
        {
            start = pair.second[0] + 1;
            end = pair.second[pair.second.size() - 1];
        }

        if (end - start + 1 > max_pair.second - max_pair.first + 1)
        {
            max_pair.first = start;
            max_pair.second = end;
        }
    }

    std::cout << max_pair.first << " -> " << max_pair.second;

    return 0;
}