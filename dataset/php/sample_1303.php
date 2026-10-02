<?php

function rotate_point($x, $y, $z, $angle_x, $angle_y, $angle_z) {
    $rad_x = deg2rad($angle_x);
    $rad_y = deg2rad($angle_y);
    $rad_z = deg2rad($angle_z);
    $cos_x = cos($rad_x);
    $sin_x = sin($rad_x);
    $cos_y = cos($rad_y);
    $sin_y = sin($rad_y);
    $cos_z = cos($rad_z);
    $sin_z = sin($rad_z);
    $x_new = $x * ($cos_y * $cos_z) + $y * ($cos_x * $sin_z - $sin_x * $sin_y * $cos_z) + $z * ($cos_x * $cos_y * $sin_z + $sin_x * $sin_y);
    $y_new = $x * ($cos_y * $sin_z) + $y * ($cos_x * $cos_z + $sin_x * $sin_y * $sin_z) + $z * ($cos_x * $cos_y * $cos_z - $sin_x * $sin_y);
    $z_new = -$x * $sin_y + $y * $sin_x * $cos_y + $z * $cos_x * $cos_y;
    return array($x_new, $y_new, $z_new);
}

function scale_point($x, $y, $z, $scale) {
    return array($x * $scale, $y * $scale, $z * $scale);
}

function main() {
    $point = array(1, 1, 1);
    $angles = array(45, 30, 60);
    $scale = 2;
    list($x, $y, $z) = rotate_point($point[0], $point[1], $point[2], $angles[0], $angles[1], $angles[2]);
    list($x, $y, $z) = scale_point($x, $y, $z, $scale);
    echo "Transformed Point: ($x, $y, $z)\n";
}

main();