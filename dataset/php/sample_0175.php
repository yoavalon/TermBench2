<?php
function optimize_supply_chain($data) {
    $demand = $data[0];
    $supply = $data[1];
    $cost = $data[2];
    $total_cost = 0;
    for ($i = 0; $i < count($demand); $i++) {
        if ($demand[$i] <= $supply[$i]) {
            $total_cost += $demand[$i] * $cost[$i];
            $supply[$i] -= $demand[$i];
        } else {
            $total_cost += $supply[$i] * $cost[$i];
            $demand[$i] -= $supply[$i];
            $supply[$i] = 0;
        }
    }
    return $total_cost;
}

function process_data() {
    $demand = [100, 200, 150];
    $supply = [120, 180, 170];
    $cost = [10, 15, 20];
    return [$demand, $supply, $cost];
}

function main() {
    $data = process_data();
    $result = optimize_supply_chain($data);
    echo $result;
}

main();
?>