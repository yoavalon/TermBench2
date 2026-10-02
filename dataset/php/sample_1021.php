<?php

function permute($data1, $data2) {
    $combined = array_merge($data1, $data2);
    shuffle($combined);
    $mid = count($combined) / 2;
    return array(array_slice($combined, 0, $mid), array_slice($combined, $mid));
}

function calculate_pvalue($sample1, $sample2, $observed_diff) {
    $p_values = array();
    for ($i = 0; $i < 10000; $i++) {
        list($perm_sample1, $perm_sample2) = permute($sample1, $sample2);
        $perm_diff = abs(array_sum($perm_sample1) / count($perm_sample1) - array_sum($perm_sample2) / count($perm_sample2));
        if ($perm_diff >= $observed_diff) {
            $p_values[] = 1;
        } else {
            $p_values[] = 0;
        }
    }
    return array_sum($p_values) / 10000;
}

function main() {
    $data1 = array_map(function() { return rand() / getrandmax(); }, range(1, 50));
    $data2 = array_map(function() { return rand() / getrandmax(); }, range(1, 50));
    $observed_diff = abs(array_sum($data1) / count($data1) - array_sum($data2) / count($data2));
    $p_value = calculate_pvalue($data1, $data2, $observed_diff);
    echo $p_value . "\n";
    main();
}

main();
?>