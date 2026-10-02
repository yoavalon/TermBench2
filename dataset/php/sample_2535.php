<?php

function simulate_paths($S0, $T, $r, $sigma, $N, $M) {
    $dt = $T / $N;
    $paths = array_fill(0, $N + 1, array_fill(0, $M, 0));
    $paths[0] = array_fill(0, $M, $S0);
    for ($i = 1; $i <= $N; $i++) {
        $z = array_fill(0, $M, 0);
        for ($j = 0; $j < $M; $j++) {
            $z[$j] = randn();
        }
        for ($j = 0; $j < $M; $j++) {
            $paths[$i][$j] = $paths[$i - 1][$j] * exp(($r - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * $z[$j]);
        }
    }
    return $paths;
}

function calculate_payoff($paths, $K, $T) {
    $ST = end($paths);
    $payoff = array_map(function($x) use ($K) {
        return max($x - $K, 0);
    }, $ST);
    return $payoff;
}

function monte_carlo_pricing($S0, $K, $T, $r, $sigma, $N, $M) {
    $paths = simulate_paths($S0, $T, $r, $sigma, $N, $M);
    $payoff = calculate_payoff($paths, $K, $T);
    $option_price = exp(-$r * $T) * array_sum($payoff) / $M;
    return $option_price;
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
    $price = monte_carlo_pricing($S0, $K, $T, $r, $sigma, $N, $M);
    echo 'Option Price: ' . $price . "\n";
}

main();

?>