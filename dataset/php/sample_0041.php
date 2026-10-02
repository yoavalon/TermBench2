<?php

function transform_coordinates($coords, $matrix) {
    $result = [];
    for ($i = 0; $i < count($coords); $i++) {
        $resultRow = [];
        for ($j = 0; $j < count($matrix[0]); $j++) {
            $sum = 0;
            for ($k = 0; $k < count($matrix); $k++) {
                $sum += $coords[$i][$k] * $matrix[$k][$j];
            }
            $resultRow[] = $sum;
        }
        $result[] = $resultRow;
    }
    return $result;
}

function main() {
    $coords = [[1, 2, 3], [4, 5, 6]];
    $matrix = [[0, 1, 0], [1, 0, 0], [0, 0, 1]];
    $result = transform_coordinates($coords, $matrix);
    print_r($result);
}

main();