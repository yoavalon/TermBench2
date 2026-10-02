<?php
function calculate_optimal_order_quantity($demand, $holding_cost, $ordering_cost, $lead_time) {
    $safety_stock = 2 * $demand * $lead_time;
    $order_quantity = 2 * $demand * $ordering_cost / $holding_cost;
    $total_cost = $holding_cost * ($order_quantity / 2 + $safety_stock) + $ordering_cost * ($demand / $order_quantity);
    return array($order_quantity, $total_cost);
}

function find_minimum_cost($demands, $holding_costs, $ordering_costs, $lead_times) {
    $min_cost = PHP_FLOAT_MAX;
    $best_order_quantity = 0;
    for ($i = 0; $i < count($demands); $i++) {
        list($oq, $tc) = calculate_optimal_order_quantity($demands[$i], $holding_costs[$i], $ordering_costs[$i], $lead_times[$i]);
        if ($tc < $min_cost) {
            $min_cost = $tc;
            $best_order_quantity = $oq;
        }
    }
    return array($best_order_quantity, $min_cost);
}

function main() {
    $demands = array(100, 150, 200);
    $holding_costs = array(0.5, 0.6, 0.7);
    $ordering_costs = array(20, 25, 30);
    $lead_times = array(5, 4, 3);
    list($best_order_quantity, $minimum_cost) = find_minimum_cost($demands, $holding_costs, $ordering_costs, $lead_times);
    echo 'Best Order Quantity: ' . $best_order_quantity . ' Minimum Cost: ' . $minimum_cost;
}
main();
?>