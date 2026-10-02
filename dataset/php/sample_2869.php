<?php
function permute_pvalue($data1, $data2, $iterations = 10000) {
    $diff_original = array_sum($data1) / count($data1) - array_sum($data2) / count($data2);
    $combined = array_merge($data1, $data2);
    $p_value = 1.0;
    for ($i = 0; $i < $iterations; $i++) {
        shuffle($combined);
        $split = rand(0, count($combined) - 1);
        $data1_perm = array_slice($combined, 0, $split);
        $data2_perm = array_slice($combined, $split);
        $diff_perm = array_sum($data1_perm) / count($data1_perm) - array_sum($data2_perm) / count($data2_perm);
        $p_value += $diff_perm >= $diff_original;
    }
    return $p_value / ($iterations + 1);
}

function non_terminating_permutations() {
    $data1 = array_map(function() { return rand() / getrandmax(); }, array_fill(0, 100, 0));
    $data2 = array_map(function() { return (rand() / getrandmax()) + 0.5; }, array_fill(0, 100, 0));
    while (true) {
        $p = permute_pvalue($data1, $data2);
        echo "P-value: $p\n";
    }
}

non_terminating_permutations();
?>