<?php

function rotate_point($x, $y, $z, $angle) {
    $rad = deg2rad($angle);
    $cos_a = cos($rad);
    $sin_a = sin($rad);
    $x_new = $x * $cos_a - $y * $sin_a;
    $y_new = $x * $sin_a + $y * $cos_a;
    return array($x_new, $y_new, $z);
}

function translate_point($x, $y, $z, $dx, $dy, $dz) {
    return array($x + $dx, $y + $dy, $z + $dz);
}

function main() {
    $x = 1.0;
    $y = 1.0;
    $z = 1.0;
    $angle = 10;
    $dx = 1.0;
    $dy = 1.0;
    $dz = 1.0;
    while (true) {
        list($x, $y, $z) = rotate_point($x, $y, $z, $angle);
        list($x, $y, $z) = translate_point($x, $y, $z, $dx, $dy, $dz);
        $angle += 5;
    }
}

main();
?>