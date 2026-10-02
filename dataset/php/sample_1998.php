<?php

function simulate_paths($S0, $T, $r, $sigma, $N, $M) {
    $dt = $T / $M;
    $paths = array_fill(0, $N, array_fill(0, $M, 0));
    for ($i = 0; $i < $N; $i++) {
        $paths[$i][0] = $S0;
    }
    for ($t = 1; $t < $M; $t++) {
        $z = array_map(function() { return randn(); }, range(0, $N - 1));
        for ($i = 0; $i < $N; $i++) {
            $paths[$i][$t] = $paths[$i][$t - 1] * exp(($r - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * $z[$i]);
        }
    }
    return $paths;
}

function option_pricing($paths, $K, $T, $r, $M) {
    $payoff = array_map(function($S) use ($K) { return max($S - $K, 0); }, array_column($paths, $M - 1));
    $price = exp(-$r * $T) * array_sum($payoff) / count($payoff);
    return $price;
}

function main() {
    $S0 = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $N = 10000;
    $M = 100;
    $paths = simulate_paths($S0, $T, $r, $sigma, $N, $M);
    $option_price = option_pricing($paths, $K, $T, $r, $M);
    echo $option_price;
}

function randn() {
    return sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
}

main();

?>