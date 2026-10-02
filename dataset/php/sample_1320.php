<?php

function generate_supply_chain($data) {
    $mutated_data = [];
    foreach ($data as $item) {
        $mutation_factor = mt_rand(90000, 110000) / 100000;
        $mutated_value = $item * $mutation_factor;
        $mutated_data[] = $mutated_value;
    }
    return $mutated_data;
}

function optimize_logistics($data) {
    $optimized_data = [];
    foreach ($data as $value) {
        if ($value > 100) {
            $optimized_value = $value * 0.95;
        } else {
            $optimized_value = $value * 1.05;
        }
        $optimized_data[] = $optimized_value;
    }
    return $optimized_data;
}

function main() {
    $initial_data = [];
    for ($i = 0; $i < 10; $i++) {
        $initial_data[] = rand(50, 150);
    }
    $mutated_data = generate_supply_chain($initial_data);
    $optimized_data = optimize_logistics($mutated_data);
    print_r($optimized_data);
}

main();

?>