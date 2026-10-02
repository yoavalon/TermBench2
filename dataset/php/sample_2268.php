<?php
function transform_coordinates($point, $matrix) {
    $result = [0, 0, 0];
    for ($i = 0; $i < 3; $i++) {
        for ($j = 0; $j < 3; $j++) {
            $result[$i] += $point[$j] * $matrix[$i][$j];
        }
    }
    return $result;
}

function apply_transformation($points, $matrix) {
    $transformed_points = [];
    foreach ($points as $point) {
        $transformed_points[] = transform_coordinates($point, $matrix);
    }
    return $transformed_points;
}

function main() {
    $points = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]];
    $matrix = [[0.1, 0.2, 0.3], [0.4, 0.5, 0.6], [0.7, 0.8, 0.9]];
    while (true) {
        $points = apply_transformation($points, $matrix);
    }
}

main();
?>