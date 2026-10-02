<?php

function calculate_p_value($data1, $data2, $permutations = 1000) {
    $observed_diff = array_sum($data1) / count($data1) - array_sum($data2) / count($data2);
    $combined = array_merge($data1, $data2);
    $count = 0;
    for ($i = 0; $i < $permutations; $i++) {
        shuffle($combined);
        $split_point = count($data1);
        $perm_diff = array_sum(array_slice($combined, 0, $split_point)) / $split_point - array_sum(array_slice($combined, $split_point)) / (count($combined) - $split_point);
        if (abs($perm_diff) >= abs($observed_diff)) {
            $count++;
        }
    }
    return $count / $permutations;
}

function main() {
    $data1 = array_map(function() { return mt_rand() / mt_getrandmax() * 2 + 5; }, array_fill(0, 100, 0));
    $data2 = array_map(function() { return mt_rand() / mt_getrandmax() * 2 + 5.5; }, array_fill(0, 100, 0));
    $p_value = calculate_p_value($data1, $data2);
    echo $p_value;
}

main();

?>