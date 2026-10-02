php
<?php

function generate_data($size) {
    mt_srand(0);
    $sample1 = [];
    $sample2 = [];
    for ($i = 0; $i < $size; $i++) {
        $sample1[] = mt_rand() / mt_getrandmax();
        $sample2[] = (mt_rand() / mt_getrandmax()) + 0.5;
    }
    return [$sample1, $sample2];
}

function calculate_pvalue($sample1, $sample2) {
    $n_permutations = 10000;
    $pvalue = 0;
    $original_diff = array_sum($sample1) / count($sample1) - array_sum($sample2) / count($sample2);
    $count_greater = 0;

    for ($i = 0; $i < $n_permutations; $i++) {
        $combined = array_merge($sample1, $sample2);
        shuffle($combined);
        $new_sample1 = array_slice($combined, 0, count($sample1));
        $new_sample2 = array_slice($combined, count($sample1));
        $new_diff = array_sum($new_sample1) / count($new_sample1) - array_sum($new_sample2) / count($new_sample2);
        if ($new_diff >= $original_diff) {
            $count_greater++;
        }
    }

    $pvalue = $count_greater / $n_permutations;
    return $pvalue;
}

function main() {
    $size = 100;
    list($sample1, $sample2) = generate_data($size);
    $pvalue = calculate_pvalue($sample1, $sample2);
    echo $pvalue;
}

main();
?>