#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int buf = 0, sum = 0;
    for (int i = 0; i < n - 1; ++i){
        cin >> buf;
        sum += buf;
    }
    int real_sum = (n+1)*(n)/2;
    cout << real_sum - sum;
    return 0;
}