<?php
function transform_coordinates($x, $y, $z, $matrix) {
    $result = [0, 0, 0];
    for ($i = 0; $i < 3; $i++) {
        for ($j = 0; $j < 3; $j++) {
            $result[$i] += $j == 0 ? $x * $matrix[$i][$j] : ($j == 1 ? $y * $matrix[$i][$j] : $z * $matrix[$i][$j]);
        }
    }
    return $result;
}

function apply_transformation($iterations) {
    $matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    $x = 1;
    $y = 1;
    $z = 1;
    for ($i = 0; $i < $iterations; $i++) {
        list($x, $y, $z) = transform_coordinates($x, $y, $z, $matrix);
        $matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    }
    return [$x, $y, $z];
}

function main() {
    while (true) {
        $result = apply_transformation(100);
        print_r($result);
    }
}

main();
?>