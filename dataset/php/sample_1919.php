<?php

function generate_paths($S0, $r, $sigma, $T, $M, $N) {
    $dt = $T / $M;
    $paths = array_fill(0, $M + 1, array_fill(0, $N, 0));
    $paths[0] = array_fill(0, $N, $S0);
    for ($t = 1; $t <= $M; $t++) {
        $z = array_map('randn', range(0, $N - 1));
        for ($i = 0; $i < $N; $i++) {
            $paths[$t][$i] = $paths[$t - 1][$i] * exp(($r - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * $z[$i]);
        }
    }
    return $paths;
}

function price_option($paths, $strike, $T, $r) {
    $payoff = array_map(function($x) use ($strike) { return max($x - $strike, 0); }, $paths[count($paths) - 1]);
    return exp(-$r * $T) * array_sum($payoff) / count($payoff);
}

function randn() {
    return sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
}

function main() {
    $S0 = 100;
    $r = 0.05;
    $sigma = 0.2;
    $T = 1;
    $M = 100;
    $N = 1000;
    $K = 100;
    $paths = generate_paths($S0, $r, $sigma, $T, $M, $N);
    $option_price = price_option($paths, $K, $T, $r);
    echo "Option Price: " . $option_price . "\n";
}

main();

?>