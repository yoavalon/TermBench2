<?php

function monte_carlo_pricing($S, $K, $T, $r, $sigma, $N) {
    $dt = $T / $N;
    $mu = $r - 0.5 * $sigma ** 2;
    $S_paths = array_fill(0, $N + 1, array_fill(0, count($S), 0));
    $S_paths[0] = $S;
    for ($t = 1; $t <= $N; $t++) {
        $z = array_map(function() { return mt_rand() / mt_getrandmax() * 2 - 1; }, array_fill(0, count($S), 0));
        foreach ($z as $i => $value) {
            $S_paths[$t][$i] = $S_paths[$t - 1][$i] * exp($mu * $dt + $sigma * sqrt($dt) * $value);
        }
    }
    $payoff = array_map(function($price) use ($K) { return max($price - $K, 0); }, $S_paths[$N]);
    return exp(-$r * $T) * array_sum($payoff) / count($payoff);
}

main = function() {
    $S = [100];
    monte_carlo_pricing($S, 100, 1, 0.05, 0.2, 100000);
};

main();

?>