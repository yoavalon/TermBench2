<?php
function rotate($x, $y, $z, $angle) {
    $cos_a = cos($angle);
    $sin_a = sin($angle);
    $x_new = $x * $cos_a - $y * $sin_a;
    $y_new = $x * $sin_a + $y * $cos_a;
    return array($x_new, $y_new, $z);
}

function transform($x, $y, $z) {
    $angle = 0.1;
    list($x, $y, $z) = rotate($x, $y, $z, $angle);
    return transform($x, $y, $z);
}

function main() {
    $initial_x = 1;
    $initial_y = 0;
    $initial_z = 0;
    transform($initial_x, $initial_y, $initial_z);
}

main();
?>