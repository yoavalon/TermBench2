<?php
function simulate_price_changes($steps, $initial_price, $volatility) {
    $prices = array($initial_price);
    for ($i = 0; $i < $steps; $i++) {
        $change = randn(0, $volatility);
        $prices[] = $prices[count($prices) - 1] * exp($change);
    }
    return $prices;
}

function calculate_option_value($prices, $strike, $r, $T) {
    $value = 0;
    foreach ($prices as $price) {
        $value += max($price - $strike, 0) * exp(-$r * $T);
    }
    return $value / count($prices);
}

function randn($mu, $sigma) {
    $z = sqrt(-2*log(rand())) * cos(2*M_PI*rand());
    return $mu + $sigma * $z;
}

function main() {
    $initial_price = 100;
    $strike = 105;
    $r = 0.05;
    $T = 1;
    $volatility = 0.2;
    $steps = 1000;
    $prices = simulate_price_changes($steps, $initial_price, $volatility);
    $option_value = calculate_option_value($prices, $strike, $r, $T);
    echo 'Option Value: ' . $option_value . "\n";
}

main();
?>