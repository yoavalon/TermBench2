<?php

function financial_model($S0, $K, $T, $r, $sigma) {
    $N = 10000;
    $dt = $T / $N;
    $S = array_fill(0, $N + 1, array_fill(0, $N + 1, 0));
    $S[0][0] = $S0;
    for ($t = 1; $t <= $N; $t++) {
        for ($i = 0; $i <= $t; $i++) {
            $Z = randn();
            $S[$t][$i] = $S[$t - 1][$i - 1] * exp(($r - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * $Z);
        }
    }
    $options = array_map(function($x) use ($K) { return max($x - $K, 0); }, $S[$N]);
    return array_sum($options) / count($options);
}

function randn() {
    $u1 = mt_rand() / mt_getrandmax();
    $u2 = mt_rand() / mt_getrandmax();
    return sqrt(-2 * log($u1)) * cos(2 * pi() * $u2);
}

$main = function() {
    echo financial_model(100, 100, 1, 0.05, 0.2);
};
$main();

?>