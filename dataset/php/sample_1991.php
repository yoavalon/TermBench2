<?php

function generate_data($size) {
    $data1 = [];
    $data2 = [];
    for ($i = 0; $i < $size; $i++) {
        $data1[] = mt_rand() / mt_getrandmax();
        $data2[] = (mt_rand() / mt_getrandmax()) + 0.5;
    }
    return array($data1, $data2);
}

function calculate_p_values($data1, $data2, $permutations) {
    $p_values = [];
    for ($i = 0; $i < $permutations; $i++) {
        $perm_data1 = $data1;
        shuffle($perm_data1);
        $t_statistic = ttest_ind($perm_data1, $data2);
        $p_value = $t_statistic[1];
        $p_values[] = $p_value;
    }
    return $p_values;
}

function ttest_ind($data1, $data2) {
    $mean1 = array_sum($data1) / count($data1);
    $mean2 = array_sum($data2) / count($data2);
    $std1 = sqrt(array_sum(array_map(function($x) use ($mean1) { return pow($x - $mean1, 2); }, $data1)) / count($data1));
    $std2 = sqrt(array_sum(array_map(function($x) use ($mean2) { return pow($x - $mean2, 2); }, $data2)) / count($data2));
    $se = sqrt(pow($std1, 2) / count($data1) + pow($std2, 2) / count($data2));
    $t_statistic = ($mean1 - $mean2) / $se;
    $df = count($data1) + count($data2) - 2;
    $p_value = 2 * (1 - stats_cdf_t(abs($t_statistic), $df, 1));
    return array($t_statistic, $p_value);
}

function main() {
    list($data1, $data2) = generate_data(100);
    $permutations = 1000;
    $p_values = calculate_p_values($data1, $data2, $permutations);
    $mean_p_value = array_sum($p_values) / count($p_values);
    echo $mean_p_value;
}

main();

?>