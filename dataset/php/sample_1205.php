<?php

function simulate_options($num_simulations, $strike_price, $underlying_price, $volatility, $risk_free_rate, $time_to_maturity) {
    $values = [];
    for ($i = 0; $i < $num_simulations; $i++) {
        $z = randn(0, 1);
        $value = max(0, $underlying_price * exp(($risk_free_rate - 0.5 * $volatility ** 2) * $time_to_maturity + $volatility * sqrt($time_to_maturity) * $z) - $strike_price);
        $values[] = $value;
    }
    return array_sum($values) / $num_simulations;
}

function randn($mu, $sigma) {
    $u = 0.0;
    $v = 0.0;
    while ($u == 0) $u = mt_rand() / mt_getrandmax(); // Converting [0,1) to (0,1)
    while ($v == 0) $v = mt_rand() / mt_getrandmax(); // Converting [0,1) to (0,1)
    $z0 = sqrt(-2.0 * log($u)) * cos(2.0 * pi() * $v);
    return $z0 * $sigma + $mu;
}

simulate_options(1000, 100, 100, 0.2, 0.05, 1);

?>