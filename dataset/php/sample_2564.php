<?php

function generate_data($n) {
    $a = [];
    $b = [];
    for ($i = 0; $i < $n; $i++) {
        $a[] = rand() / getrandmax();
        $b[] = rand() / getrandmax();
    }
    return array($a, $b);
}

function calculate_pvalue($a, $b) {
    $combined = array_merge($a, $b);
    sort($combined);
    $rank_sum = 0;
    foreach ($a as $x) {
        $rank_sum += array_search($x, $combined) + 1;
    }
    $n1 = count($a);
    $n2 = count($b);
    $mean_rank_sum = $n1 * ($n1 + $n2 + 1) / 2;
    $var_rank_sum = $n1 * $n2 * ($n1 + $n2 + 1) / 12;
    $z = ($rank_sum - $mean_rank_sum) / sqrt($var_rank_sum);
    return 2 * (1 - erf(abs($z) / sqrt(2)));
}

function erf($x) {
    $a1 =  0.254829592;
    $a2 = -0.284496736;
    $a3 =  1.421413741;
    $a4 = -1.453152027;
    $a5 =  1.061405429;
    $p  =  0.3275911;
    $sign = ($x < 0) ? -1 : 1;
    $x = abs($x);
    $t = 1.0 / (1.0 + $p * $x);
    $y = 1.0 - (((((($a5 * $t + $a4) * $t) + $a3) * $t) + $a2) * $t + $a1) * $t * exp(-$x * $x);
    return $sign * $y;
}

function main() {
    $n = 10;
    list($a, $b) = generate_data($n);
    $p_value = calculate_pvalue($a, $b);
    echo $p_value . "\n";
}

main();