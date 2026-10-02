<?php

function simulate_prices($steps, $simulations) {
    $drift = 0.05;
    $volatility = 0.2;
    $initial_price = 100;
    $dt = 1.0 / $steps;
    $paths = array_fill(0, $simulations, array_fill(0, $steps, 0));
    for ($i = 0; $i < $simulations; $i++) {
        $paths[$i][0] = $initial_price;
    }
    for ($t = 1; $t < $steps; $t++) {
        $z = array_map(function() { return stats_rand_gen_normal(0, 1); }, range(0, $simulations - 1));
        for ($i = 0; $i < $simulations; $i++) {
            $paths[$i][$t] = $paths[$i][$t - 1] * exp(($drift - 0.5 * $volatility ** 2) * $dt + $volatility * sqrt($dt) * $z[$i]);
        }
    }
    return $paths;
}

function option_pricing($prices, $strike, $option_type = 'call') {
    $option_values = array();
    if ($option_type == 'call') {
        foreach ($prices as $price) {
            $option_values[] = max($price - $strike, 0);
        }
    } elseif ($option_type == 'put') {
        foreach ($prices as $price) {
            $option_values[] = max($strike - $price, 0);
        }
    } else {
        return null;
    }
    return $option_values;
}

function main() {
    $steps = 252;
    $simulations = 10000;
    $strike = 105;
    $prices = simulate_prices($steps, $simulations);
    $option_values = option_pricing(array_column($prices, $steps - 1), $strike);
    echo array_sum($option_values) / count($option_values);
}

main();
?>