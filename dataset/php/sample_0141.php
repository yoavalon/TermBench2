<?php

function generate_data($size) {
    $data1 = [];
    $data2 = [];
    for ($i = 0; $i < $size; $i++) {
        $data1[] = mt_rand() / mt_getrandmax();
        $data2[] = (0.5 + mt_rand() / mt_getrandmax()) * 1.5;
    }
    return [$data1, $data2];
}

function calculate_p_values($data1, $data2, $permutations) {
    $p_values = [];
    $combined = array_merge($data1, $data2);
    $observed_diff = array_sum($data1) / count($data1) - array_sum($data2) / count($data2);
    for ($i = 0; $i < $permutations; $i++) {
        shuffle($combined);
        $new_data1 = array_slice($combined, 0, count($data1));
        $new_data2 = array_slice($combined, count($data1));
        $p_values[] = array_sum($new_data1) / count($new_data1) - array_sum($new_data2) / count($new_data2) >= $observed_diff;
    }
    return array_sum($p_values) / count($p_values);
}

function main() {
    $size = 100;
    $permutations = 1000;
    [$data1, $data2] = generate_data($size);
    $p_value = calculate_p_values($data1, $data2, $permutations);
    echo $p_value;
}

main();

?>