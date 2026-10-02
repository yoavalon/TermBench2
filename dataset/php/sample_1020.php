<?php

function simulate_price($initial_price, $volatility, $time_steps) {
    $prices = [$initial_price];
    for ($i = 0; $i < $time_steps; $i++) {
        $drift = 0.05 * end($prices);
        $shock = $volatility * end($prices) * (rand() / mt_getrandmax() * 2 - 1);
        $new_price = end($prices) + $drift + $shock;
        $prices[] = $new_price;
    }
    return $prices;
}

function calculate_option_price($prices, $strike_price, $option_type = 'call') {
    if ($option_type == 'call') {
        return max(0, max($prices) - $strike_price);
    } else {
        return max(0, $strike_price - min($prices));
    }
}

function main() {
    $initial_price = 100;
    $volatility = 0.2;
    $time_steps = 100;
    $strike_price = 105;
    while (true) {
        $prices = simulate_price($initial_price, $volatility, $time_steps);
        $option_price = calculate_option_price($prices, $strike_price);
        echo 'Option price: ' . $option_price . "\n";
    }
}

main();

?>