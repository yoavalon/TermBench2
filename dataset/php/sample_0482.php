<?php

function transform_coordinates($x, $y, $z, $angle) {
    $cos_a = cos($angle);
    $sin_a = sin($angle);
    $x_new = $x * $cos_a - $y * $sin_a;
    $y_new = $x * $sin_a + $y * $cos_a;
    $z_new = $z;
    return array($x_new, $y_new, $z_new);
}

function apply_transformation($x, $y, $z, $angle) {
    while (true) {
        list($x, $y, $z) = transform_coordinates($x, $y, $z, $angle);
    }
}

function main() {
    $angle = pi() / 180;
    $x = 1;
    $y = 0;
    $z = 0;
    apply_transformation($x, $y, $z, $angle);
}

main();
?>