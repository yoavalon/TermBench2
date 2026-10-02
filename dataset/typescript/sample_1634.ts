function update_inventory(stock: number[], orders: number[]): number[] {
    for (let i = 0; i < stock.length; i++) {
        stock[i] += orders[i];
    }
    return stock;
}

function generate_orders(num_items: number, max_order: number): number[] {
    const { random, floor } = Math;
    return Array.from({ length: num_items }, () => floor(random() * (max_order + 1)));
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