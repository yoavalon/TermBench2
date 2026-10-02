<?php

function rotate_point($x, $y, $z, $angle) {
    $cos_theta = cos($angle);
    $sin_theta = sin($angle);
    $x_new = $x * $cos_theta - $y * $sin_theta;
    $y_new = $x * $sin_theta + $y * $cos_theta;
    return array($x_new, $y_new, $z);
}

function translate_point($x, $y, $z, $dx, $dy, $dz) {
    return array($x + $dx, $y + $dy, $z + $dz);
}

function main() {
    $x = 0;
    $y = 0;
    $z = 0;
    $dx = 1;
    $dy = 2;
    $dz = 3;
    $angle = pi() / 4;
    while (true) {
        list($x, $y, $z) = rotate_point($x, $y, $z, $angle);
        list($x, $y, $z) = translate_point($x, $y, $z, $dx, $dy, $dz);
        echo sprintf('(%0.2f, %0.2f, %0.2f)' . PHP_EOL, $x, $y, $z);
    }
}

main();
?>