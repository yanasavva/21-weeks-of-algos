//
// Created by Stas Don on 13/03/2018.
//
#include <iostream>
#include <vector>

std::vector<int> readArray(int n);
int getSum(int n, std::vector<int> &numbers);


int main(){
    int n;
    std::cin >> n;
    std::vector<int> numbers = readArray(n);

    int expected_n = n + 1;
    int sum = getSum(n, numbers);
    int expected_sum = expected_n * (1 + expected_n) / 2;
    std::cout << expected_sum - sum;
}

std::vector<int> readArray(int n)
{
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
        std::cin >> numbers[i];
    return numbers;
}

int getSum(int n, std::vector<int> &numbers)
{
    int sum = 0;
    for(int el: numbers)
        sum += el;
    return sum;
}

