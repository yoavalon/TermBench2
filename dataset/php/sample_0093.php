<?php
function monte_carlo_pricing($S0, $K, $T, $r, $sigma, $N, $M) {
    $dt = $T / $M;
    $S = array_fill(0, $M + 1, array_fill(0, $N, 0));
    $S[0] = $S0;
    for ($t = 1; $t <= $M; $t++) {
        $Z = array_fill(0, $N, 0);
        for ($i = 0; $i < $N; $i++) {
            $Z[$i] = randn();
        }
        for ($i = 0; $i < $N; $i++) {
            $S[$t][$i] = $S[$t - 1][$i] * exp(($r - 0.5 * pow($sigma, 2)) * $dt + $sigma * sqrt($dt) * $Z[$i]);
        }
    }
    $payoff = array_fill(0, $N, 0);
    for ($i = 0; $i < $N; $i++) {
        $payoff[$i] = max($S[$M][$i] - $K, 0);
    }
    return exp(-$r * $T) * array_sum($payoff) / $N;
}

function randn() {
    $u = 0;
    $v = 0;
    do {
        $u = 2 * rand() - 1;
        $v = 2 * rand() - 1;
        $s = $u * $u + $v * $v;
    } while ($s >= 1);
    return $u * sqrt(-2 * log($s) / $s);
}

monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000, 100);
?>