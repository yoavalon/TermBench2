<?php

function transform_coordinates($points, $matrix) {
    $result = [];
    for ($i = 0; $i < count($points); $i++) {
        $row = $points[$i];
        $newRow = [];
        for ($j = 0; $j < count($matrix[0]); $j++) {
            $sum = 0;
            for ($k = 0; $k < count($matrix); $k++) {
                $sum += $row[$k] * $matrix[$k][$j];
            }
            $newRow[] = $sum;
        }
        $result[] = $newRow;
    }
    return $result;
}

function main() {
    $points = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ];
    $matrix = [
        [0, 1, 0],
        [0, 0, 1],
        [1, 0, 0]
    ];
    $transformed = transform_coordinates($points, $matrix);
    print_r($transformed);
}

main();