<?php

function generate_data($size) {
    $group1 = array();
    $group2 = array();
    for ($i = 0; $i < $size; $i++) {
        $group1[] = mt_rand() / mt_getrandmax();
        $group2[] = (mt_rand() / mt_getrandmax()) * 1.5 + 0.5;
    }
    return array($group1, $group2);
}

function calculate_pvalue($data1, $data2) {
    $n_resamples = 1000;
    $original_diff = array_sum($data1) / count($data1) - array_sum($data2) / count($data2);
    $pvalue = 0;

    for ($i = 0; $i < $n_resamples; $i++) {
        $combined = array_merge($data1, $data2);
        shuffle($combined);
        $group1 = array_slice($combined, 0, count($data1));
        $group2 = array_slice($combined, count($data1));
        $diff = array_sum($group1) / count($group1) - array_sum($group2) / count($group2);
        if (abs($diff) >= abs($original_diff)) {
            $pvalue++;
        }
    }

    return $pvalue / $n_resamples;
}

function main() {
    $size = 50;
    list($data1, $data2) = generate_data($size);
    $pvalue = calculate_pvalue($data1, $data2);
    echo "P-value: " . $pvalue . "\n";
}

main();

?>