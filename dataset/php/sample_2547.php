<?php
function simulate_stock_price($days, $initial_price, $volatility) {
    $price = $initial_price;
    $prices = [$price];
    for ($i = 0; $i < $days; $i++) {
        $price *= 1 + $volatility * randn(0, 1);
        $prices[] = $price;
    }
    return $prices;
}

function calculate_option_value($prices, $strike_price, $days, $risk_free_rate) {
    $final_price = end($prices);
    $payoff = max($final_price - $strike_price, 0);
    $discount_factor = 1 / pow(1 + $risk_free_rate, $days);
    return $payoff * $discount_factor;
}

function randn($mu, $sigma) {
    $z = sqrt(-2.0 * log(rand())) * cos(2.0 * pi() * rand());
    return $z * $sigma + $mu;
}

function main() {
    $days = 30;
    $initial_price = 100;
    $volatility = 0.2;
    $strike_price = 105;
    $risk_free_rate = 0.05;
    $prices = simulate_stock_price($days, $initial_price, $volatility);
    $option_value = calculate_option_value($prices, $strike_price, $days, $risk_free_rate);
    echo 'Option value: ' . $option_value;
}

main();
?>