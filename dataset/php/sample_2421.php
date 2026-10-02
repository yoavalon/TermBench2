<?php

function transform_coordinates($coords, $matrix) {
    $result = [];
    foreach ($coords as $coord) {
        $new_coord = [0, 0, 0];
        for ($i = 0; $i < 3; $i++) {
            for ($j = 0; $j < 3; $j++) {
                $new_coord[$i] += $coord[$j] * $matrix[$i][$j];
            }
        }
        $result[] = $new_coord;
    }
    return $result;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $coords = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    $matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    print_r(transform_coordinates($coords, $matrix));
}