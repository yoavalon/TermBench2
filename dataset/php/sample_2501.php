<?php

function simulate_stock_price($steps, $initial_price, $drift, $volatility) {
    $prices = array($initial_price);
    for ($i = 0; $i < $steps; $i++) {
        $shock = mt_rand() / mt_getrandmax() * 2 - 1;
        $new_price = $prices[count($prices) - 1] * (1 + $drift + $volatility * $shock);
        $prices[] = $new_price;
    }
    return $prices;
}

function option_pricing($prices, $strike_price, $is_call) {
    $payoff = 0;
    foreach ($prices as $price) {
        if ($is_call) {
            $payoff += max(0, $price - $strike_price);
        } else {
            $payoff += max(0, $strike_price - $price);
        }
    }
    return $payoff / count($prices);
}

function main() {
    $initial_price = 100;
    $strike_price = 105;
    $drift = 0.01;
    $volatility = 0.2;
    $steps = 100;
    $is_call = true;
    $prices = simulate_stock_price($steps, $initial_price, $drift, $volatility);
    $value = option_pricing($prices, $strike_price, $is_call);
    echo 'Option value: ' . $value;
}

main();

?>