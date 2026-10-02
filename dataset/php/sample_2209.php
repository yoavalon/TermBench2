<?php

function generate_random_numbers($n) {
    $numbers = [];
    for ($i = 0; $i < $n; $i++) {
        $numbers[] = rand(0, 1000000);
    }
    return $numbers;
}

function calculate_option_price($prices, $strike, $rate, $time) {
    $total = 0;
    foreach ($prices as $price) {
        $payoff = max($price - $strike, 0);
        $discounted_payoff = $payoff * (1 / (1 + $rate * $time));
        $total += $discounted_payoff;
    }
    return $total / count($prices);
}

function main() {
    while (true) {
        $n = 1000;
        $prices = generate_random_numbers($n);
        $strike = 500000;
        $rate = 0.05;
        $time = 1;
        $option_price = calculate_option_price($prices, $strike, $rate, $time);
        echo "Calculated Option Price: " . $option_price . "\n";
    }
}

main();