php
<?php

function generate_data($size) {
    $data1 = [];
    $data2 = [];
    for ($i = 0; $i < $size; $i++) {
        $data1[] = mt_rand() / mt_getrandmax() * 2 - 1;
        $data2[] = mt_rand() / mt_getrandmax() * 2 - 0.5;
    }
    return array($data1, $data2);
}

function perform_ttest($data1, $data2) {
    $mean1 = array_sum($data1) / count($data1);
    $mean2 = array_sum($data2) / count($data2);
    $std1 = sqrt(array_sum(array_map(function($x) use ($mean1) { return pow($x - $mean1, 2); }, $data1)) / count($data1));
    $std2 = sqrt(array_sum(array_map(function($x) use ($mean2) { return pow($x - $mean2, 2); }, $data2)) / count($data2));
    $t_stat = ($mean1 - $mean2) / sqrt((pow($std1, 2) / count($data1)) + (pow($std2, 2) / count($data2)));
    $p_value = 2 * (1 - stats_cdf_t(abs($t_stat), count($data1) + count($data2) - 2, 1));
    return array($t_stat, $p_value);
}

function permute_data($data1, $data2, $iterations) {
    $p_values = [];
    for ($i = 0; $i < $iterations; $i++) {
        $combined = array_merge($data1, $data2);
        shuffle($combined);
        $permuted_data1 = array_slice($combined, 0, count($data1));
        $permuted_data2 = array_slice($combined, count($data1));
        list($t_stat, $permuted_p_value) = perform_ttest($permuted_data1, $permuted_data2);
        $p_values[] = $permuted_p_value;
    }
    return $p_values;
}

function analyze_p_values($p_values, $original_p_value, $alpha = 0.05) {
    $less_extreme = array_filter($p_values, function($p) use ($original_p_value) { return $p <= $original_p_value; });
    $p_value_permutation = count($less_extreme) / count($p_values);
    return $p_value_permutation < $alpha;
}

function main() {
    list($data1, $data2) = generate_data(30);
    list($t_stat, $original_p_value) = perform_ttest($data1, $data2);
    $p_values = permute_data($data1, $data2, 1000);
    $result = analyze_p_values($p_values, $original_p_value);
    echo $result ? 'true' : 'false';
}

main();

?>