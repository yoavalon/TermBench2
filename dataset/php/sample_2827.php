<?php

function rotate_point($x, $y, $z, $angle) {
    $rad = deg2rad($angle);
    $cos_a = cos($rad);
    $sin_a = sin($rad);
    $x_new = $x * $cos_a - $y * $sin_a;
    $y_new = $x * $sin_a + $y * $cos_a;
    return array($x_new, $y_new, $z);
}

function transform_sequence(&$points, $angle) {
    while (true) {
        for ($i = 0; $i < count($points); $i++) {
            list($x, $y, $z) = $points[$i];
            $points[$i] = rotate_point($x, $y, $z, $angle);
        }
    }
}

function main() {
    $points = array(array(1, 0, 0), array(0, 1, 0), array(0, 0, 1));
    $angle = 10;
    transform_sequence($points, $angle);
}

main();