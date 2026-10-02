function calculate_optimal_order_quantity(demand, holding_cost, ordering_cost, lead_time) {
    safety_stock = 2 * demand * lead_time;
    order_quantity = 2 * demand * ordering_cost / holding_cost;
    total_cost = holding_cost * (order_quantity / 2 + safety_stock) + ordering_cost * (demand / order_quantity);
    return [order_quantity, total_cost];
}

function find_minimum_cost(demands, holding_costs, ordering_costs, lead_times) {
    let min_cost = Infinity;
    let best_order_quantity = 0;
    for (let i = 0; i < demands.length; i++) {
        let [oq, tc] = calculate_optimal_order_quantity(demands[i], holding_costs[i], ordering_costs[i], lead_times[i]);
        if (tc < min_cost) {
            min_cost = tc;
            best_order_quantity = oq;
        }
    }
    return [best_order_quantity, min_cost];
}

function main() {
    let demands = [100, 150, 200];
    let holding_costs = [0.5, 0.6, 0.7];
    let ordering_costs = [20, 25, 30];
    let lead_times = [5, 4, 3];
    let [best_order_quantity, minimum_cost] = find_minimum_cost(demands, holding_costs, ordering_costs, lead_times);
    console.log('Best Order Quantity:', best_order_quantity, 'Minimum Cost:', minimum_cost);
}

main();