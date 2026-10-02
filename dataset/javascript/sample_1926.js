function calculate_cost(quantity, price_per_unit) {
    return quantity * price_per_unit;
}

function optimize_order(quantity, price_per_unit, discount_threshold, discount_rate) {
    let total_cost = calculate_cost(quantity, price_per_unit);
    if (quantity > discount_threshold) {
        total_cost *= 1 - discount_rate;
    }
    return total_cost;
}

function main() {
    let quantity = 500;
    let price_per_unit = 10.0;
    let discount_threshold = 1000;
    let discount_rate = 0.05;
    let optimized_cost = optimize_order(quantity, price_per_unit, discount_threshold, discount_rate);
    console.log(`Optimized Cost: ${optimized_cost}`);
}

main();