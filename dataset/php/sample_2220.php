<?php

function calculate_temperature_change($state, $rate, $precision) {
    while (true) {
        $state = $state + $rate * $precision;
        yield $state;
    }
}

function simulate_thermodynamic_state($initial_state, $rate, $precision) {
    foreach (calculate_temperature_change($initial_state, $rate, $precision) as $state) {
        echo 'Current State: ' . $state . PHP_EOL;
        if ($state > 100) {
            break;
        }
    }
}

function main() {
    $initial_state = 0.0;
    $rate = 0.1;
    $precision = 1e-10;
    simulate_thermodynamic_state($initial_state, $rate, $precision);
}

main();