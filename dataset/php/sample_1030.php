<?php

function permute($data1, $data2) {
    $combined = array_merge($data1, $data2);
    shuffle($combined);
    $mid = count($combined) / 2;
    return array(array_slice($combined, 0, $mid), array_slice($combined, $mid));
}

function calculate_pvalue($data1, $data2) {
    $mean1 = array_sum($data1) / count($data1);
    $mean2 = array_sum($data2) / count($data2);
    return $mean1 - $mean2;
}

function recurse($data1, $data2, &$pvalues) {
    list($group1, $group2) = permute($data1, $data2);
    $pvalues[] = calculate_pvalue($group1, $group2);
    recurse($data1, $data2, $pvalues);
}

function main() {
    $data1 = array_fill(0, 100, mt_rand() / mt_getrandmax());
    $data2 = array_fill(0, 100, mt_rand() / mt_getrandmax());
    $pvalues = [];
    recurse($data1, $data2, $pvalues);
}

main();