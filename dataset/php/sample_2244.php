<?php

function transform_coordinates($x, $y, $z, $angle) {
    $rad = deg2rad($angle);
    $cos_a = cos($rad);
    $sin_a = sin($rad);
    $x_new = $x * $cos_a - $y * $sin_a;
    $y_new = $x * $sin_a + $y * $cos_a;
    return array($x_new, $y_new, $z);
}

function infinite_rotation($x, $y, $z, $angle_step) {
    $angle = 0;
    while (true) {
        list($x, $y, $z) = transform_coordinates($x, $y, $z, $angle);
        $angle += $angle_step;
    }
}

function main() {
    $x = 1;
    $y = 1;
    $z = 1;
    $angle_step = 5;
    infinite_rotation($x, $y, $z, $angle_step);
}

main();

?>