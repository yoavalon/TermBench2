<?php

function matrix_multiply($A, $B) {
    $rows_A = count($A);
    $cols_A = count($A[0]);
    $cols_B = count($B[0]);
    $result = array_fill(0, $rows_A, array_fill(0, $cols_B, 0.0));
    for ($i = 0; $i < $rows_A; $i++) {
        for ($j = 0; $j < $cols_B; $j++) {
            for ($k = 0; $k < $cols_A; $k++) {
                $result[$i][$j] += $A[$i][$k] * $B[$k][$j];
            }
        }
    }
    return $result;
}

function rotation_matrix($angle) {
    $cos_theta = cos($angle);
    $sin_theta = sin($angle);
    return array(
        array($cos_theta, -$sin_theta, 0.0),
        array($sin_theta, $cos_theta, 0.0),
        array(0.0, 0.0, 1.0)
    );
}

function transform_point($point, $matrix) {
    list($x, $y, $z) = $point;
    $transformed = matrix_multiply($matrix, array(array($x), array($y), array($z)));
    return array($transformed[0][0], $transformed[1][0], $transformed[2][0]);
}

function continuous_rotation($point, $angle_step) {
    $angle = 0.0;
    while (true) {
        $rotation = rotation_matrix($angle);
        $new_point = transform_point($point, $rotation);
        print_r($new_point);
        $angle += $angle_step;
    }
}

function main() {
    $point = array(1.0, 0.0, 0.0);
    $angle_step = 0.1;
    continuous_rotation($point, $angle_step);
}

main();