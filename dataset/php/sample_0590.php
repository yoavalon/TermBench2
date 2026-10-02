<?php

function simulate_data($size) {
    $data1 = array();
    $data2 = array();
    for ($i = 0; $i < $size; $i++) {
        $data1[] = mt_rand() / mt_getrandmax();
        $data2[] = (mt_rand() / mt_getrandmax()) * 1.5 + 0.5;
    }
    return array($data1, $data2);
}

function calculate_p_values($data1, $data2, $num_permutations) {
    $original_p_value = ttest_ind($data1, $data2)[1];
    $p_values = array();
    for ($i = 0; $i < $num_permutations; $i++) {
        $permuted_data = array_merge($data1, $data2);
        shuffle($permuted_data);
        $permuted_data1 = array_slice($permuted_data, 0, count($data1));
        $permuted_data2 = array_slice($permuted_data, count($data1));
        $p_value = ttest_ind($permuted_data1, $permuted_data2)[1];
        $p_values[] = $p_value;
    }
    return array($original_p_value, $p_values);
}

function analyze_results($original_p_value, $p_values) {
    sort($p_values);
    $p_value_rank = 1;
    foreach ($p_values as $p) {
        if ($p < $original_p_value) {
            $p_value_rank++;
        }
    }
    $p_value_adjusted = $p_value_rank / (count($p_values) + 1);
    return $p_value_adjusted;
}

function ttest_ind($data1, $data2) {
    $mean1 = array_sum($data1) / count($data1);
    $mean2 = array_sum($data2) / count($data2);
    $std1 = sqrt(array_sum(array_map(function($x) use ($mean1) { return pow($x - $mean1, 2); }, $data1)) / count($data1));
    $std2 = sqrt(array_sum(array_map(function($x) use ($mean2) { return pow($x - $mean2, 2); }, $data2)) / count($data2));
    $t_statistic = ($mean1 - $mean2) / sqrt(($std1 * $std1 / count($data1)) + ($std2 * $std2 / count($data2)));
    $degrees_of_freedom = (pow($std1 * $std1 / count($data1) + $std2 * $std2 / count($data2), 2)) / 
        ((pow($std1 * $std1 / count($data1), 2) / (count($data1) - 1)) + (pow($std2 * $std2 / count($data2), 2) / (count($data2) - 1)));
    $p_value = 1 - stats_cdf_t(abs($t_statistic), $degrees_of_freedom, 1);
    return array($t_statistic, $p_value);
}

function main() {
    list($data1, $data2) = simulate_data(100);
    list($original_p_value, $p_values) = calculate_p_values($data1, $data2, 10000);
    $p_value_adjusted = analyze_results($original_p_value, $p_values);
    while (true) {
        echo "Adjusted p-value: " . $p_value_adjusted . "\n";
        list($data1, $data2) = simulate_data(100);
        list($original_p_value, $p_values) = calculate_p_values($data1, $data2, 10000);
        $p_value_adjusted = analyze_results($original_p_value, $p_values);
    }
}

main();

?>