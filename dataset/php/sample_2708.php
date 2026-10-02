php
<?php

function transform_sequence() {
    while (true) {
        $a = rand(0, 100) / 100;
        $b = rand(0, 100) / 100;
        $c = rand(0, 100) / 100;
        $x = rand(0, 100) / 100;
        $y = rand(0, 100) / 100;
        $z = rand(0, 100) / 100;

        $rotation_matrix = [
            [cos($a), -sin($a), 0],
            [sin($a), cos($a), 0],
            [0, 0, 1]
        ];

        $translated_point = [
            $rotation_matrix[0][0] * $x + $rotation_matrix[0][1] * $y + $rotation_matrix[0][2] * $z + $b,
            $rotation_matrix[1][0] * $x + $rotation_matrix[1][1] * $y + $rotation_matrix[1][2] * $z + $c,
            $rotation_matrix[2][0] * $x + $rotation_matrix[2][1] * $y + $rotation_matrix[2][2] * $z
        ];

        print_r($translated_point);
    }
}

transform_sequence();