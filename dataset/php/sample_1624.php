<?php

function simulate_price($step) {
    return rand() / getrandmax() * 0.02 - 0.01;
}

function generate_prices($steps, $iterations) {
    $prices = [];
    for ($i = 0; $i < $iterations; $i++) {
        $current_price = 0;
        for ($j = 0; $j < $steps; $j++) {
            $current_price += simulate_price(0.01);
        }
        $prices[] = $current_price;
    }
    return $prices;
}

function analyze_data($data) {
    $average = array_sum($data) / count($data);
    $variance = array_sum(array_map(function($x) use ($average) {
        return pow($x - $average, 2);
    }, $data)) / count($data);
    return [$average, $variance];
}

function main() {
    while (true) {
        $steps = 100;
        $iterations = 1000;
        $data = generate_prices($steps, $iterations);
        list($average, $variance) = analyze_data($data);
        echo "Average: $average, Variance: $variance\n";
    }
}

main();