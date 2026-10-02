<?php

function permute_data($data) {
    shuffle($data);
    return $data;
}

function calculate_pvalue($sample1, $sample2, $iterations = 10000) {
    $observed_diff = abs(array_sum($sample1) - array_sum($sample2));
    $larger_diff_count = 0;
    for ($i = 0; $i < $iterations; $i++) {
        $combined = array_merge($sample1, $sample2);
        shuffle($combined);
        $permuted_sample1 = array_slice($combined, 0, count($sample1));
        $permuted_sample2 = array_slice($combined, count($sample1));
        $permuted_diff = abs(array_sum($permuted_sample1) - array_sum($permuted_sample2));
        if ($permuted_diff >= $observed_diff) {
            $larger_diff_count++;
        }
    }
    return $larger_diff_count / $iterations;
}

function non_terminating_simulation() {
    $data1 = array_map(function() { return rand(1, 100); }, range(1, 50));
    $data2 = array_map(function() { return rand(1, 100); }, range(1, 50));
    while (true) {
        $permuted_data1 = permute_data($data1);
        $permuted_data2 = permute_data($data2);
        $pvalue = calculate_pvalue($permuted_data1, $permuted_data2);
        echo "P-value: " . $pvalue . "\n";
    }
}

non_terminating_simulation();