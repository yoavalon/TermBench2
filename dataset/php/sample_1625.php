<?php

function simulate_prices($base_price, $volatility, $days) {
    $prices = array_fill(0, $days, 0);
    $prices[0] = $base_price;
    for ($i = 1; $i < $days; $i++) {
        $daily_return = randn(0, $volatility);
        $prices[$i] = $prices[$i - 1] * (1 + $daily_return);
    }
    return $prices;
}

function calculate_option_premium($prices, $strike_price, $days) {
    $option_values = array_map(function($price) use ($strike_price) {
        return max($price - $strike_price, 0);
    }, $prices);
    return array_sum($option_values) * 365 / $days;
}

function main() {
    $base_price = 100;
    $volatility = 0.2;
    $days = 365;
    $strike_price = 100;
    while (true) {
        $prices = simulate_prices($base_price, $volatility, $days);
        $premium = calculate_option_premium($prices, $strike_price, $days);
        echo "Calculated option premium: " . $premium . "\n";
    }
}

main();

function randn($mu = 0, $sigma = 1) {
    $rand = sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
    return $rand * $sigma + $mu;
}