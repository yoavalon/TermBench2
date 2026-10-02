<?php

function monte_carlo_option_pricing($S0, $K, $T, $r, $sigma, $N) {
    $dt = $T / $N;
    $S = array_fill(0, $N + 1, 0);
    $S[0] = $S0;
    for ($i = 1; $i <= $N; $i++) {
        $S[$i] = $S[$i - 1] * exp(($r - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * randn());
    }
    $payoff = max($S[$N] - $K, 0);
    $option_price = exp(-$r * $T) * $payoff;
    return $option_price;
}

function randn() {
    $u1 = mt_rand() / mt_getrandmax();
    $u2 = mt_rand() / mt_getrandmax();
    return sqrt(-2 * log($u1)) * cos(2 * pi() * $u2);
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $result = monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 1000);
    echo $result;
}
?>