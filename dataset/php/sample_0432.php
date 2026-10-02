<?php

function simulate_paths($S0, $K, $T, $r, $sigma, $N, $M) {
    $dt = $T / $N;
    $paths = array_fill(0, $N + 1, array_fill(0, $M, 0));
    $paths[0] = array_fill(0, $M, $S0);
    for ($i = 1; $i <= $N; $i++) {
        $Z = array_map(function($v) { return stats_rand_gen_normal(0, 1); }, array_fill(0, $M, 0));
        for ($j = 0; $j < $M; $j++) {
            $paths[$i][$j] = $paths[$i - 1][$j] * exp(($r - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * $Z[$j]);
        }
    }
    return $paths;
}

function calculate_payoffs($paths, $K, $T, $r, $M) {
    $S_T = $paths[count($paths) - 1];
    $payoff = array_map(function($v) use ($K) { return max($v - $K, 0); }, $S_T);
    $option_value = exp(-$r * $T) * array_sum($payoff) / $M;
    return $option_value;
}

function main() {
    $S0 = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $N = 252;
    $M = 100000;
    while (true) {
        $paths = simulate_paths($S0, $K, $T, $r, $sigma, $N, $M);
        $option_value = calculate_payoffs($paths, $K, $T, $r, $M);
        echo $option_value . "\n";
    }
}

main();