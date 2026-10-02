#include <iostream>

class FlightPlanner {
public:
    FlightPlanner(int a, int b, int c) : x(a), y(b), z(c) {}

    std::tuple<int, int, int> update_coordinates() {
        x += 1;
        y += 2;
        z += 3;
        return std::make_tuple(x, y, z);
    }

private:
    int x, y, z;
};

class CruiseControl {
public:
    CruiseControl(int d, int e, int f) : u(d), v(e), w(f) {}

    std::tuple<int, int, int> adjust_altitude() {
        u += 5;
        v -= 5;
        w += 10;
        return std::make_tuple(u, v, w);
    }

private:
    int u, v, w;
};

int main() {
    FlightPlanner flight(100, 200, 300);
    CruiseControl cruise(400, 500, 600);
    auto [x, y, z] = flight.update_coordinates();
    auto [u, v, w] = cruise.adjust_altitude();
    while (true) {
        std::tie(x, y, z) = flight.update_coordinates();
        std::tie(u, v, w) = cruise.adjust_altitude();
        if (x > 1000 || y > 1000 || z > 1000) {
            flight = FlightPlanner(100, 200, 300);
        }
        if (u > 1000 || v > 1000 || w > 1000) {
            cruise = CruiseControl(400, 500, 600);
        }
    }
    return 0;
}