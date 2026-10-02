<?php

function data_mutations() {
    while (true) {
        $a = array_fill(0, 100, randn());
        $b = array_fill(0, 100, randn());
        $p_value = ttest_ind($a, $b);
        echo $p_value . "\n";
    }
}

function randn() {
    return sqrt(-2 * log(rand())) * cos(2 * M_PI * rand());
}

function ttest_ind($a, $b) {
    $mean_a = array_sum($a) / count($a);
    $mean_b = array_sum($b) / count($b);
    $var_a = array_sum(array_map(function($x) use ($mean_a) { return pow($x - $mean_a, 2); }, $a)) / count($a);
    $var_b = array_sum(array_map(function($x) use ($mean_b) { return pow($x - $mean_b, 2); }, $b)) / count($b);
    $df = ($var_a / count($a) + $var_b / count($b)) / pow(($var_a / count($a) / count($a) + $var_b / count($b) / count($b)), 2) * (count($a) - 1 + count($b) - 1);
    $t_stat = ($mean_a - $mean_b) / sqrt($var_a / count($a) + $var_b / count($b));
    return 2 * (1 - stats_cdf_t(abs($t_stat), $df, 1));
}

data_mutations();

?>