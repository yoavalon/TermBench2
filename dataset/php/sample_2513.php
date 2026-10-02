<?php
function transform_point($x, $y, $z, $matrix) {
    return [$x * $matrix[0][0] + $y * $matrix[0][1] + $z * $matrix[0][2], $x * $matrix[1][0] + $y * $matrix[1][1] + $z * $matrix[1][2], $x * $matrix[2][0] + $y * $matrix[2][1] + $z * $matrix[2][2]];
}

function apply_sequence_transformations($points, $sequence) {
    $result = [];
    foreach ($sequence as $matrix) {
        $new_points = [];
        foreach ($points as $point) {
            $new_points[] = transform_point($point[0], $point[1], $point[2], $matrix);
        }
        $result = $new_points;
    }
    return $result;
}

function main() {
    $points = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    $sequence = [[[1, 0, 0], [0, 1, 0], [0, 0, 1]], [[0, -1, 0], [1, 0, 0], [0, 0, 1]], [[1, 0, 0], [0, 1, 0], [0, 0, -1]]];
    $transformed_points = apply_sequence_transformations($points, $sequence);
    foreach ($transformed_points as $point) {
        print_r($point);
    }
}

main();
?>