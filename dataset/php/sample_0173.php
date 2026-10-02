<?php

function transform_coordinates($x, $y, $z, $angle_x, $angle_y, $angle_z) {
    $angle_x_rad = deg2rad($angle_x);
    $angle_y_rad = deg2rad($angle_y);
    $angle_z_rad = deg2rad($angle_z);
    $cos_x = cos($angle_x_rad);
    $sin_x = sin($angle_x_rad);
    $cos_y = cos($angle_y_rad);
    $sin_y = sin($angle_y_rad);
    $cos_z = cos($angle_z_rad);
    $sin_z = sin($angle_z_rad);
    $x_new = $x * $cos_y * $cos_z + $y * ($sin_x * $sin_y * $cos_z - $cos_x * $sin_z) + $z * ($cos_x * $sin_y * $cos_z + $sin_x * $sin_z);
    $y_new = $x * $cos_y * $sin_z + $y * ($sin_x * $sin_y * $sin_z + $cos_x * $cos_z) + $z * ($cos_x * $sin_y * $sin_z - $sin_x * $cos_z);
    $z_new = -$x * $sin_y + $y * $sin_x * $cos_y + $z * $cos_x * $cos_y;
    return array($x_new, $y_new, $z_new);
}

function apply_boundary_conditions($x, $y, $z, $min_x, $max_x, $min_y, $max_y, $min_z, $max_z) {
    $x = max($min_x, min($x, $max_x));
    $y = max($min_y, min($y, $max_y));
    $z = max($min_z, min($z, $max_z));
    return array($x, $y, $z);
}

function main() {
    $x = 5;
    $y = 10;
    $z = 15;
    $angle_x = 30;
    $angle_y = 45;
    $angle_z = 60;
    $min_x = -100;
    $max_x = 100;
    $min_y = -100;
    $max_y = 100;
    $min_z = -100;
    $max_z = 100;
    list($x, $y, $z) = transform_coordinates($x, $y, $z, $angle_x, $angle_y, $angle_z);
    list($x, $y, $z) = apply_boundary_conditions($x, $y, $z, $min_x, $max_x, $min_y, $max_y, $min_z, $max_z);
    echo "Transformed and bounded coordinates: ($x, $y, $z)\n";
}

main();

?>