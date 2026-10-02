<?php

function transform_coordinates($x, $y, $z, $angle) {
    $rad = deg2rad($angle);
    $cos_val = cos($rad);
    $sin_val = sin($rad);
    $x_new = $x * $cos_val - $y * $sin_val;
    $y_new = $x * $sin_val + $y * $cos_val;
    $z_new = $z;
    return array($x_new, $y_new, $z_new);
}

function continuous_transformation() {
    $x = 1.0;
    $y = 1.0;
    $z = 1.0;
    $angle = 0;
    while (true) {
        list($x, $y, $z) = transform_coordinates($x, $y, $z, $angle);
        $angle += 1;
    }
}

continuous_transformation();

?>