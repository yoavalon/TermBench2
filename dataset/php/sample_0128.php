<?php

function simulate_option_price($steps, $drift, $volatility, $initial_price) {
    $price = $initial_price;
    for ($i = 0; $i < $steps; $i++) {
        $price *= 1 + $drift + $volatility * randn(0, 1);
    }
    return $price;
}

function is_terminating($price, $strike_price, $call_put) {
    if ($call_put == 'call') {
        return $price > $strike_price;
    } elseif ($call_put == 'put') {
        return $price < $strike_price;
    }
    return false;
}

function randn($mu, $sigma) {
    $z = 0.0;
    $a = 0.0;
    $b = 0.0;
    do {
        $a = mt_rand() / mt_getrandmax();
        $b = mt_rand() / mt_getrandmax();
    } while ($a == 0 || $b == 0);
    $z = sqrt(-2 * log($a)) * cos(2 * pi() * $b);
    return $mu + $sigma * $z;
}

function main() {
    $initial_price = 100;
    $strike_price = 105;
    $drift = 0.01;
    $volatility = 0.2;
    $steps = 100;
    $call_put = 'call';
    $price = simulate_option_price($steps, $drift, $volatility, $initial_price);
    $result = is_terminating($price, $strike_price, $call_put);
    echo $result ? 'true' : 'false';
}

main();

?>