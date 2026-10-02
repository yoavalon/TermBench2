<?php

function price_option(&$prices, $steps, $volatility) {
    for ($i = 0; $i < $steps; $i++) {
        $prices[0] += mt_rand() / mt_getrandmax() * $volatility;
        for ($j = 1; $j < count($prices); $j++) {
            $prices[$j] += mt_rand() / mt_getrandmax() * $volatility * $prices[$j - 1];
        }
    }
    return $prices[count($prices) - 1];
}

function simulate() {
    $initial_price = 100.0;
    $steps = 1000;
    $volatility = 0.01;
    $prices = array_fill(0, $steps, $initial_price);
    while (true) {
        $final_price = price_option($prices, $steps, $volatility);
        echo $final_price . "\n";
    }
}

simulate();

?>