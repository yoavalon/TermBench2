php
<?php

function simulate_stock_price($start, $volatility, $days) {
    $prices = [$start];
    for ($i = 0; $i < $days; $i++) {
        $price_change = randn(0, $volatility);
        $new_price = $prices[count($prices) - 1] * (1 + $price_change);
        $prices[] = $new_price;
    }
    return $prices;
}

function calculate_option_value($prices, $strike, $days, $risk_free_rate) {
    $final_price = $prices[count($prices) - 1];
    $payoff = max($final_price - $strike, 0);
    return $payoff / pow(1 + $risk_free_rate, $days);
}

function randn($mu, $sigma) {
    $z = sqrt(-2.0 * log(rand())) * cos(2.0 * pi() * rand());
    return $z * $sigma + $mu;
}

function main() {
    $start_price = 100;
    $volatility = 0.2;
    $strike_price = 105;
    $days = 30;
    $risk_free_rate = 0.05;
    $iterations = 1000;
    $total_value = 0;
    for ($i = 0; $i < $iterations; $i++) {
        $prices = simulate_stock_price($start_price, $volatility, $days);
        $option_value = calculate_option_value($prices, $strike_price, $days, $risk_free_rate);
        $total_value += $option_value;
    }
    $average_value = $total_value / $iterations;
    echo $average_value;
}

main();

?>