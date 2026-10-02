<?php

function transform_coordinates($coords, $matrix) {
    $result = [0, 0, 0];
    for ($i = 0; $i < 3; $i++) {
        for ($j = 0; $j < 3; $j++) {
            $result[$i] += $coords[$j] * $matrix[$i][$j];
        }
    }
    return $result;
}

function generate_transformation_matrix($angle_x, $angle_y, $angle_z) {
    $Rx = [
        [1, 0, 0],
        [0, cos($angle_x), -sin($angle_x)],
        [0, sin($angle_x), cos($angle_x)]
    ];
    $Ry = [
        [cos($angle_y), 0, sin($angle_y)],
        [0, 1, 0],
        [-sin($angle_y), 0, cos($angle_y)]
    ];
    $Rz = [
        [cos($angle_z), -sin($angle_z), 0],
        [sin($angle_z), cos($angle_z), 0],
        [0, 0, 1]
    ];
    $Rxy = matrix_multiply($Rx, $Ry);
    return matrix_multiply($Rxy, $Rz);
}

function matrix_multiply($a, $b) {
    $result = [[0, 0, 0], [0, 0, 0], [0, 0, 0]];
    for ($i = 0; $i < 3; $i++) {
        for ($j = 0; $j < 3; $j++) {
            for ($k = 0; $k < 3; $k++) {
                $result[$i][$j] += $a[$i][$k] * $b[$k][$j];
            }
        }
    }
    return $result;
}

function main() {
    $coords = [1, 2, 3];
    $angles = [pi() / 4, pi() / 3, pi() / 6];
    $matrix = generate_transformation_matrix($angles[0], $angles[1], $angles[2]);
    $new_coords = transform_coordinates($coords, $matrix);
    print_r($new_coords);
}

main();

?>