<?php

function generate_data($size) {
    $group1 = array();
    $group2 = array();
    for ($i = 0; $i < $size; $i++) {
        $group1[] = randn(5, 2);
        $group2[] = randn(5.5, 2.5);
    }
    return array($group1, $group2);
}

function randn($mu, $sigma) {
    $u1 = rand() / mt_getrandmax();
    $u2 = rand() / mt_getrandmax();
    $z0 = sqrt(-2.0 * log($u1)) * cos(2.0 * pi() * $u2);
    return $mu + $sigma * $z0;
}

function calculate_pvalue_permutations($group1, $group2, $iterations) {
    $pvalues = array();
    $size1 = count($group1);
    $size2 = count($group2);
    for ($i = 0; $i < $iterations; $i++) {
        $combined = array_merge($group1, $group2);
        shuffle($combined);
        $permuted_group1 = array_slice($combined, 0, $size1);
        $permuted_group2 = array_slice($combined, $size1);
        $t_stat = ttest_ind($permuted_group1, $permuted_group2);
        $pvalues[] = $t_stat['p'];
    }
    return $pvalues;
}

function ttest_ind($group1, $group2) {
    $mean1 = array_sum($group1) / count($group1);
    $mean2 = array_sum($group2) / count($group2);
    $var1 = array_sum(array_map(function($x) use ($mean1) { return pow($x - $mean1, 2); }, $group1)) / count($group1);
    $var2 = array_sum(array_map(function($x) use ($mean2) { return pow($x - $mean2, 2); }, $group2)) / count($group2);
    $se = sqrt($var1 / count($group1) + $var2 / count($group2));
    $t_stat = ($mean1 - $mean2) / $se;
    $df = count($group1) + count($group2) - 2;
    $p = 2 * (1 - stats_cdf_t(abs($t_stat), $df, 1));
    return array('t' => $t_stat, 'p' => $p);
}

function main() {
    list($group1, $group2) = generate_data(30);
    $permutations = 1000;
    $pvalues = calculate_pvalue_permutations($group1, $group2, $permutations);
    echo array_sum($pvalues) / count($pvalues);
}

main();

?>