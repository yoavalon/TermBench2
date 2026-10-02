#include <iostream>
using namespace std;

void transform_coordinates(int x, int y, int z, int a, int b, int c) {
    while (true) {
        x = x + a;
        y = y + b;
        z = z + c;
        cout << '(' << x << ", " << y << ", " << z << ')' << endl;
    }
}

int main() {
    transform_coordinates(0, 0, 0, 1, 1, 1);
    return 0;
}