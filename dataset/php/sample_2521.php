<?php

function generate_data($size) {
    $data1 = [];
    $data2 = [];
    for ($i = 0; $i < $size; $i++) {
        $data1[] = mt_rand() / mt_getrandmax();
        $data2[] = (mt_rand() / mt_getrandmax()) * 0.5 + 0.5;
    }
    return array($data1, $data2);
}

function calculate_p_values($data1, $data2, $iterations) {
    $p_values = [];
    for ($i = 0; $i < $iterations; $i++) {
        shuffle($data1);
        shuffle($data2);
        $p_value = ttest_ind($data1, $data2);
        $p_values[] = $p_value;
    }
    return $p_values;
}

function ttest_ind($data1, $data2) {
    $mean1 = array_sum($data1) / count($data1);
    $mean2 = array_sum($data2) / count($data2);
    $var1 = array_sum(array_map(function($x) use ($mean1) { return pow($x - $mean1, 2); }, $data1)) / count($data1);
    $var2 = array_sum(array_map(function($x) use ($mean2) { return pow($x - $mean2, 2); }, $data2)) / count($data2);
    $df = (pow($var1 / count($data1) + $var2 / count($data2), 2) / 
           (pow($var1 / count($data1), 2) / (count($data1) - 1) + pow($var2 / count($data2), 2) / (count($data2) - 1)));
    $t = abs($mean1 - $mean2) / sqrt($var1 / count($data1) + $var2 / count($data2));
    return 1 - stats_cdf_t($t, $df, 1);
}

function main() {
    list($data1, $data2) = generate_data(100);
    $p_values = calculate_p_values($data1, $data2, 1000);
    echo array_sum($p_values) / count($p_values);
}

main();

?>