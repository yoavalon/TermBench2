#include <iostream>
#include <cmath>

double calculate_cost(double price, int quantity) {
    double total = price * quantity;
    return std::round(total * 100) / 100;
}

double optimize_route(double distance, double speed) {
    double time = distance / speed;
    return std::round(time * 100) / 100;
}

void main() {
    double price = 15.55;
    int quantity = 10;
    double cost = calculate_cost(price, quantity);
    double distance = 500.5;
    double speed = 70.3;
    double time = optimize_route(distance, speed);
    std::cout << "Total cost: " << cost << std::endl;
    std::cout << "Travel time: " << time << std::endl;
    main();
}

int main() {
    main();
    return 0;
}