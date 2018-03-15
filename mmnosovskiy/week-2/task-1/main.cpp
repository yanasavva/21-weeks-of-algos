#include <iostream>

int** init_array(int n);

void make_spiral_even(int** arr, int n, int offset, int &largest);

void make_spiral_neven(int** arr, int n, int offset, int &largest);

void print_arr(int** arr, int n);

int main()
{
    int n;
    std::cin >> n;

    int** arr = init_array(n);

    int i, j, current = n * n;
    if (n % 2 == 1)
    {
        for (int k = 0; k < n / 2 + 1; ++k)
            make_spiral_neven(arr, n, k, current);
    }
    else
    {
        for (int k = 0; k < n / 2; ++k)
            make_spiral_even(arr, n, k, current);
    }

    print_arr(arr, n);

    return 0;
}

void print_arr(int** arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            std::cout << arr[i][j] << "\t";
        std::cout << std::endl;
    }
}

int** init_array(int n)
{
    int** arr = new int* [n];
    for (int i = 0; i < n; ++i)
        arr[i] = new int[n]{0};

    return arr;
}

void make_spiral_even(int** arr, int n, int offset, int &largest)
{
    int i = offset;
    int j = n - offset - 1;

    for (int k = 0; k < n - 2 * offset; ++k)
        arr[i++][j] = largest--;
    --i;
    --j;
    for (int k = 0; k < n - 2 * offset - 2; ++k)
        arr[i][j--] = largest--;
    for (int k = 0; k < n - 2 * offset; ++k)
        arr[i--][j] = largest--;
    ++i;
    ++j;
    for (int k = 0; k < n - 2 * offset - 2; ++k)
        arr[i][j++] = largest--;
}

void make_spiral_neven(int** arr, int n, int offset, int &largest)
{
    if (offset == n / 2)
    {
        arr[offset][offset] = 1;
        return;
    }

    int i = offset;
    int j = offset;

    for (int k = 0; k < n - 2 * offset; ++k)
        arr[i][j++] = largest--;
    ++i;
    --j;
    for (int k = 0; k < n - 2 * offset - 2; ++k)
        arr[i++][j] = largest--;
    for (int k = 0; k < n - 2 * offset; ++k)
        arr[i][j--] = largest--;
    --i;
    ++j;
    for (int k = 0; k < n - 2 * offset - 2; ++k)
        arr[i--][j] = largest--;
}
