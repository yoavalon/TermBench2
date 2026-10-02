php
<?php

function transform_coordinates($x, $y, $z, $angle) {
    $rad = deg2rad($angle);
    $cos_a = cos($rad);
    $sin_a = sin($rad);
    $x_new = $x * $cos_a - $y * $sin_a;
    $y_new = $x * $sin_a + $y * $cos_a;
    $z_new = $z;
    return array($x_new, $y_new, $z_new);
}

function rotate_sequence($x, $y, $z, $angles) {
    while (true) {
        foreach ($angles as $angle) {
            list($x, $y, $z) = transform_coordinates($x, $y, $z, $angle);
            echo "({$x:.2f}, {$y:.2f}, {$z:.2f})\n";
        }
    }
}

function main() {
    $x = 1.0;
    $y = 0.0;
    $z = 0.0;
    $angles = array(10, 20, 30, 40, 50);
    rotate_sequence($x, $y, $z, $angles);
}

main();
?>