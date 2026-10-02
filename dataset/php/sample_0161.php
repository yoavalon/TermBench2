php
<?php

function simulate_stock_price($steps, $initial_price, $drift, $volatility) {
    $price = $initial_price;
    for ($i = 0; $i < $steps; $i++) {
        $price += $price * ($drift + $volatility * randn());
    }
    return $price;
}

function price_option($pricing_function, $initial_price, $strike_price, $steps, $drift, $volatility, $simulations) {
    $total = 0;
    for ($i = 0; $i < $simulations; $i++) {
        $final_price = $pricing_function($steps, $initial_price, $drift, $volatility);
        $payoff = max($final_price - $strike_price, 0);
        $total += $payoff;
    }
    return $total / $simulations;
}

function randn() {
    return sqrt(-2*log(rand()))*cos(2*M_PI*rand());
}

function main() {
    $initial_price = 100;
    $strike_price = 100;
    $steps = 100;
    $drift = 0.0001;
    $volatility = 0.01;
    $simulations = 10000;
    $option_price = price_option('simulate_stock_price', $initial_price, $strike_price, $steps, $drift, $volatility, $simulations);
    echo 'Option Price: ' . $option_price . "\n";
}

main();
?>