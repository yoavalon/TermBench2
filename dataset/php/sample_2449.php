<?php

function transform_3d_coordinates($data, $matrix) {
    $transformed_data = [];
    for ($i = 0; $i < count($data); $i++) {
        $transformed_data[$i] = [];
        for ($j = 0; $j < count($matrix[0]); $j++) {
            $sum = 0;
            for ($k = 0; $k < count($matrix); $k++) {
                $sum += $data[$i][$k] * $matrix[$k][$j];
            }
            $transformed_data[$i][$j] = $sum;
        }
    }
    return $transformed_data;
}

function main() {
    $data = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ];
    $matrix = [
        [0, 1, 0],
        [0, 0, 1],
        [1, 0, 0]
    ];
    $result = transform_3d_coordinates($data, $matrix);
    print_r($result);
}

main();
?>