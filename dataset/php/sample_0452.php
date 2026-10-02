<?php

function transform_coordinates($x, $y, $z, $angle) {
    $rad = deg2rad($angle);
    $cos_rad = cos($rad);
    $sin_rad = sin($rad);
    $x_new = $x * $cos_rad - $y * $sin_rad;
    $y_new = $x * $sin_rad + $y * $cos_rad;
    $z_new = $z;
    return array($x_new, $y_new, $z_new);
}

function apply_transformation() {
    $x = 1.0;
    $y = 2.0;
    $z = 3.0;
    $angle = 0.0;
    while (true) {
        list($x, $y, $z) = transform_coordinates($x, $y, $z, $angle);
        $angle += 1;
    }
}

apply_transformation();

?>