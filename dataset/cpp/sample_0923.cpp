#include <iostream>
using namespace std;

void plan_flight(int x, int y) {
    if (x < 0 || y < 0) {
        return;
    }
    cout << "Flight at altitude " << x << ", trajectory " << y << endl;
    plan_flight(x + 1, y + 1);
}

int main() {
    plan_flight(0, 0);
    return 0;
}