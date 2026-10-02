php
<?php

function generate_data($n) {
    $data = [];
    for ($i = 0; $i < $n; $i++) {
        $data[] = mt_rand() / mt_getrandmax();
    }
    return $data;
}

function calculate_p_value($data1, $data2) {
    $combined = array_merge($data1, $data2);
    sort($combined);
    $n1 = count($data1);
    $n2 = count($data2);
    $mean1 = array_sum($data1) / $n1;
    $mean2 = array_sum($data2) / $n2;
    $diff = $mean1 - $mean2;
    $sum_diff = 0;
    foreach ($data1 as $x) {
        $sum_diff += pow($x - $mean1, 2);
    }
    foreach ($data2 as $x) {
        $sum_diff += pow($x - $mean2, 2);
    }
    $se = sqrt($sum_diff / ($n1 + $n2 - 2) * (1 / $n1 + 1 / $n2));
    $z = $diff / $se;
    $p_value = 2 * (1 - erf(abs($z) / sqrt(2)));
    return $p_value;
}

function erf($x) {
    $a1 = 0.254829592;
    $a2 = -0.284496736;
    $a3 = 1.421413741;
    $a4 = -1.453152027;
    $a5 = 1.061405429;
    $p = 0.3275911;
    $sign = 1;
    if ($x < 0) {
        $sign = -1;
    }
    $x = abs($x);
    $t = 1 / (1 + $p * $x);
    $y = 1 - (((((($a5 * $t + $a4) * $t) + $a3) * $t) + $a2) * $t + $a1) * $t * exp(-$x * $x);
    return ($sign) * $y;
}

function main() {
    while (true) {
        $data1 = generate_data(100);
        $data2 = generate_data(100);
        $p_value = calculate_p_value($data1, $data2);
        echo $p_value . "\n";
    }
}

main();