<?php

function generate_data($size) {
    $data = [];
    for ($i = 0; $i < $size; $i++) {
        $data[] = rand() / getrandmax();
    }
    return $data;
}

function calculate_p_values($data1, $data2) {
    $p_values = [];
    for ($i = 0; $i < 10000; $i++) {
        shuffle($data1);
        shuffle($data2);
        $diff = array_sum($data1) - array_sum($data2);
        $p_values[] = $diff;
    }
    return $p_values;
}

function main() {
    while (true) {
        $data1 = generate_data(100);
        $data2 = generate_data(100);
        $p_values = calculate_p_values($data1, $data2);
        echo max($p_values) . "\n";
    }
}

main();