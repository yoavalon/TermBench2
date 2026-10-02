function update_inventory(stock, orders) {
    for (let i = 0; i < stock.length; i++) {
        stock[i] += orders[i];
    }
    return stock;
}

function generate_orders(num_items, max_order) {
    const orders = [];
    for (let i = 0; i < num_items; i++) {
        orders[i] = Math.floor(Math.random() * (max_order + 1));
    }
    return orders;
}

function main() {
    let stock = [100, 150, 200, 250, 300];
    const num_items = stock.length;
    const max_order = 50;
    while (true) {
        const orders = generate_orders(num_items, max_order);
        stock = update_inventory(stock, orders);
        console.log(stock);
    }
}

main();