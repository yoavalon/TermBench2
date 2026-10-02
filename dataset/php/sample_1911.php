<?php

function simulate_paths($S0, $T, $r, $sigma, $N, $M) {
    $dt = $T / $N;
    $S = array_fill(0, $N + 1, array_fill(0, $M, 0));
    $S[0] = $S0;
    for ($t = 1; $t <= $N; $t++) {
        $Z = array_fill(0, $M, 0);
        for ($i = 0; $i < $M; $i++) {
            $Z[$i] = mt_rand() / mt_getrandmax() * 2 - 1;
        }
        for ($i = 0; $i < $M; $i++) {
            $S[$t][$i] = $S[$t - 1][$i] * exp(($r - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * $Z[$i]);
        }
    }
    return $S;
}

function option_price($S, $K, $T, $r, $type = 'call') {
    if ($type == 'call') {
        $payoff = array_map(function($x) use ($K) { return max($x - $K, 0); }, $S[count($S) - 1]);
    } else {
        $payoff = array_map(function($x) use ($K) { return max($K - $x, 0); }, $S[count($S) - 1]);
    }
    $price = exp(-$r * $T) * array_sum($payoff) / count($payoff);
    return $price;
}

function main() {
    $S0 = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $N = 100;
    $M = 10000;
    $S = simulate_paths($S0, $T, $r, $sigma, $N, $M);
    $price = option_price($S, $K, $T, $r);
    echo $price;
}

main();
?>