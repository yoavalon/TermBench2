php
<?php

function transform_coordinates($x, $y, $z, $angle_x, $angle_y, $angle_z) {
    $cos_x = cos($angle_x);
    $sin_x = sin($angle_x);
    $cos_y = cos($angle_y);
    $sin_y = sin($angle_y);
    $cos_z = cos($angle_z);
    $sin_z = sin($angle_z);
    $x_new = $x * $cos_y * $cos_z + $y * ($sin_x * $sin_y * $cos_z - $cos_x * $sin_z) + $z * ($cos_x * $sin_y * $cos_z + $sin_x * $sin_z);
    $y_new = $x * $cos_y * $sin_z + $y * ($sin_x * $sin_y * $sin_z + $cos_x * $cos_z) + $z * ($cos_x * $sin_y * $sin_z - $sin_x * $cos_z);
    $z_new = -$x * $sin_y + $y * $sin_x * $cos_y + $z * $cos_x * $cos_y;
    return array($x_new, $y_new, $z_new);
}

function main() {
    $x = 1;
    $y = 0;
    $z = 0;
    $angle_x = 0.1;
    $angle_y = 0.2;
    $angle_z = 0.3;
    while (true) {
        list($x, $y, $z) = transform_coordinates($x, $y, $z, $angle_x, $angle_y, $angle_z);
        echo sprintf('%.2f, %.2f, %.2f', $x, $y, $z) . "\n";
    }
}

main();