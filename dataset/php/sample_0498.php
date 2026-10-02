<?php

function transform_point($x, $y, $z, $angle_x, $angle_y, $angle_z) {
    $rad_x = deg2rad($angle_x);
    $rad_y = deg2rad($angle_y);
    $rad_z = deg2rad($angle_z);
    $cos_x = cos($rad_x);
    $sin_x = sin($rad_x);
    $cos_y = cos($rad_y);
    $sin_y = sin($rad_y);
    $cos_z = cos($rad_z);
    $sin_z = sin($rad_z);
    $x1 = $x;
    $y1 = $y * $cos_x - $z * $sin_x;
    $z1 = $y * $sin_x + $z * $cos_x;
    $x2 = $x1 * $cos_y + $z1 * $sin_y;
    $y2 = $y1;
    $z2 = -$x1 * $sin_y + $z1 * $cos_y;
    $x3 = $x2 * $cos_z - $y2 * $sin_z;
    $y3 = $x2 * $sin_z + $y2 * $cos_z;
    $z3 = $z2;
    return array($x3, $y3, $z3);
}

function rotate_forever() {
    $angle_x = 0;
    $angle_y = 0;
    $angle_z = 0;
    while (true) {
        $x = 1;
        $y = 1;
        $z = 1;
        list($x, $y, $z) = transform_point($x, $y, $z, $angle_x, $angle_y, $angle_z);
        $angle_x += 1;
        $angle_y += 2;
        $angle_z += 3;
    }
}

rotate_forever();

?>