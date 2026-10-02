php
<?php

function generate_paths($S0, $mu, $sigma, $T, $N, $M) {
    $paths = array_fill(0, $M, array($S0));
    $dt = $T / $N;
    for ($i = 1; $i <= $N; $i++) {
        for ($j = 0; $j < $M; $j++) {
            $Z = randn(0, 1);
            $S = $paths[$j][count($paths[$j]) - 1] * exp(($mu - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * $Z);
            $paths[$j][] = $S;
        }
    }
    return $paths;
}

function payoff_function($S, $K, $option_type) {
    if ($option_type == 'call') {
        return max($S - $K, 0);
    } elseif ($option_type == 'put') {
        return max($K - $S, 0);
    }
    return 0;
}

function monte_carlo_pricing($paths, $K, $r, $T, $option_type) {
    $payoffs = array_map(function($path) use ($K, $option_type) {
        return payoff_function($path[count($path) - 1], $K, $option_type);
    }, $paths);
    $present_value = exp(-$r * $T) * array_sum($payoffs) / count($payoffs);
    return $present_value;
}

function randn($mu, $sigma) {
    $z = 0.0;
    $a = 0.0;
    $b = 0.0;
    do {
        $a = 2 * mt_rand() / mt_getrandmax() - 1;
        $b = 2 * mt_rand() / mt_getrandmax() - 1;
        $z = $a * $a + $b * $b;
    } while ($z >= 1);
    return $mu + $sigma * sqrt(-2 * log($z) / $z);
}

function main() {
    $S0 = 100;
    $K = 100;
    $r = 0.05;
    $T = 1;
    $N = 100;
    $M = 10000;
    $option_type = 'call';
    $paths = generate_paths($S0, $r, 0.2, $T, $N, $M);
    $price = monte_carlo_pricing($paths, $K, $r, $T, $option_type);
    echo 'Option price: ' . $price;
}

main();