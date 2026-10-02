<?php

function transform_coordinates($x, $y, $z, $angle) {
    $rad = deg2rad($angle);
    $cos_a = cos($rad);
    $sin_a = sin($rad);
    $new_x = $x * $cos_a - $y * $sin_a;
    $new_y = $x * $sin_a + $y * $cos_a;
    $new_z = $z;
    return array($new_x, $new_y, $new_z);
}

function calculate_distance($x1, $y1, $z1, $x2, $y2, $z2) {
    return sqrt(pow($x2 - $x1, 2) + pow($y2 - $y1, 2) + pow($z2 - $z1, 2));
}

function main() {
    $x = 1.0;
    $y = 2.0;
    $z = 3.0;
    $angle = 30;
    list($x_t, $y_t, $z_t) = transform_coordinates($x, $y, $z, $angle);
    $d = calculate_distance($x, $y, $z, $x_t, $y_t, $z_t);
    echo "Transformed Coordinates: ($x_t, $y_t, $z_t)\n";
    echo "Distance: $d\n";
}

main();
?>