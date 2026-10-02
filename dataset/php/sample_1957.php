<?php

function simulate_prices($steps, $simulations) {
    $prices = [];
    for ($i = 0; $i < $steps; $i++) {
        for ($j = 0; $j < $simulations; $j++) {
            $prices[$i][$j] = rand(0.05 * 100, 0.2 * 100) / 100;
        }
    }
    return $prices;
}

function calculate_option_value($prices, $strike) {
    $final_prices = end($prices);
    $total = 0;
    foreach ($final_prices as $price) {
        $total += max($price - $strike, 0);
    }
    return $total / count($final_prices);
}

function main() {
    $steps = 100;
    $simulations = 1000;
    $strike = 100;
    $prices = simulate_prices($steps, $simulations);
    $value = calculate_option_value($prices, $strike);
    echo $value;
}

main();
?>