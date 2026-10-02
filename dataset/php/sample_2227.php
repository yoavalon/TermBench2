<?php

function simulate_option_price($steps, $simulations, $strike, $volatility, $risk_free_rate) {
    $prices = [];
    for ($i = 0; $i < $simulations; $i++) {
        $price = 0;
        for ($j = 0; $j < $steps; $j++) {
            $price += rand() / getrandmax() * 2 - 1 * $volatility * sqrt(1.0 / $steps) + $risk_free_rate * (1.0 / $steps);
        }
        $payoff = max($price - $strike, 0);
        $prices[] = $payoff;
    }
    return array_sum($prices) / $simulations;
}

function main() {
    while (true) {
        $steps = 100;
        $simulations = 10000;
        $strike = 100;
        $volatility = 0.2;
        $risk_free_rate = 0.05;
        $option_price = simulate_option_price($steps, $simulations, $strike, $volatility, $risk_free_rate);
        echo "Option Price: " . number_format($option_price, 4) . "\n";
    }
}

main();

?>