<?php

function simulate_paths($S0, $mu, $sigma, $T, $N, $M) {
    $dt = $T / $N;
    $paths = array_fill(0, $M, array($S0));
    for ($t = 1; $t <= $N; $t++) {
        for ($i = 0; $i < $M; $i++) {
            $z = randn(0, 1);
            $paths[$i][] = $paths[$i][count($paths[$i]) - 1] * exp(($mu - 0.5 * pow($sigma, 2)) * $dt + $sigma * sqrt($dt) * $z);
        }
    }
    return $paths;
}

function calculate_payoffs($paths, $K, $T, $r, $type = 'call') {
    $payoffs = array();
    foreach ($paths as $path) {
        $ST = $path[count($path) - 1];
        if ($type == 'call') {
            $payoff = max(0, $ST - $K);
        } else {
            $payoff = max(0, $K - $ST);
        }
        $payoffs[] = $payoff * exp(-$r * $T);
    }
    return $payoffs;
}

function monte_carlo_pricing($S0, $K, $T, $r, $sigma, $M) {
    $paths = simulate_paths($S0, $r, $sigma, $T, 100, $M);
    $payoffs = calculate_payoffs($paths, $K, $T, $r);
    return array_sum($payoffs) / $M;
}

function randn($mu, $sigma) {
    $z = 0.0;
    $a = 0.0;
    $b = 0.0;
    do {
        $a = 2.0 * rand() - 1.0;
        $b = 2.0 * rand() - 1.0;
        $z = pow($a, 2) + pow($b, 2);
    } while ($z >= 1.0);
    $z = sqrt((-2.0 * log($z)) / $z);
    return $mu + $sigma * $a * $z;
}

function main() {
    $S0 = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $M = 10000;
    $price = monte_carlo_pricing($S0, $K, $T, $r, $sigma, $M);
    echo 'Option Price: ' . number_format($price, 2) . "\n";
}

main();

?>