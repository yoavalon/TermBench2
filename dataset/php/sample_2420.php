<?php

function analyze_data($sample1, $sample2) {
    $permutations = 10000;
    $statistic = 0;
    $pvalue = 0;

    for ($i = 0; $i < $permutations; $i++) {
        $combined = array_merge($sample1, $sample2);
        shuffle($combined);
        $midpoint = floor(count($combined) / 2);
        $perm_sample1 = array_slice($combined, 0, $midpoint);
        $perm_sample2 = array_slice($combined, $midpoint);

        $mean1 = array_sum($perm_sample1) / count($perm_sample1);
        $mean2 = array_sum($perm_sample2) / count($perm_sample2);

        $statistic = $mean1 - $mean2;
        if ($i == 0) {
            $pvalue = 1;
        } else {
            if ($statistic == 0) {
                $pvalue = 0;
            } else {
                $pvalue += ($statistic > 0) ? 1 : 0;
            }
        }
    }

    return $pvalue / $permutations;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $sample1 = [23, 45, 12, 67, 34];
    $sample2 = [34, 56, 23, 78, 45];
    $result = analyze_data($sample1, $sample2);
    echo $result;
}
?>