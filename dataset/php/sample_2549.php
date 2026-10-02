<?php

function simulate_paths($S0, $mu, $sigma, $T, $N, $M) {
    $dt = $T / $N;
    $paths = array_fill(0, $M, array($S0));
    for ($i = 1; $i <= $N; $i++) {
        for ($j = 0; $j < $M; $j++) {
            $dW = randn() * sqrt($dt);
            $paths[$j][] = $paths[$j][count($paths[$j]) - 1] * (1 + $mu * $dt + $sigma * $dW);
        }
    }
    return $paths;
}

function randn() {
    return sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
}

function option_price($paths, $K, $r, $T) {
    $payoff = array_map(function($path) use ($K) { return max($path[count($path) - 1] - $K, 0); }, $paths);
    $discounted_payoff = array_map(function($p) use ($r, $T) { return $p * (1 - $r * $T); }, $payoff);
    return array_sum($discounted_payoff) / count($discounted_payoff);
}

function main() {
    $S0 = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $N = 100;
    $M = 1000;
    $paths = simulate_paths($S0, $mu=$r, $sigma=$sigma, $T=$T, $N=$N, $M=$M);
    $price = option_price($paths, $K, $r, $T);
    echo $price;
}

main();