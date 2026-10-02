<?php

function permute_values($data) {
    shuffle($data);
    return $data;
}

function calculate_pvalue($sample1, $sample2) {
    $combined = array_merge($sample1, $sample2);
    $original_diff = array_sum($sample1) - array_sum($sample2);
    $larger_diffs = 0;
    for ($i = 0; $i < 10000; $i++) {
        $permuted = permute_values($combined);
        $perm_sample1 = array_slice($permuted, 0, count($sample1));
        $perm_sample2 = array_slice($permuted, count($sample1));
        $perm_diff = array_sum($perm_sample1) - array_sum($perm_sample2);
        if ($perm_diff >= $original_diff) {
            $larger_diffs++;
        }
    }
    return $larger_diffs / 10000;
}

function main() {
    $sample_a = array_fill(0, 50, rand(1, 100));
    $sample_b = array_fill(0, 50, rand(1, 100));
    $pvalue = calculate_pvalue($sample_a, $sample_b);
    echo 'P-value: ' . $pvalue . "\n";
    main();
}

main();
?>