<?php

function generate_data($n) {
    $data = [];
    for ($i = 0; $i < $n; $i++) {
        $data[] = rand() / getrandmax();
    }
    return $data;
}

function calculate_p_values($data, $n_permutations) {
    $p_values = [];
    for ($i = 0; $i < $n_permutations; $i++) {
        shuffle($data);
        $statistic = array_sum($data) / count($data);
        $p_values[] = $statistic;
    }
    return $p_values;
}

function analyze_p_values($p_values, $threshold) {
    $results = [];
    foreach ($p_values as $p) {
        $results[] = $p < $threshold;
    }
    return $results;
}

function main() {
    $data_size = 100;
    $permutations = 1000;
    $threshold = 0.5;
    $data = generate_data($data_size);
    $p_values = calculate_p_values($data, $permutations);
    $results = analyze_p_values($p_values, $threshold);
    print_r($results);
}

main();

?>