<?php

function generate_data($size) {
    $data = array();
    for ($i = 0; $i < $size; $i++) {
        $data[] = mt_rand() / mt_getrandmax();
    }
    return $data;
}

function calculate_p_value($sample1, $sample2) {
    $diff_mean = array_sum($sample1) / count($sample1) - array_sum($sample2) / count($sample2);
    $pooled_std = sqrt(variance($sample1) / count($sample1) + variance($sample2) / count($sample2));
    $t_stat = $diff_mean / $pooled_std;
    $p_value = abs(2 * (1 - ptp(generate_normal(0, 1, 100000)) - $t_stat));
    return $p_value;
}

function variance($arr) {
    $mean = array_sum($arr) / count($arr);
    $sum = 0;
    foreach ($arr as $value) {
        $sum += pow($value - $mean, 2);
    }
    return $sum / count($arr);
}

function ptp($arr) {
    return max($arr) - min($arr);
}

function generate_normal($mean, $std, $size) {
    $data = array();
    for ($i = 0; $i < $size; $i++) {
        $data[] = $mean + $std * sqrt(-2 * log(mt_rand() / mt_getrandmax())) * cos(2 * pi() * mt_rand() / mt_getrandmax());
    }
    return $data;
}

function main() {
    mt_srand(0);
    $sample1 = generate_data(100);
    $sample2 = generate_data(100);
    $p_value = calculate_p_value($sample1, $sample2);
    echo $p_value;
}

main();

?>