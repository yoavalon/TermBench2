<?php

function monte_carlo_option_pricing($s, $x, $t, $r, $v, $n) {
    $dt = $t / $n;
    $st = array_fill(0, $n + 1, 0);
    $st[0] = $s;
    for ($i = 1; $i <= $n; $i++) {
        $st[$i] = $st[$i - 1] * exp(($r - 0.5 * $v ** 2) * $dt + $v * sqrt($dt) * randn());
    }
    return exp(-$r * $t) * array_sum(array_map(function($value) use ($x) { return max($value - $x, 0); }, $st)) / ($n + 1);
}

function randn() {
    return sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
}

monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 1000);

?>