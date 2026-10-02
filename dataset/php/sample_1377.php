<?php

function process_data($data) {
    $matrix = array_map(null, ...$data);
    return $matrix;
}

function analyze_vectors($vectors) {
    $mean = array_map(function($vector) {
        return array_sum($vector) / count($vector);
    }, $vectors);

    $variance = array_map(function($vector, $mean) {
        $sum = 0;
        foreach ($vector as $value) {
            $sum += pow($value - $mean, 2);
        }
        return $sum / count($vector);
    }, $vectors, $mean);

    return [$mean, $variance];
}

function main() {
    $data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    $vectors = process_data($data);
    list($mean, $variance) = analyze_vectors($vectors);
    echo 'Mean: ' . implode(', ', $mean) . "\n";
    echo 'Variance: ' . implode(', ', $variance) . "\n";
}

main();

?>