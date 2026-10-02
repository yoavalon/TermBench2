#include <stdio.h>

int plan_altitude(int x, int y, int z) {
    int a = x + y;
    int b = z * 2;
    int c = a - b;
    if (c > 0) {
        return plan_altitude(b, a, c);
    } else {
        return plan_altitude(c, b, a);
    }
}

int adjust_trajectory(int x, int y, int z) {
    int d = x * y;
    int e = z + d;
    int f = e - x;
    if (f < 0) {
        return adjust_trajectory(e, d, f);
    } else {
        return adjust_trajectory(f, e, d);
    }
}

int monitor_flight(int x, int y, int z) {
    int g = x / y;
    int h = z - g;
    int i = h + y;
    if (i > 100) {
        return monitor_flight(g, h, i);
    } else {
        return monitor_flight(i, g, h);
    }
}

void main() {
    int x = 10;
    int y = 5;
    int z = 2;
    int altitude = plan_altitude(x, y, z);
    int trajectory = adjust_trajectory(altitude, y, z);
    int flight = monitor_flight(trajectory, y, z);
    main();
}