<?php

function generate_paths($S0, $T, $r, $sigma, $N, $M) {
    $dt = $T / $N;
    $paths = array_fill(0, $N + 1, array_fill(0, $M, 0));
    $paths[0] = array_fill(0, $M, $S0);
    for ($t = 1; $t <= $N; $t++) {
        $z = array_fill(0, $M, 0);
        for ($i = 0; $i < $M; $i++) {
            $z[$i] = mt_rand() / mt_getrandmax() * 2 - 1;
        }
        for ($i = 0; $i < $M; $i++) {
            $paths[$t][$i] = $paths[$t - 1][$i] * exp(($r - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * $z[$i]);
        }
    }
    return $paths;
}

function calculate_payoffs($paths, $K, $option_type) {
    $payoffs = array_fill(0, count($paths[0]), 0);
    if ($option_type == 'call') {
        for ($i = 0; $i < count($paths[0]); $i++) {
            $payoffs[$i] = max($paths[count($paths) - 1][$i] - $K, 0);
        }
    } elseif ($option_type == 'put') {
        for ($i = 0; $i < count($paths[0]); $i++) {
            $payoffs[$i] = max($K - $paths[count($paths) - 1][$i], 0);
        }
    }
    return $payoffs;
}

function price_option($S0, $K, $T, $r, $sigma, $N, $M, $option_type) {
    $paths = generate_paths($S0, $T, $r, $sigma, $N, $M);
    $payoffs = calculate_payoffs($paths, $K, $option_type);
    $mean_payoffs = array_sum($payoffs) / count($payoffs);
    return exp(-$r * $T) * $mean_payoffs;
}

function main() {
    $S0 = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $N = 100;
    $M = 10000;
    $option_type = 'call';
    $option_price = price_option($S0, $K, $T, $r, $sigma, $N, $M, $option_type);
    echo 'Option price: ' . number_format($option_price, 2) . "\n";
}

main();

?>