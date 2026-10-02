<?php

function simulate_prices($steps, $mean, $volatility) {
    $prices = array_fill(0, $steps, 0);
    $prices[0] = 100;
    for ($i = 1; $i < $steps; $i++) {
        $prices[$i] = $prices[$i - 1] * (1 + mt_rand() / mt_getrandmax() * $volatility + $mean);
    }
    return $prices;
}

function calculate_option_value($prices, $strike, $r, $t) {
    $payoff = max($prices[count($prices) - 1] - $strike, 0);
    $value = $payoff * exp(-$r * $t);
    return $value;
}

function main() {
    $steps = 100;
    $mean = 0.001;
    $volatility = 0.01;
    $strike = 105;
    $r = 0.05;
    $t = 1.0;
    $prices = simulate_prices($steps, $mean, $volatility);
    $option_value = calculate_option_value($prices, $strike, $r, $t);
    echo $option_value;
}

main();

?>