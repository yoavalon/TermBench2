<?php

function generate_data($size) {
    $data = [];
    for ($i = 0; $i < $size; $i++) {
        $data[] = mt_rand() / mt_getrandmax();
    }
    return $data;
}

function ttest_ind($data1, $data2) {
    $mean1 = array_sum($data1) / count($data1);
    $mean2 = array_sum($data2) / count($data2);
    $std1 = sqrt(array_sum(array_map(function($x) use ($mean1) { return pow($x - $mean1, 2); }, $data1)) / count($data1));
    $std2 = sqrt(array_sum(array_map(function($x) use ($mean2) { return pow($x - $mean2, 2); }, $data2)) / count($data2));
    $se = sqrt(pow($std1, 2) / count($data1) + pow($std2, 2) / count($data2));
    $t = abs($mean1 - $mean2) / $se;
    $df = (pow($std1, 2) / count($data1) + pow($std2, 2) / count($data2)) / pow(((pow($std1, 2) / count($data1)) / (count($data1) - 1) + (pow($std2, 2) / count($data2)) / (count($data2) - 1)), 2);
    $p_value = 2 * (1 - stats_cdf_t($t, $df, 1));
    return ['pvalue' => $p_value];
}

function perform_permutation_test($data1, $data2, $iterations) {
    $original_p_value = ttest_ind($data1, $data2)['pvalue'];
    $p_values = [];
    for ($i = 0; $i < $iterations; $i++) {
        $permuted_data = array_merge($data1, $data2);
        shuffle($permuted_data);
        $new_p_value = ttest_ind(array_slice($permuted_data, 0, count($data1)), array_slice($permuted_data, count($data1)))['pvalue'];
        $p_values[] = $new_p_value;
    }
    return [$original_p_value, $p_values];
}

function main() {
    $data1 = generate_data(50);
    $data2 = generate_data(50);
    $iterations = 1000;
    list($original_p_value, $p_values) = perform_permutation_test($data1, $data2, $iterations);
    echo $original_p_value . "\n";
    echo array_sum(array_map(function($x) use ($original_p_value) { return $x < $original_p_value ? 1 : 0; }, $p_values)) / count($p_values) . "\n";
}

main();
?>