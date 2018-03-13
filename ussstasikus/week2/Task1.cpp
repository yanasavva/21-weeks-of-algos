//
// Created by Stas Don on 13/03/2018.
//

#include <iostream>
#include <vector>



void snake_down(int n, std::vector<std::vector<int>> &array);
void snake_left(int n, std::vector<std::vector<int>> &array);
void printArray(int n, std::vector<std::vector<int>> &array);

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> array(n, std::vector<int>(n));
    if(n % 2 == 0)
        snake_down(n, array);
    else
        snake_left(n, array);

    printArray(n, array);
}

void printArray(int n, std::vector<std::vector<int>> &array)
{
    for (int k = 0; k < n; ++k)
    {
        for (int l = 0; l < n; ++l)
            std::cout << array[k][l] << "\t";
        std::cout << std::endl;
    }
}

void snake_left(int n, std::vector<std::vector<int>> &array)
{
    int curr_index = (n - 1)/2;
    int amount = n * n;
    int i = curr_index, j = curr_index;
    int curr_n = 1;
    int step_number = 0;


    while(curr_n <= amount)
    {
        ++step_number;
        for (int left = 0; left < step_number && curr_n <= amount; ++left)
            array[i][j--] = curr_n++;

        for (int down = 0; down < step_number && curr_n <= amount; ++down)
            array[i++][j] = curr_n++;


        ++step_number;
        for (int right = 0; right < step_number && curr_n <= amount; ++right)
            array[i][j++] = curr_n++;

        for (int up = 0; up < step_number && curr_n <= amount; ++up)
            array[i--][j] = curr_n++;
    }

}

void snake_down(int n, std::vector<std::vector<int>> &array)
{
    int curr_index = (n - 1)/2;
    int amount = n * n;
    int i = curr_index, j = curr_index;
    int curr_n = 1;
    int step_number = 0;


    while(curr_n <= amount)
    {
        ++step_number;
        for (int down = 0; down < step_number && curr_n <= amount; ++down)
            array[i++][j] = curr_n++;

        for (int right = 0; right < step_number && curr_n <= amount; ++right)
            array[i][j++] = curr_n++;

        ++step_number;
        for (int up = 0; up < step_number && curr_n <= amount; ++up)
            array[i--][j] = curr_n++;

        for (int left = 0; left < step_number && curr_n <= amount; ++left)
            array[i][j--] = curr_n++;

    }

}
