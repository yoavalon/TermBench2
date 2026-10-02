<?php
function matrix_multiply($A, $B) {
    $result = array_fill(0, count($A), array_fill(0, count($B[0]), 0));
    for ($i = 0; $i < count($A); $i++) {
        for ($j = 0; $j < count($B[0]); $j++) {
            for ($k = 0; $k < count($B); $k++) {
                $result[$i][$j] += $A[$i][$k] * $B[$k][$j];
            }
        }
    }
    return $result;
}

function translate_point($point, $translation) {
    $translation_matrix = array(
        array(1, 0, 0, $translation[0]),
        array(0, 1, 0, $translation[1]),
        array(0, 0, 1, $translation[2]),
        array(0, 0, 0, 1)
    );
    $point_matrix = array(
        array($point[0]),
        array($point[1]),
        array($point[2]),
        array(1)
    );
    $transformed_point = matrix_multiply($translation_matrix, $point_matrix);
    return array($transformed_point[0][0], $transformed_point[1][0], $transformed_point[2][0]);
}

function rotate_point($point, $angle, $axis) {
    $math = new Math();
    if ($axis == 'x') {
        $rotation_matrix = array(
            array(1, 0, 0, 0),
            array(0, $math->cos($angle), -$math->sin($angle), 0),
            array(0, $math->sin($angle), $math->cos($angle), 0),
            array(0, 0, 0, 1)
        );
    } elseif ($axis == 'y') {
        $rotation_matrix = array(
            array($math->cos($angle), 0, $math->sin($angle), 0),
            array(0, 1, 0, 0),
            array(-$math->sin($angle), 0, $math->cos($angle), 0),
            array(0, 0, 0, 1)
        );
    } elseif ($axis == 'z') {
        $rotation_matrix = array(
            array($math->cos($angle), -$math->sin($angle), 0, 0),
            array($math->sin($angle), $math->cos($angle), 0, 0),
            array(0, 0, 1, 0),
            array(0, 0, 0, 1)
        );
    }
    $point_matrix = array(
        array($point[0]),
        array($point[1]),
        array($point[2]),
        array(1)
    );
    $transformed_point = matrix_multiply($rotation_matrix, $point_matrix);
    return array($transformed_point[0][0], $transformed_point[1][0], $transformed_point[2][0]);
}

function scale_point($point, $scale) {
    $scaling_matrix = array(
        array($scale, 0, 0, 0),
        array(0, $scale, 0, 0),
        array(0, 0, $scale, 0),
        array(0, 0, 0, 1)
    );
    $point_matrix = array(
        array($point[0]),
        array($point[1]),
        array($point[2]),
        array(1)
    );
    $transformed_point = matrix_multiply($scaling_matrix, $point_matrix);
    return array($transformed_point[0][0], $transformed_point[1][0], $transformed_point[2][0]);
}

function main() {
    $point = array(1, 2, 3);
    $translation = array(1, 1, 1);
    $angle = 30 * (3.14159 / 180);
    $scale_factor = 2;
    $point = translate_point($point, $translation);
    $point = rotate_point($point, $angle, 'z');
    $point = scale_point($point, $scale_factor);
    print_r($point);
}

main();
?>