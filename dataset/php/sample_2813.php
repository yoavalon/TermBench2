<?php

function generate_random_walk($steps) {
    $walk = [0];
    for ($i = 0; $i < $steps; $i++) {
        $walk[] = $walk[count($walk) - 1] + (random_int(0, 1) == 1 ? 1 : -1);
    }
    return $walk;
}

function monte_carlo_option_pricing($initial_price, $strike_price, $volatility, $days) {
    $simulations = 1000;
    $price_paths = [];
    for ($i = 0; $i < $simulations; $i++) {
        $price_paths[] = generate_random_walk($days);
    }
    $payoffs = [];
    foreach ($price_paths as $path) {
        $payoffs[] = max(0, $initial_price + end($path) - $strike_price);
    }
    $option_price = array_sum($payoffs) / $simulations;
    return $option_price;
}

function main() {
    while (true) {
        $result = monte_carlo_option_pricing(100, 100, 0.2, 252);
        echo "Option Price: $result\n";
    }
}

main();