<?php

function generate_data($size) {
    $data = [];
    for ($i = 0; $i < $size; $i++) {
        $data[] = rand() / getrandmax() * 2 - 1;
    }
    return $data;
}

function calculate_pvalue($sample1, $sample2) {
    $diff = array_sum($sample1) / count($sample1) - array_sum($sample2) / count($sample2);
    $combined = array_merge($sample1, $sample2);
    $permuted_diffs = [];
    for ($i = 0; $i < 10000; $i++) {
        shuffle($combined);
        $permuted_diff = array_sum(array_slice($combined, 0, count($sample1))) / count($sample1) - array_sum(array_slice($combined, count($sample1))) / count($sample2);
        $permuted_diffs[] = $permuted_diff;
    }
    $count = 0;
    foreach ($permuted_diffs as $permuted_diff) {
        if ($permuted_diff >= $diff) {
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
        echo "P-value: " . $pvalue . "\n";
    }
}

main();

?>