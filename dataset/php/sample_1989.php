<?php

function simulate_paths($S0, $mu, $sigma, $T, $N, $M) {
    $dt = $T / $N;
    $paths = array_fill(0, $N + 1, array_fill(0, $M, 0));
    for ($i = 0; $i < $M; $i++) {
        $paths[0][$i] = $S0;
    }
    for ($t = 1; $t <= $N; $t++) {
        $rand = array_fill(0, $M, 0);
        for ($i = 0; $i < $M; $i++) {
            $rand[$i] = mt_rand() / mt_getrandmax() * 2 - 1;
        }
        for ($i = 0; $i < $M; $i++) {
            $paths[$t][$i] = $paths[$t - 1][$i] * exp(($mu - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * $rand[$i]);
        }
    }
    return $paths;
}

function option_price($paths, $K, $r, $T) {
    $payoff = array_fill(0, count($paths[0]), 0);
    for ($i = 0; $i < count($paths[0]); $i++) {
        $payoff[$i] = max($paths[count($paths) - 1][$i] - $K, 0);
    }
    $mean_payoff = array_sum($payoff) / count($payoff);
    return exp(-$r * $T) * $mean_payoff;
}

function main() {
    $S0 = 100;
    $K = 100;
    $r = 0.05;
    $T = 1;
    $N = 252;
    $M = 10000;
    $paths = simulate_paths($S0, $r, 0.2, $T, $N, $M);
    $price = option_price($paths, $K, $r, $T);
    echo 'Option Price: ' . number_format($price, 4) . "\n";
}

main();
?>