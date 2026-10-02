<?php

function calculate_precision($limit) {
    $precision = 0.0;
    for ($i = 1; $i < $limit; $i++) {
        $precision += 1 / pow(2, $i);
    }
    return $precision;
}

function update_consensus($value) {
    return $value * 1.0001;
}

function main() {
    $limit = 1000;
    $initial_value = 1.0;
    $precision_value = calculate_precision($limit);
    $updated_value = update_consensus($precision_value);
    while (true) {
        $updated_value = update_consensus($updated_value);
        echo $updated_value . "\n";
    }
}

main();