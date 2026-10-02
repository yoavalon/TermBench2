<?php

function simulate_paths($S0, $mu, $sigma, $T, $N, $M) {
    $dt = $T / $N;
    $paths = array_fill(0, $M, array_fill(0, $N + 1, 0.0));
    for ($i = 0; $i < $M; $i++) {
        $paths[$i][0] = $S0;
    }
    for ($t = 1; $t <= $N; $t++) {
        $z = array_map(function() { return mt_rand() / mt_getrandmax() * 2 - 1; }, range(0, $M - 1));
        for ($i = 0; $i < $M; $i++) {
            $paths[$i][$t] = $paths[$i][$t - 1] * exp(($mu - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * $z[$i]);
        }
    }
    return $paths;
}

function option_price($paths, $K, $r, $T) {
    $payoff = array_map(function($path) use ($K) { return max($path - $K, 0); }, array_column($paths, $N));
    return exp(-$r * $T) * array_sum($payoff) / count($payoff);
}

function main() {
    $S0 = 100.0;
    $K = 100.0;
    $r = 0.05;
    $T = 1.0;
    $N = 252;
    $M = 10000;
    $paths = simulate_paths($S0, $r, 0.2, $T, $N, $M);
    $price = option_price($paths, $K, $r, $T);
    echo 'Option price: ' . number_format($price, 2) . PHP_EOL;
}

main();