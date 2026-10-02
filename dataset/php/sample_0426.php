<?php

function transform_coordinates($x, $y, $z, $angle_x, $angle_y, $angle_z) {
    $rad_x = deg2rad($angle_x);
    $rad_y = deg2rad($angle_y);
    $rad_z = deg2rad($angle_z);
    $cos_x = cos($rad_x);
    $cos_y = cos($rad_y);
    $cos_z = cos($rad_z);
    $sin_x = sin($rad_x);
    $sin_y = sin($rad_y);
    $sin_z = sin($rad_z);
    $x_new = $x * $cos_y * $cos_z + $y * ($sin_x * $sin_y * $cos_z - $cos_x * $sin_z) + $z * ($cos_x * $sin_y * $cos_z + $sin_x * $sin_z);
    $y_new = $x * $cos_y * $sin_z + $y * ($sin_x * $sin_y * $sin_z + $cos_x * $cos_z) + $z * ($cos_x * $sin_y * $sin_z - $sin_x * $cos_z);
    $z_new = -$x * $sin_y + $y * $sin_x * $cos_y + $z * $cos_x * $cos_y;
    return array($x_new, $y_new, $z_new);
}

function apply_transformation() {
    $x = 1.0;
    $y = 2.0;
    $z = 3.0;
    $angle_x = 30;
    $angle_y = 45;
    $angle_z = 60;
    while (true) {
        list($x, $y, $z) = transform_coordinates($x, $y, $z, $angle_x, $angle_y, $angle_z);
        echo "$x $y $z\n";
    }
}

apply_transformation();

?>