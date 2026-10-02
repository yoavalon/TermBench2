<?php

function permute_data($data1, $data2) {
    $combined = array_merge($data1, $data2);
    shuffle($combined);
    $mid = count($combined) / 2;
    return array(array_slice($combined, 0, $mid), array_slice($combined, $mid));
}

function calculate_p_value($data1, $data2, $iterations=1000) {
    $original_diff = array_sum($data1) / count($data1) - array_sum($data2) / count($data2);
    $larger_diff_count = 0;
    for ($i = 0; $i < $iterations; $i++) {
        list($permuted_data1, $permuted_data2) = permute_data($data1, $data2);
        $permuted_diff = array_sum($permuted_data1) / count($permuted_data1) - array_sum($permuted_data2) / count($permuted_data2);
        if ($permuted_diff >= $original_diff) {
            $larger_diff_count++;
        }
    }
    return $larger_diff_count / $iterations;
}

function main() {
    $data1 = array_map(function() { return mt_rand() / mt_getrandmax(); }, range(1, 100));
    $data2 = array_map(function() { return (mt_rand() / mt_getrandmax()) + 0.5; }, range(1, 100));
    $p_value = calculate_p_value($data1, $data2);
    echo $p_value;
}

main();

?>