<?php

function monte_carlo_pricing($S, $K, $T, $r, $sigma, $N) {
    $dt = $T / $N;
    $S_t = array_fill(0, $N + 1, 0);
    $S_t[0] = $S;
    $z = array_fill(0, $N, 0);
    for ($i = 0; $i < $N; $i++) {
        $z[$i] = mt_rand() / mt_getrandmax() * 2 - 1;
    }
    for ($i = 1; $i <= $N; $i++) {
        $S_t[$i] = $S_t[$i - 1] * exp(($r - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * $z[$i - 1]);
    }
    $payoff = max($S_t[$N] - $K, 0);
    $option_price = exp(-$r * $T) * array_sum($payoff) / $N;
    return $option_price;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000);
    echo $result;
}