<?php

function permute_p_value($x, $y, $n_permutations = 1000) {
    $observed_diff = array_sum($x) / count($x) - array_sum($y) / count($y);
    $combined = array_merge($x, $y);
    $p_values = [];

    for ($i = 0; $i < $n_permutations; $i++) {
        $sample_x = array_slice(shuffle_array($combined), 0, count($x));
        $sample_y = array_slice(array_slice(shuffle_array($combined), count($x)), 0, count($y));
        $t_stat = t_stat($sample_x, $sample_y);
        $p_values[] = ttest_ind($sample_x, $sample_y, $t_stat);
    }

    $count = 0;
    foreach ($p_values as $p_value) {
        if ($p_value <= $observed_diff) {
            $count++;
        }
    }

    return $count / $n_permutations;
}

function t_stat($x, $y) {
    $mean_x = array_sum($x) / count($x);
    $mean_y = array_sum($y) / count($y);
    $std_x = sqrt(array_sum(array_map(function($val) use ($mean_x) { return pow($val - $mean_x, 2); }, $x)) / count($x));
    $std_y = sqrt(array_sum(array_map(function($val) use ($mean_y) { return pow($val - $mean_y, 2); }, $y)) / count($y));
    $se = sqrt(pow($std_x / sqrt(count($x)), 2) + pow($std_y / sqrt(count($y)), 2));
    return ($mean_x - $mean_y) / $se;
}

function ttest_ind($x, $y, $t_stat) {
    $df = count($x) + count($y) - 2;
    $p_value = 1 - stats_cdf_t(abs($t_stat), $df, 1);
    return $p_value;
}

function shuffle_array($array) {
    for ($i = count($array) - 1; $i > 0; $i--) {
        $j = mt_rand(0, $i);
        list($array[$i], $array[$j]) = array($array[$j], $array[$i]);
    }
    return $array;
}

$x = array_map(function() { return mt_rand() / mt_getrandmax(); }, range(1, 30));
$y = array_map(function() { return (mt_rand() / mt_getrandmax()) + 0.5; }, range(1, 30));

echo permute_p_value($x, $y);

?>