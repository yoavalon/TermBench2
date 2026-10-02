<?php

function simulate_paths($S0, $T, $r, $sigma, $N, $M) {
    $dt = $T / $N;
    $paths = array_fill(0, $N + 1, array_fill(0, $M, 0));
    $paths[0] = $S0;
    for ($t = 1; $t <= $N; $t++) {
        $z = array_map('randn', array_fill(0, $M, 0));
        for ($i = 0; $i < $M; $i++) {
            $paths[$t][$i] = $paths[$t - 1][$i] * exp(($r - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * $z[$i]);
        }
    }
    return $paths;
}

function payoff_function($paths, $K, $option_type) {
    if ($option_type == 'call') {
        return array_map(function($x) use ($K) { return max($x - $K, 0); }, $paths[count($paths) - 1]);
    } elseif ($option_type == 'put') {
        return array_map(function($x) use ($K) { return max($K - $x, 0); }, $paths[count($paths) - 1]);
    }
}

function price_option($S0, $K, $T, $r, $sigma, $N, $M, $option_type) {
    $paths = simulate_paths($S0, $T, $r, $sigma, $N, $M);
    $payoff = payoff_function($paths, $K, $option_type);
    return exp(-$r * $T) * array_sum($payoff) / count($payoff);
}

function main() {
    $S0 = 100.0;
    $K = 100.0;
    $T = 1.0;
    $r = 0.05;
    $sigma = 0.2;
    $N = 252;
    $M = 10000;
    $option_type = 'call';
    $option_price = price_option($S0, $K, $T, $r, $sigma, $N, $M, $option_type);
    echo 'Option Price: ' . $option_price . PHP_EOL;
}

function randn() {
    return sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
}

main();

?>