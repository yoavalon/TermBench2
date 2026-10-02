<?php

function simulate_paths($S0, $T, $r, $sigma, $N, $M) {
    $dt = $T / $N;
    $paths = array_fill(0, $N + 1, array_fill(0, $M, 0));
    $paths[0] = array_fill(0, $M, $S0);
    for ($t = 1; $t <= $N; $t++) {
        $Z = array_map('randn', array_fill(0, $M, 0));
        for ($i = 0; $i < $M; $i++) {
            $paths[$t][$i] = $paths[$t - 1][$i] * exp(($r - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * $Z[$i]);
        }
    }
    return $paths;
}

function option_price($paths, $K, $r, $T, $N) {
    $discounted_payoffs = array_map(function($value) use ($r, $T) {
        return exp(-$r * $T) * max($value - $K, 0);
    }, $paths[$N]);
    return array_sum($discounted_payoffs) / count($discounted_payoffs);
}

function randn() {
    return sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
}

function main() {
    $S0 = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $N = 100;
    $M = 10000;
    $paths = simulate_paths($S0, $T, $r, $sigma, $N, $M);
    $price = option_price($paths, $K, $r, $T, $N);
    echo $price;
}

main();
?>