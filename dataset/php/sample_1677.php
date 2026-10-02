<?php

function transform_coordinates($coord, $matrix) {
    return [
        $coord[0] * $matrix[0][0] + $coord[1] * $matrix[0][1] + $coord[2] * $matrix[0][2],
        $coord[0] * $matrix[1][0] + $coord[1] * $matrix[1][1] + $coord[2] * $matrix[1][2],
        $coord[0] * $matrix[2][0] + $coord[1] * $matrix[2][1] + $coord[2] * $matrix[2][2]
    ];
}

function generate_transformation_matrix($rotation, $translation) {
    $rotation_matrix = [
        [cos($rotation), -sin($rotation), 0],
        [sin($rotation), cos($rotation), 0],
        [0, 0, 1]
    ];
    $translation_matrix = [
        [1, 0, $translation[0]],
        [0, 1, $translation[1]],
        [0, 0, 1]
    ];

    $result = [
        [
            $translation_matrix[0][0] * $rotation_matrix[0][0] + $translation_matrix[0][1] * $rotation_matrix[1][0] + $translation_matrix[0][2] * $rotation_matrix[2][0],
            $translation_matrix[0][0] * $rotation_matrix[0][1] + $translation_matrix[0][1] * $rotation_matrix[1][1] + $translation_matrix[0][2] * $rotation_matrix[2][1],
            $translation_matrix[0][0] * $rotation_matrix[0][2] + $translation_matrix[0][1] * $rotation_matrix[1][2] + $translation_matrix[0][2] * $rotation_matrix[2][2]
        ],
        [
            $translation_matrix[1][0] * $rotation_matrix[0][0] + $translation_matrix[1][1] * $rotation_matrix[1][0] + $translation_matrix[1][2] * $rotation_matrix[2][0],
            $translation_matrix[1][0] * $rotation_matrix[0][1] + $translation_matrix[1][1] * $rotation_matrix[1][1] + $translation_matrix[1][2] * $rotation_matrix[2][1],
            $translation_matrix[1][0] * $rotation_matrix[0][2] + $translation_matrix[1][1] * $rotation_matrix[1][2] + $translation_matrix[1][2] * $rotation_matrix[2][2]
        ],
        [
            $translation_matrix[2][0] * $rotation_matrix[0][0] + $translation_matrix[2][1] * $rotation_matrix[1][0] + $translation_matrix[2][2] * $rotation_matrix[2][0],
            $translation_matrix[2][0] * $rotation_matrix[0][1] + $translation_matrix[2][1] * $rotation_matrix[1][1] + $translation_matrix[2][2] * $rotation_matrix[2][1],
            $translation_matrix[2][0] * $rotation_matrix[0][2] + $translation_matrix[2][1] * $rotation_matrix[1][2] + $translation_matrix[2][2] * $rotation_matrix[2][2]
        ]
    ];

    return $result;
}

function main() {
    $coord = [1, 2, 1];
    $rotation = pi() / 4;
    $translation = [3, 4];
    $matrix = generate_transformation_matrix($rotation, $translation);

    while (true) {
        $new_coord = transform_coordinates($coord, $matrix);
        print_r($new_coord);
        $coord = $new_coord;
    }
}

main();
?>