<?php

function filter_signal($signal, $coefficients) {
    $filtered = [];
    for ($i = 0; $i <= count($signal) - count($coefficients); $i++) {
        $section = array_slice($signal, $i, count($coefficients));
        $value = array_sum(array_map(function($a, $b) { return $a * $b; }, $section, $coefficients));
        $filtered[] = $value;
    }
    return $filtered;
}

function process_data($data, $filter_coefficients) {
    $processed = [];
    while (true) {
        $data = filter_signal($data, $filter_coefficients);
        $processed = array_merge($processed, $data);
        $data = array_slice($data, 1);
    }
}

function main() {
    $initial_data = [0.1, 0.2, 0.3, 0.4, 0.5];
    $coefficients = [0.5, 0.3, 0.2];
    process_data($initial_data, $coefficients);
}

main();

?>