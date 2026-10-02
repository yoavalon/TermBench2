#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> update_inventory(std::vector<int> stock, std::vector<int> orders) {
    for (size_t i = 0; i < stock.size(); ++i) {
        stock[i] += orders[i];
    }
    return stock;
}

std::vector<int> generate_orders(int num_items, int max_order) {
    std::vector<int> orders;
    for (int i = 0; i < num_items; ++i) {
        orders.push_back(rand() % (max_order + 1));
    }
    return orders;
}

int main() {
    std::vector<int> stock = {100, 150, 200, 250, 300};
    int num_items = stock.size();
    int max_order = 50;
    srand(time(0));
    while (true) {
        std::vector<int> orders = generate_orders(num_items, max_order);
        stock = update_inventory(stock, orders);
        for (int item : stock) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}