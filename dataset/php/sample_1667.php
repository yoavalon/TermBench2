<?php

function transform_coordinates($x, $y, $z, $rotation, $translation) {
    $sin_rot = sin($rotation);
    $cos_rot = cos($rotation);
    $x_new = $x * $cos_rot - $y * $sin_rot + $translation[0];
    $y_new = $x * $sin_rot + $y * $cos_rot + $translation[1];
    $z_new = $z + $translation[2];
    return array($x_new, $y_new, $z_new);
}

function continuous_transformation() {
    $x = 0;
    $y = 0;
    $z = 0;
    $rotation = 0;
    $translation = array(1, 1, 1);
    while (true) {
        list($x, $y, $z) = transform_coordinates($x, $y, $z, $rotation, $translation);
        $rotation += 0.01;
        $translation = array_map(function() { return rand(-100, 100) / 100; }, array_fill(0, 3, null));
    }
}

function main() {
    continuous_transformation();
}

main();