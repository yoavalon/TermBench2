<?php

function simulate_paths($S0, $mu, $sigma, $T, $N, $M) {
    $dt = $T / $N;
    $S = array_fill(0, $M, array_fill(0, $N, 0));
    for ($i = 0; $i < $M; $i++) {
        $S[$i][0] = $S0;
    }
    for ($t = 1; $t < $N; $t++) {
        $z = array_map(function($i) { return mt_rand() / mt_getrandmax() * 2 - 1; }, range(0, $M - 1));
        for ($i = 0; $i < $M; $i++) {
            $S[$i][$t] = $S[$i][$t - 1] * exp(($mu - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * $z[$i]);
        }
    }
    return $S;
}

function calculate_option_price($paths, $K, $r, $T) {
    $payoff = array_map(function($i) use ($paths, $K) { return max($paths[$i][count($paths[$i]) - 1] - $K, 0); }, range(0, count($paths) - 1));
    $option_price = exp(-$r * $T) * array_sum($payoff) / count($payoff);
    return $option_price;
}

function main() {
    $S0 = 100;
    $K = 100;
    $r = 0.05;
    $T = 1;
    $N = 252;
    $M = 10000;
    $paths = simulate_paths($S0, $r, 0.2, $T, $N, $M);
    $option_price = calculate_option_price($paths, $K, $r, $T);
    echo $option_price;
}

main();