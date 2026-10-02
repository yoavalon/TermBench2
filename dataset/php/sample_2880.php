<?php

function simulate_temp_change($initial_temp, $rate, $time_step) {
    $current_temp = $initial_temp;
    while (true) {
        $current_temp += $rate * $time_step;
        yield $current_temp;
    }
}

function analyze_sequence($sequence) {
    foreach ($sequence as $value) {
        echo "Current Temperature: " . number_format($value, 2) . "K\n";
    }
}

function main() {
    $initial_temp = 300;
    $rate = 0.01;
    $time_step = 1;
    $sequence = simulate_temp_change($initial_temp, $rate, $time_step);
    analyze_sequence($sequence);
}

main();

?>