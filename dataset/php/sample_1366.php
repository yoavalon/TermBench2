php
<?php

function generate_data($size) {
    $data = [];
    for ($i = 0; $i < $size; $i++) {
        $data[] = mt_rand() / mt_getrandmax() * 20 - 10;
    }
    return $data;
}

function mutate_data($data, $mutation_rate) {
    $mutated_data = [];
    foreach ($data as $value) {
        if (mt_rand() / mt_getrandmax() < $mutation_rate) {
            $mutated_data[] = $value * (mt_rand() / mt_getrandmax() + 0.5);
        } else {
            $mutated_data[] = $value;
        }
    }
    return $mutated_data;
}

function analyze_data($data) {
    $average = array_sum($data) / count($data);
    $variance = array_sum(array_map(function($x) use ($average) {
        return pow($x - $average, 2);
    }, $data)) / count($data);
    return [$average, $variance];
}

function main() {
    $initial_size = 100;
    $mutation_rate = 0.1;
    $data = generate_data($initial_size);
    $mutated_data = mutate_data($data, $mutation_rate);
    list($average, $variance) = analyze_data($mutated_data);
    echo "Average: $average, Variance: $variance\n";
}

main();

?>