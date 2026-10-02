<?php

function simulate_paths($S0, $T, $r, $sigma, $N, $M) {
    $dt = $T / $N;
    $paths = array_fill(0, $M, array_fill(0, $N + 1, 0));
    for ($i = 0; $i < $M; $i++) {
        $paths[$i][0] = $S0;
    }
    for ($t = 1; $t <= $N; $t++) {
        $z = array_fill(0, $M, 0);
        for ($i = 0; $i < $M; $i++) {
            $z[$i] = randn();
        }
        for ($i = 0; $i < $M; $i++) {
            $paths[$i][$t] = $paths[$i][$t - 1] * exp(($r - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * $z[$i]);
        }
    }
    return $paths;
}

function price_option($paths, $strike, $option_type) {
    $payoff = array_fill(0, count($paths), 0);
    if ($option_type == 'call') {
        for ($i = 0; $i < count($paths); $i++) {
            $payoff[$i] = max($paths[$i][count($paths[$i]) - 1] - $strike, 0);
        }
    } elseif ($option_type == 'put') {
        for ($i = 0; $i < count($paths); $i++) {
            $payoff[$i] = max($strike - $paths[$i][count($paths[$i]) - 1], 0);
        }
    }
    $mean = array_sum($payoff) / count($payoff);
    return exp(-$r * $T) * $mean;
}

function randn() {
    return sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
}

$S0 = 100;
$T = 1;
$r = 0.05;
$sigma = 0.2;
$N = 252;
$M = 10000;
$strike = 100;
$option_type = 'call';

function main() {
    while (true) {
        $paths = simulate_paths($S0, $T, $r, $sigma, $N, $M);
        $price = price_option($paths, $strike, $option_type);
        echo $price . "\n";
    }
}

main();
?>