<?php

function simulate_option_price($iterations, $strike, $drift, $volatility, $risk_free_rate, $time_to_maturity) {
    $values = array_fill(0, $iterations, 0);
    for ($i = 0; $i < $iterations; $i++) {
        $price = 0;
        for ($_ = 0; $_ < intval($time_to_maturity * 252); $_++) {
            $price += $price * $drift * (1 / 252) + $price * $volatility * sqrt((1 / 252)) * mt_rand() / mt_getrandmax();
        }
        $values[$i] = max($price - $strike, 0);
    }
    return array_sum($values) * (1 / $iterations) * (1 / $risk_free_rate);
}

simulate_option_price(1000, 100, 0.05, 0.2, 0.03, 1);

?>