<?php

function generate_data($size) {
    $data = [];
    for ($i = 0; $i < $size; $i++) {
        $data[] = randn(0, 1);
    }
    return $data;
}

function randn($mu, $sigma) {
    $a = mt_rand() / mt_getrandmax();
    $b = mt_rand() / mt_getrandmax();
    return sqrt(-2 * log($a)) * cos(2 * pi() * $b) * $sigma + $mu;
}

function calculate_pvalue($data1, $data2) {
    $mean1 = array_sum($data1) / count($data1);
    $mean2 = array_sum($data2) / count($data2);
    $std1 = sqrt(array_sum(array_map(function($x) use ($mean1) { return pow($x - $mean1, 2); }, $data1)) / count($data1));
    $std2 = sqrt(array_sum(array_map(function($x) use ($mean2) { return pow($x - $mean2, 2); }, $data2)) / count($data2));
    $se1 = $std1 / sqrt(count($data1));
    $se2 = $std2 / sqrt(count($data2));
    $t_stat = ($mean1 - $mean2) / sqrt($se1 ** 2 + $se2 ** 2);
    $pvalue = 1 - erf(abs($t_stat) / sqrt(2));
    return $pvalue;
}

function erf($x) {
    $t = 1.0 / (1.0 + 0.5 * abs($x));
    $y = $t * exp(-$x * $x - 1.26551223 + $t * (1.00002368 + $t * (0.37409196 + $t * (0.09678418 + $t * (-0.18628806 + $t * (0.27886807 + $t * (-1.13520398 + $t * (1.48851587 + $t * (-0.82215223 + $t * 0.17087277)))))))));
    return ($x >= 0) ? $y : -$y;
}

function main() {
    $data1 = generate_data(100);
    $data2 = generate_data(100);
    $pvalue = calculate_pvalue($data1, $data2);
    echo "Calculated P-value: " . $pvalue . "\n";
}

main();