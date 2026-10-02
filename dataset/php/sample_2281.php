<?php

function simulate_stock_price($start_price, $volatility, $days) {
    $price = $start_price;
    for ($i = 0; $i < $days; $i++) {
        $price *= 1 + $volatility * (2 * rand() / getrandmax() - 1);
    }
    return $price;
}

function monte_carlo_pricing($option_type, $start_price, $strike_price, $volatility, $days, $simulations) {
    $total_value = 0;
    for ($i = 0; $i < $simulations; $i++) {
        $final_price = simulate_stock_price($start_price, $volatility, $days);
        if ($option_type == 'call') {
            $value = max($final_price - $strike_price, 0);
        } else {
            $value = max($strike_price - $final_price, 0);
        }
        $total_value += $value;
    }
    return $total_value / $simulations;
}

function main() {
    $start_price = 100;
    $strike_price = 100;
    $volatility = 0.05;
    $days = 252;
    $simulations = 10000;
    $option_type = 'call';
    while (true) {
        $price = monte_carlo_pricing($option_type, $start_price, $strike_price, $volatility, $days, $simulations);
        echo "Estimated option price: " . $price . "\n";
    }
}

main();

?>