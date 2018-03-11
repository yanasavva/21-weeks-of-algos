#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;
string getLCS(string x, string y)
{
    int len_x = x.length(), len_y = y.length();
    string path = "";
    string longest_path = "";

    // variable to shorten the number of operations when searching in strings
    int j_start = 0;

    for (int k = 0; k < len_x; ++k)
    {
        path = "";
        j_start = 0;
        while(j_start < len_y && x[k] != y[j_start])
            ++j_start;
        if (j_start == len_y)
            continue;

        for (int i = k; i < len_x; ++i)
        {
            for (int j = j_start; j < len_y; ++j)
            {
                //if current chars are equal and we haven't seen that symbol in second string
                if (x[i] == y[j])
                {
                    // shorten the number of chars we have to look at in the second string
                    j_start = j + 1;

                    // add this char to the result
                    path+=y[j];
                    break;
                }
            }

            if (path.length() > longest_path.length())
                longest_path = path;
        }

    }

    return longest_path;
}

int main()
{
    string x;
    string y;
    string res;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        getline(fin, x);
        getline(fin, y);
        fin.close();
    }

    res = getLCS(x, y);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res;
    fout.close();

    return 0;
}