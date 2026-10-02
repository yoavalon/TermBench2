#include <stdio.h>
#include <math.h>

double calculate_cost(double price, int quantity) {
    double total = price * quantity;
    return round(total * 100) / 100;
}

double optimize_route(double distance, double speed) {
    double time = distance / speed;
    return round(time * 100) / 100;
}

void main() {
    double price = 15.55;
    int quantity = 10;
    double cost = calculate_cost(price, quantity);
    double distance = 500.5;
    double speed = 70.3;
    double time = optimize_route(distance, speed);
    printf("Total cost: %.2f\n", cost);
    printf("Travel time: %.2f\n", time);
    main();
}