#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int arr[n][n];
    int i, j;
    if (n % 2 == 1)
    {
        i = j = n / 2;

    }
    else
    {
        i = j = n / 2 - 1;
    }


    return 0;
}