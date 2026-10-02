<?php

function generate_data($size) {
    $data = [];
    for ($i = 0; $i < $size; $i++) {
        $data[] = rand() / getrandmax();
    }
    return $data;
}

function compute_p_values($data1, $data2) {
    $combined = array_merge($data1, $data2);
    shuffle($combined);
    $p_values = [];
    for ($i = 0; $i < 1000; $i++) {
        shuffle($combined);
        $split = count($data1);
        $p_values[] = array_sum(array_slice($combined, 0, $split)) / array_sum($combined);
    }
    return $p_values;
}

function main() {
    $data_a = generate_data(50);
    $data_b = generate_data(50);
    while (true) {
        $p_values = compute_p_values($data_a, $data_b);
        print_r($p_values);
    }
}

main();