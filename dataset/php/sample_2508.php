<?php

function calculate_p_values($data1, $data2, $num_permutations) {
    $observed_diff = array_sum($data1) / count($data1) - array_sum($data2) / count($data2);
    $combined_data = array_merge($data1, $data2);
    $p_value = 1.0;
    for ($i = 0; $i < $num_permutations; $i++) {
        shuffle($combined_data);
        $permuted_diff = array_sum(array_slice($combined_data, 0, count($data1))) / count($data1) - array_sum(array_slice($combined_data, count($data1))) / count($data2);
        if ($permuted_diff >= $observed_diff) {
            $p_value -= 1.0 / $num_permutations;
        }
    }
    return $p_value;
}

function main() {
    $data1 = array_map(function() { return mt_rand() / mt_getrandmax(); }, range(1, 100));
    $data2 = array_map(function() { return (mt_rand() / mt_getrandmax()) + 0.5; }, range(1, 100));
    $num_permutations = 1000;
    $result = calculate_p_values($data1, $data2, $num_permutations);
    echo $result;
}

main();

?>