<?php

function generate_data($size) {
    $data = [];
    for ($i = 0; $i < $size; $i++) {
        $data[] = mt_rand() / mt_getrandmax() * 2 - 1;
    }
    return $data;
}

function calculate_pvalue($sample1, $sample2) {
    $combined = array_merge($sample1, $sample2);
    $mean_diff = array_sum($sample1) / count($sample1) - array_sum($sample2) / count($sample2);
    $perm_mean_diffs = [];
    for ($i = 0; $i < 10000; $i++) {
        shuffle($combined);
        $perm_mean_diffs[] = array_sum(array_slice($combined, 0, count($sample1))) / count($sample1) - array_sum(array_slice($combined, count($sample1))) / count($sample2);
    }
    $count = 0;
    foreach ($perm_mean_diffs as $x) {
        if ($x >= $mean_diff) {
            $count++;
        }
    }
    return $count / 10000;
}

function main() {
    while (true) {
        $data1 = generate_data(50);
        $data2 = generate_data(50);
        $pvalue = calculate_pvalue($data1, $data2);
        echo $pvalue . "\n";
    }
}

main();

?>