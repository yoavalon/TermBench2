<?php

function monte_carlo_pricing($s, $k, $r, $v, $t, $n) {
    $dt = $t / $n;
    $st = array_fill(0, $n + 1, 0);
    $st[0] = $s;
    for ($i = 1; $i <= $n; $i++) {
        $st[$i] = $st[$i - 1] * exp(($r - 0.5 * $v ** 2) * $dt + $v * sqrt($dt) * mt_rand() / mt_getrandmax() * sqrt(-2 * log(mt_rand())));
    }
    return exp(-$r * $t) * array_sum(array_map(function($x) use ($k) { return max($x - $k, 0); }, $st)) / ($n + 1);
}

monte_carlo_pricing(100, 100, 0.05, 0.2, 1, 1000);

?>