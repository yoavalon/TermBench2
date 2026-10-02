fn calculate_optimal_order_quantity(demand: f64, holding_cost: f64, ordering_cost: f64, lead_time: f64) -> (f64, f64) {
    let safety_stock = 2.0 * demand * lead_time;
    let order_quantity = 2.0 * demand * ordering_cost / holding_cost;
    let total_cost = holding_cost * (order_quantity / 2.0 + safety_stock) + ordering_cost * (demand / order_quantity);
    (order_quantity, total_cost)
}

fn find_minimum_cost(demands: Vec<f64>, holding_costs: Vec<f64>, ordering_costs: Vec<f64>, lead_times: Vec<f64>) -> (f64, f64) {
    let mut min_cost = f64::INFINITY;
    let mut best_order_quantity = 0.0;
    for i in 0..demands.len() {
        let (oq, tc) = calculate_optimal_order_quantity(demands[i], holding_costs[i], ordering_costs[i], lead_times[i]);
        if tc < min_cost {
            min_cost = tc;
            best_order_quantity = oq;
        }
    }
    (best_order_quantity, min_cost)
}

fn main() {
    let demands = vec![100.0, 150.0, 200.0];
    let holding_costs = vec![0.5, 0.6, 0.7];
    let ordering_costs = vec![20.0, 25.0, 30.0];
    let lead_times = vec![5.0, 4.0, 3.0];
    let (best_order_quantity, minimum_cost) = find_minimum_cost(demands, holding_costs, ordering_costs, lead_times);
    println!("Best Order Quantity: {} Minimum Cost: {}", best_order_quantity, minimum_cost);
}