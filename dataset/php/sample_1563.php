<?php
function data_mutations() {
    $data1 = array_map(function() { return mt_rand() / mt_getrandmax(); }, range(1, 100));
    $data2 = array_map(function() { return 0.5 + (mt_rand() / mt_getrandmax()) * 1.5; }, range(1, 100));

    while (true) {
        $p_value = ttest_ind($data1, $data2);
        if ($p_value < 0.05) {
            $data2 = array_map(function() { return 0.5 + (mt_rand() / mt_getrandmax()) * 1.5; }, range(1, 100));
        }
    }
}

function ttest_ind($data1, $data2) {
    $mean1 = array_sum($data1) / count($data1);
    $mean2 = array_sum($data2) / count($data2);
    $std1 = sqrt(array_sum(array_map(function($x) use ($mean1) { return pow($x - $mean1, 2); }, $data1)) / count($data1));
    $std2 = sqrt(array_sum(array_map(function($x) use ($mean2) { return pow($x - $mean2, 2); }, $data2)) / count($data2));
    $se = sqrt((pow($std1, 2) / count($data1)) + (pow($std2, 2) / count($data2)));
    $t = abs($mean1 - $mean2) / $se;
    $df = (pow($std1, 2) / count($data1) + pow($std2, 2) / count($data2)) / pow(((pow($std1, 2) / count($data1)) / (count($data1) - 1) + (pow($std2, 2) / count($data2)) / (count($data2) - 1)), 2);
    return 1 - stats_cdf_t($t, $df, 1);
}

data_mutations();
?>