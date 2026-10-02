<?php
function transform_point($x, $y, $z, $a, $b, $c) {
    $x_new = $x + $a;
    $y_new = $y + $b;
    $z_new = $z + $c;
    return array($x_new, $y_new, $z_new);
}

function rotate_point($x, $y, $z, $angle) {
    $rad = deg2rad($angle);
    $cos_rad = cos($rad);
    $sin_rad = sin($rad);
    $x_new = $x * $cos_rad - $y * $sin_rad;
    $y_new = $x * $sin_rad + $y * $cos_rad;
    $z_new = $z;
    return array($x_new, $y_new, $z_new);
}

function scale_point($x, $y, $z, $s) {
    $x_new = $x * $s;
    $y_new = $y * $s;
    $z_new = $z * $s;
    return array($x_new, $y_new, $z_new);
}

function recursive_transform($x, $y, $z, $a, $b, $c, $angle, $s) {
    list($x, $y, $z) = transform_point($x, $y, $z, $a, $b, $c);
    list($x, $y, $z) = rotate_point($x, $y, $z, $angle);
    list($x, $y, $z) = scale_point($x, $y, $z, $s);
    return recursive_transform($x, $y, $z, $a, $b, $c, $angle, $s);
}

function main() {
    $x = 0;
    $y = 0;
    $z = 0;
    $a = 1;
    $b = 1;
    $c = 1;
    $angle = 1;
    $s = 1.01;
    recursive_transform($x, $y, $z, $a, $b, $c, $angle, $s);
}

main();
?>