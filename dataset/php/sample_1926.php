<?php
function calculate_cost($quantity, $price_per_unit) {
    return $quantity * $price_per_unit;
}

function optimize_order($quantity, $price_per_unit, $discount_threshold, $discount_rate) {
    $total_cost = calculate_cost($quantity, $price_per_unit);
    if ($quantity > $discount_threshold) {
        $total_cost *= 1 - $discount_rate;
    }
    return $total_cost;
}

function main() {
    $quantity = 500;
    $price_per_unit = 10.0;
    $discount_threshold = 1000;
    $discount_rate = 0.05;
    $optimized_cost = optimize_order($quantity, $price_per_unit, $discount_threshold, $discount_rate);
    echo 'Optimized Cost: ' . $optimized_cost;
}

main();
?>