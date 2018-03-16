#include <iostream>
#include <string>
#include <vector>
#include <deque>


using namespace std;

typedef pair<double, double> dpair;


class line
{
    double x_coef, y_coef, free_coef;
public:
    line(double x, double y, double free)
    {
        x_coef = x;
        y_coef = y;
        free_coef = free;
    }


    bool is_online(double x, double y)
    {
        return x_coef * x + y_coef * y + free_coef == 0;
    }
};


int main()
{
    const int n = 5;
    const dpair buf[] = {dpair(2, 1), dpair(-2, -4), dpair(-2, 5), dpair(-5, 2), dpair(4, 2), dpair(-1, -2)};
//    const dpair buf[] = {dpair(6, 8), dpair(1, 6), dpair(-2, 3), dpair(-3, 7), dpair(-4, -2), dpair(7, -3)};
//    const dpair buf[] = {dpair(6, 4), dpair(4, 2), dpair(-3, 4), dpair(2, 2), dpair(1, 2), dpair(-1, 2)};
//    const dpair buf[] = {dpair(6, 4), dpair(4, 2), dpair(-3, 4), dpair(1.5, 2), dpair(-1, 2)};
    deque<dpair> arr(buf, buf + sizeof(buf) / sizeof(buf[0]));

    sort(arr.begin(), arr.end(), [](dpair& left, dpair& right)
    {
        return left.first + left.second < right.first + right.second;
    });
    bool hasSymmetry = true;

    dpair r1 = arr.back();
    arr.pop_back();
    dpair r2 = arr.back();
    arr.pop_back();
    dpair l1 = arr.front();
    arr.pop_front();
    dpair l2 = arr.front();
    arr.pop_front();
    double xc1 = (r1.first + l1.first) / 2;
    double yc1 = (r1.second + l1.second) / 2;

    double xc2 = (r2.first + l2.first) / 2;
    double yc2 = (r2.second + l2.second) / 2;

    line ln(yc1 - yc2, xc2 - xc1, xc1 * yc2 - xc2 * yc1);
    while (arr.size() > n % 2 == 0 ? 0 : 1)
    {
        dpair r = arr.back();
        arr.pop_back();
        dpair l = arr.front();
        arr.pop_front();
        double xc = (r.first + l.first) / 2;
        double yc = (r.second + l.second) / 2;
        hasSymmetry = ln.is_online(xc, yc);
    }

    cout << hasSymmetry;

    return 0;
}