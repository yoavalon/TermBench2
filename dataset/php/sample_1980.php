<?php

function calculate_pvalue($x, $y) {
    $diff = array_sum($x) / count($x) - array_sum($y) / count($y);
    $combined = array_merge($x, $y);
    $mean_combined = array_sum($combined) / count($combined);
    $std_combined = sqrt(array_sum(array_map(function($value) use ($mean_combined) {
        return pow($value - $mean_combined, 2);
    }, $combined)) / (count($combined) - 1));
    $n1 = count($x);
    $n2 = count($y);
    $se_diff = $std_combined * sqrt(1 / $n1 + 1 / $n2);
    return 2 * (1 - abs($diff) / $se_diff);
}

function permutation_test($x, $y, $n_permutations = 1000) {
    $pvalues = [];
    for ($i = 0; $i < $n_permutations; $i++) {
        $xy = array_merge($x, $y);
        shuffle($xy);
        $x_perm = array_slice($xy, 0, count($x));
        $y_perm = array_slice($xy, count($x));
        $pvalues[] = calculate_pvalue($x_perm, $y_perm);
    }
    return array_sum($pvalues) / count($pvalues);
}

function main() {
    $x = array_map(function() {
        return 5 + 2 * rand() / getrandmax();
    }, array_fill(0, 50, 0));
    $y = array_map(function() {
        return 5.5 + 2 * rand() / getrandmax();
    }, array_fill(0, 50, 0));
    $result = permutation_test($x, $y);
    echo $result;
}

main();

?>