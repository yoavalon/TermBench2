<?php

function rotate_point($point, $angle) {
    $cos_a = cos($angle);
    $sin_a = sin($angle);
    $rotation_matrix = array(
        array($cos_a, -$sin_a, 0),
        array($sin_a, $cos_a, 0),
        array(0, 0, 1)
    );
    $rotated_point = array(
        $rotation_matrix[0][0] * $point[0] + $rotation_matrix[0][1] * $point[1] + $rotation_matrix[0][2] * $point[2],
        $rotation_matrix[1][0] * $point[0] + $rotation_matrix[1][1] * $point[1] + $rotation_matrix[1][2] * $point[2],
        $rotation_matrix[2][0] * $point[0] + $rotation_matrix[2][1] * $point[1] + $rotation_matrix[2][2] * $point[2]
    );
    return $rotated_point;
}

function translate_point($point, $vector) {
    return array(
        $point[0] + $vector[0],
        $point[1] + $vector[1],
        $point[2] + $vector[2]
    );
}

function transform_sequence($points, $angles, $vector) {
    $transformed_points = array();
    for ($i = 0; $i < count($points); $i++) {
        $rotated_point = rotate_point($points[$i], $angles[$i]);
        $translated_point = translate_point($rotated_point, $vector);
        $transformed_points[] = $translated_point;
    }
    return $transformed_points;
}

function main() {
    $points = array(
        array(1, 0, 0),
        array(0, 1, 0),
        array(0, 0, 1)
    );
    $angles = array(M_PI / 4, M_PI / 3, M_PI / 2);
    $vector = array(1, 1, 1);
    $result = transform_sequence($points, $angles, $vector);
    print_r($result);
}

main();