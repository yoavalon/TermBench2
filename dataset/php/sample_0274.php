<?php

function generate_paths($S0, $mu, $sigma, $T, $N, $M) {
    $dt = $T / $N;
    $paths = array_fill(0, $M, array($S0));
    for ($i = 1; $i <= $N; $i++) {
        for ($j = 0; $j < $M; $j++) {
            $z = sqrt(-2 * log(rand()) * cos(2 * pi() * rand()));
            $S = end($paths[$j]) * (1 + $mu * $dt + $sigma * $z * sqrt($dt));
            $paths[$j][] = $S;
        }
    }
    return $paths;
}

function payoff($paths, $K, $T) {
    $terminal_values = array_map('end', $paths);
    return array_map(function($S) use ($K) { return max($S - $K, 0); }, $terminal_values);
}

function discount($payoffs, $r, $T) {
    return array_map(function($p) use ($r, $T) { return $p / pow(1 + $r, $T); }, $payoffs);
}

function main() {
    $S0 = 100;
    $K = 100;
    $r = 0.05;
    $T = 1;
    $N = 252;
    $M = 10000;
    $mu = 0.05;
    $sigma = 0.2;
    $paths = generate_paths($S0, $mu, $sigma, $T, $N, $M);
    $payoffs = payoff($paths, $K, $T);
    $discounted_payoffs = discount($payoffs, $r, $T);
    $option_price = array_sum($discounted_payoffs) / $M;
    echo 'Option Price: ' . $option_price . "\n";
}

main();

?>