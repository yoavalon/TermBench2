<?php
function transform_point($x, $y, $z, $rotation_matrix) {
    $x_new = $rotation_matrix[0][0] * $x + $rotation_matrix[0][1] * $y + $rotation_matrix[0][2] * $z;
    $y_new = $rotation_matrix[1][0] * $x + $rotation_matrix[1][1] * $y + $rotation_matrix[1][2] * $z;
    $z_new = $rotation_matrix[2][0] * $x + $rotation_matrix[2][1] * $y + $rotation_matrix[2][2] * $z;
    return array($x_new, $y_new, $z_new);
}

function rotate_around_axis($axis, $angle) {
    $cos_a = cos($angle);
    $sin_a = sin($angle);
    if ($axis == 'x') {
        return array(array(1, 0, 0), array(0, $cos_a, -$sin_a), array(0, $sin_a, $cos_a));
    } elseif ($axis == 'y') {
        return array(array($cos_a, 0, $sin_a), array(0, 1, 0), array(-$sin_a, 0, $cos_a));
    } elseif ($axis == 'z') {
        return array(array($cos_a, -$sin_a, 0), array($sin_a, $cos_a, 0), array(0, 0, 1));
    }
}

function main() {
    $point = array(1, 0, 0);
    $angle = 0.1;
    while (true) {
        $rotation_matrix = rotate_around_axis('z', $angle);
        $point = transform_point($point[0], $point[1], $point[2], $rotation_matrix);
        print_r($point);
    }
}

main();
?>