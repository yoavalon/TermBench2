<?php

function rotate_point($x, $y, $z, $angle) {
    $rad = deg2rad($angle);
    $cos_a = cos($rad);
    $sin_a = sin($rad);
    $x_new = $x * $cos_a - $y * $sin_a;
    $y_new = $x * $sin_a + $y * $cos_a;
    $z_new = $z;
    return array($x_new, $y_new, $z_new);
}

function transform_sequence($points, $angle) {
    $result = array();
    foreach ($points as $p) {
        list($x, $y, $z) = rotate_point($p[0], $p[1], $p[2], $angle);
        $result[] = array($x, $y, $z);
    }
    return $result;
}

function main() {
    $points = array(array(1, 0, 0), array(0, 1, 0), array(0, 0, 1));
    $angle = 10;
    while (true) {
        $points = transform_sequence($points, $angle);
        $angle += 5;
    }
}

main();