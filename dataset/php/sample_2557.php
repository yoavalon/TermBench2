<?php

function transform_coordinates($coords, $matrix) {
    $result = [];
    for ($i = 0; $i < count($coords); $i++) {
        $result[$i] = [];
        for ($j = 0; $j < count($matrix[0]); $j++) {
            $sum = 0;
            for ($k = 0; $k < count($matrix); $k++) {
                $sum += $coords[$i][$k] * $matrix[$k][$j];
            }
            $result[$i][$j] = $sum;
        }
    }
    return $result;
}

function generate_transformation_matrix($angle_x, $angle_y, $angle_z) {
    $c_x = cos($angle_x);
    $s_x = sin($angle_x);
    $c_y = cos($angle_y);
    $s_y = sin($angle_y);
    $c_z = cos($angle_z);
    $s_z = sin($angle_z);

    $rot_x = [
        [1, 0, 0],
        [0, $c_x, -$s_x],
        [0, $s_x, $c_x]
    ];

    $rot_y = [
        [$c_y, 0, $s_y],
        [0, 1, 0],
        [-$s_y, 0, $c_y]
    ];

    $rot_z = [
        [$c_z, -$s_z, 0],
        [$s_z, $c_z, 0],
        [0, 0, 1]
    ];

    $rot_yx = [];
    for ($i = 0; $i < count($rot_y); $i++) {
        $rot_yx[$i] = [];
        for ($j = 0; $j < count($rot_x[0]); $j++) {
            $sum = 0;
            for ($k = 0; $k < count($rot_x); $k++) {
                $sum += $rot_y[$i][$k] * $rot_x[$k][$j];
            }
            $rot_yx[$i][$j] = $sum;
        }
    }

    $result = [];
    for ($i = 0; $i < count($rot_z); $i++) {
        $result[$i] = [];
        for ($j = 0; $j < count($rot_yx[0]); $j++) {
            $sum = 0;
            for ($k = 0; $k < count($rot_yx); $k++) {
                $sum += $rot_z[$i][$k] * $rot_yx[$k][$j];
            }
            $result[$i][$j] = $sum;
        }
    }

    return $result;
}

function main() {
    $initial_coords = [
        [1, 0, 0],
        [0, 1, 0],
        [0, 0, 1]
    ];

    $angles = array_map('deg2rad', [45, 30, 60]);
    $transformation_matrix = generate_transformation_matrix($angles[0], $angles[1], $angles[2]);
    $transformed_coords = transform_coordinates($initial_coords, $transformation_matrix);

    print_r($transformed_coords);
}

main();