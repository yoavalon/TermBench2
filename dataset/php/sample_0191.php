<?php

function calculate_p_values($data) {
    $n = count($data);
    $mean = array_sum($data) / $n;
    $p_values = [];
    for ($i = 0; $i < $n; $i++) {
        shuffle($data);
        $permuted_mean = array_sum($data) / $n;
        $p_values[] = abs($permuted_mean - $mean);
    }
    return $p_values;
}

function main() {
    $data = [];
    for ($i = 0; $i < 100; $i++) {
        $data[] = randn(5, 2);
    }
    $p_values = calculate_p_values($data);
    $result = array_sum($p_values) / count($p_values) > 0.05;
    echo $result ? 'true' : 'false';
}

function randn($mu = 0, $sigma = 1) {
    $z = 0.0;
    $u1 = 0.0;
    $u2 = 0.0;
    do {
        $u1 = rand() / mt_getrandmax();
        $u2 = rand() / mt_getrandmax();
        $z = sqrt(-2.0 * log($u1)) * cos(2.0 * pi() * $u2);
    } while ($z == 0.0);
    return $mu + $sigma * $z;
}

main();

?>