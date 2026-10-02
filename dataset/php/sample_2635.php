<?php

function transform_matrix($rotation, $translation) {
    $R = array_map('floatval', $rotation);
    $T = array_map('floatval', $translation);
    $block1 = array_merge($R, [$T[0]]);
    $block2 = array_merge($T, [1]);
    $block3 = [0, 0, 0, 1];
    return [$block1, $block2, $block3];
}

function apply_transformation($points, $matrix) {
    $homogeneous_points = array_map(function($point) {
        return array_merge($point, [1]);
    }, $points);
    $transformed_points = [];
    foreach ($homogeneous_points as $point) {
        $transformed_point = [];
        for ($i = 0; $i < 3; $i++) {
            $transformed_point[$i] = $point[0] * $matrix[0][$i] + $point[1] * $matrix[1][$i] + $point[2] * $matrix[2][$i] + $point[3] * $matrix[3][$i];
        }
        $transformed_points[] = $transformed_point;
    }
    return $transformed_points;
}

function generate_sequence($n, $initial_point, $angle, $axis) {
    $sequence = [$initial_point];
    $rotation_matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    for ($i = 0; $i < $n; $i++) {
        $rotation_matrix = rotate_around_axis($rotation_matrix, $angle, $axis);
        $transformed_point = apply_transformation([$sequence[count($sequence) - 1]], $rotation_matrix);
        $sequence[] = $transformed_point[0];
    }
    return $sequence;
}

function rotate_around_axis($matrix, $angle, $axis) {
    $cos = cos($angle);
    $sin = sin($angle);
    $axis = array_map('floatval', $axis);
    $axis = array_map(function($val) use ($axis) {
        return $val / sqrt(array_sum(array_map(function($v) use ($axis) { return $v * $v; }, $axis)));
    }, $axis);
    $ux = $axis[0];
    $uy = $axis[1];
    $uz = $axis[2];
    return [
        [$cos + $ux ** 2 * (1 - $cos), $ux * $uy * (1 - $cos) - $uz * $sin, $ux * $uz * (1 - $cos) + $uy * $sin],
        [$uy * $ux * (1 - $cos) + $uz * $sin, $cos + $uy ** 2 * (1 - $cos), $uy * $uz * (1 - $cos) - $ux * $sin],
        [$uz * $ux * (1 - $cos) - $uy * $sin, $uz * $uy * (1 - $cos) + $ux * $sin, $cos + $uz ** 2 * (1 - $cos)]
    ];
}

function main() {
    $initial_point = [1, 0, 0];
    $angle = pi() / 4;
    $axis = [0, 0, 1];
    $n = 10;
    $sequence = generate_sequence($n, $initial_point, $angle, $axis);
    print_r($sequence);
}

main();