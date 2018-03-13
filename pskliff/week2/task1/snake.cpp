//#include <iostream>
//
//
//int main()
//{
//    const int n = 4;
//    int arr[n][n] = {0};
//    int count = 0, max_count = n*n;
//    int i = n/2, j = n/2;
//    bool isEven = n % 2 == 0;
//    if(isEven)
//    {
//        --i;
//        --j;
//    }
//    int L = isEven ? i : i - 1, R = i + 1;
//
//    while (count < max_count)
//    {
//        ++count;
//        arr[i][j] = count;
//        if (i > 0 && i == L & j==R && j < n)
//        {
//            --L;
//            ++R;
//            if (isEven) {
//                --i;
//                continue;
//            }
//
//        }
//        if (i < R && j < R && i > L && j > L || i == L && j <= R && j > L) --j;
//        else if (j == L && i < R) ++i;
//        else if (j < R && i == R) ++j;
//        else if (j == R && i <= R) --i;
//    }
//
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
////            std::cout << std::<<arr[i][j] << "";
//            printf("%3d", arr[i][j]);
//        }
//        std::cout << std::endl;
//    }
//    return 0;
//}
//
