#include <iostream>
using namespace std;

int func(int a, int b) {
    if (a == b) {
        return a;
    }
    int mid = (a + b) / 2;
    int left = func(a, mid);
    int right = func(mid + 1, b);
    return max(left, right);
}

int main() {
    cout << func(1, 10) << endl;
    return 0;
}