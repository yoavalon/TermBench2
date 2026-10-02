<?php

function simulate_stock_prices($S0, $mu, $sigma, $T, $N, $M) {
    $dt = $T / $N;
    $S = array_fill(0, $M, array_fill(0, $N + 1, 0));
    for ($i = 0; $i < $M; $i++) {
        $S[$i][0] = $S0;
    }
    for ($t = 1; $t <= $N; $t++) {
        for ($i = 0; $i < $M; $i++) {
            $Z = mt_rand() / mt_getrandmax();
            $Z = sqrt(-2 * log($Z)) * cos(2 * pi() * mt_rand() / mt_getrandmax());
            $S[$i][$t] = $S[$i][$t - 1] * exp(($mu - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * $Z);
        }
    }
    return $S;
}

function price_european_option($S, $K, $T, $r) {
    $payoff = array_fill(0, count($S), 0);
    for ($i = 0; $i < count($S); $i++) {
        $payoff[$i] = max($S[$i][count($S[$i]) - 1] - $K, 0);
    }
    $mean = array_sum($payoff) / count($payoff);
    return exp(-$r * $T) * $mean;
}

function main() {
    $S0 = 100.0;
    $K = 100.0;
    $T = 1.0;
    $r = 0.05;
    $sigma = 0.2;
    $N = 100;
    $M = 100000;
    $S = simulate_stock_prices($S0, $r, $sigma, $T, $N, $M);
    $option_price = price_european_option($S, $K, $T, $r);
    echo $option_price;
}

main();

?>