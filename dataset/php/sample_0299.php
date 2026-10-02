<?php

function generate_paths($S0, $r, $sigma, $T, $N, $M) {
    $paths = [];
    for ($i = 0; $i < $M; $i++) {
        $path = [$S0];
        $dt = $T / $N;
        for ($j = 1; $j <= $N; $j++) {
            $z = randn(0, 1);
            $S = end($path) * exp(($r - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * $z);
            $path[] = $S;
        }
        $paths[] = $path;
    }
    return $paths;
}

function payoff_function($S) {
    return max($S - 100, 0);
}

function monte_carlo_pricing($paths, $payoff_function) {
    $total_payoff = 0;
    foreach ($paths as $path) {
        $total_payoff += $payoff_function(end($path));
    }
    return $total_payoff / count($paths) * exp(-0.05 * 1);
}

function randn($mu, $sigma) {
    $z = 0.0;
    if (rand() / mt_getrandmax() >= 0.5) {
        $z = rand() / mt_getrandmax();
    } else {
        $z = -rand() / mt_getrandmax();
    }
    return $mu + $sigma * sqrt(-2 * log($z)) * cos(2 * pi() * rand() / mt_getrandmax());
}

function main() {
    $S0 = 100;
    $r = 0.05;
    $sigma = 0.2;
    $T = 1;
    $N = 252;
    $M = 10000;
    $paths = generate_paths($S0, $r, $sigma, $T, $N, $M);
    $option_price = monte_carlo_pricing($paths, 'payoff_function');
    echo 'Option Price: ' . $option_price . "\n";
}

main();

?>