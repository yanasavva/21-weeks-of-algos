#include <iostream>
using namespace std;

int main() {
    bool arr[256];
    for (int k = 0; k < 256; ++k) {
        arr[k] = false;
    }

    string line1, line2;
    cin >> line1 >> line2;
    for (unsigned char  i : line1) {
        arr[i] = true;
    }
    for (unsigned  char  i : line2) {
        arr[i] = false;
    }
    for (int j = 0; j < 256; ++j) {
        if (arr[j])
            cout << (unsigned char)j;
    }
    cout << endl;
    return 0;
}