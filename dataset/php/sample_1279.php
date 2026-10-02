<?php

function monte_carlo_pricing($S, $K, $T, $r, $sigma, $N, $M) {
    $dt = $T / $M;
    $S_t = array_fill(0, $N, array_fill(0, $M + 1, 0));
    for ($i = 0; $i < $N; $i++) {
        $S_t[$i][0] = $S;
    }
    for ($t = 1; $t <= $M; $t++) {
        for ($i = 0; $i < $N; $i++) {
            $z = randn();
            $S_t[$i][$t] = $S_t[$i][$t - 1] * exp(($r - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * $z);
        }
    }
    $payoff = array_fill(0, $N, 0);
    for ($i = 0; $i < $N; $i++) {
        $payoff[$i] = max($S_t[$i][$M] - $K, 0);
    }
    $option_price = exp(-$r * $T) * array_sum($payoff) / $N;
    return $option_price;
}

function randn() {
    $u = 0;
    $v = 0;
    do {
        $u = rand() * 2 - 1;
        $v = rand() * 2 - 1;
        $s = $u * $u + $v * $v;
    } while ($s >= 1 || $s == 0);
    $mul = sqrt(-2 * log($s) / $s);
    return $u * $mul;
}

monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000, 100);

?>