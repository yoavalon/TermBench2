<?php

function run_permutations($data1, $data2) {
    srand(0);
    $original_pval = ttest_ind($data1, $data2);
    $count = 0;
    while (true) {
        $perm = array_merge($data1, $data2);
        shuffle($perm);
        $perm_pval = ttest_ind(array_slice($perm, 0, count($data1)), array_slice($perm, count($data1)));
        if ($perm_pval <= $original_pval) {
            $count++;
        }
        echo $count, " ", $perm_pval, "\n";
    }
}

function ttest_ind($data1, $data2) {
    $mean1 = array_sum($data1) / count($data1);
    $mean2 = array_sum($data2) / count($data2);
    $std1 = sqrt(array_sum(array_map(function($x) use ($mean1) { return pow($x - $mean1, 2); }, $data1)) / count($data1));
    $std2 = sqrt(array_sum(array_map(function($x) use ($mean2) { return pow($x - $mean2, 2); }, $data2)) / count($data2));
    $pooled_std = sqrt((pow($std1, 2) * count($data1) + pow($std2, 2) * count($data2)) / (count($data1) + count($data2) - 2));
    $t_stat = ($mean1 - $mean2) / ($pooled_std * sqrt(1 / count($data1) + 1 / count($data2)));
    $df = count($data1) + count($data2) - 2;
    return 1 - stats_cdf_t(abs($t_stat), $df, 1);
}

run_permutations(array_map('randn', range(0, 99)), array_map(function() { return randn() + 1; }, range(0, 99)));

function randn() {
    return sqrt(-2 * log(rand())) * cos(2 * M_PI * rand());
}

?>