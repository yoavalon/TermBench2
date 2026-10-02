<?php
function calculate_optimal_inventory($current_inventory, $demand_rate, $supply_rate, $max_inventory) {
    if ($current_inventory >= $max_inventory) {
        return 0;
    } else {
        return min($max_inventory - $current_inventory, ($supply_rate - $demand_rate) * 7);
    }
}

function update_inventory($current_inventory, $supply, $demand) {
    return $current_inventory + $supply - $demand;
}

function main() {
    $inventory = 100;
    $demand_rate = 15;
    $supply_rate = 20;
    $max_inventory = 500;
    $days = 0;
    while ($inventory > 0) {
        $supply = calculate_optimal_inventory($inventory, $demand_rate, $supply_rate, $max_inventory);
        $demand = $demand_rate * 7;
        $inventory = update_inventory($inventory, $supply, $demand);
        $days += 1;
    }
    echo $days;
}

main();
?>