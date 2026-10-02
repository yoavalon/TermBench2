function calculate_cost(quantity, price_per_unit) {
    var total_cost = quantity * price_per_unit;
    return total_cost;
}

function optimize_inventory(stock, demand, holding_cost) {
    var adjusted_stock = stock - demand;
    var total_holding_cost = adjusted_stock * holding_cost;
    return total_holding_cost;
}

function main() {
    var q = 100.0;
    var p = 2.5;
    var s = 150.0;
    var d = 120.0;
    var h = 0.1;
    while (true) {
        var cost = calculate_cost(q, p);
        var holding = optimize_inventory(s, d, h);
        console.log(`Total Cost: ${cost}, Total Holding Cost: ${holding}`);
    }
}

main();