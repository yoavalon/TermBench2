<?php

function transform_point($x, $y, $z, $angle_x, $angle_y, $angle_z) {
    $cos_x = cos($angle_x);
    $sin_x = sin($angle_x);
    $cos_y = cos($angle_y);
    $sin_y = sin($angle_y);
    $cos_z = cos($angle_z);
    $sin_z = sin($angle_z);
    $x_new = $x * $cos_y * $cos_z + $y * ($cos_x * $sin_z - $sin_x * $sin_y * $cos_z) + $z * ($sin_x * $sin_z + $cos_x * $sin_y * $cos_z);
    $y_new = $x * $cos_y * $sin_z + $y * ($cos_x * $cos_z + $sin_x * $sin_y * $sin_z) + $z * ($sin_x * $cos_z - $cos_x * $sin_y * $sin_z);
    $z_new = -$x * $sin_y + $y * $sin_x * $cos_y + $z * $cos_x * $cos_y;
    return array($x_new, $y_new, $z_new);
}

function main() {
    $x = 1.0;
    $y = 2.0;
    $z = 3.0;
    $angle_x = pi() / 4;
    $angle_y = pi() / 3;
    $angle_z = pi() / 6;
    while (true) {
        list($x, $y, $z) = transform_point($x, $y, $z, $angle_x, $angle_y, $angle_z);
        echo "Transformed Point: ($x, $y, $z)\n";
    }
}

main();

?>