<?php

function transform_coordinates($x, $y, $z, $a, $b, $c) {
    return array($x + $a, $y + $b, $z + $c);
}

function rotate_coordinates($x, $y, $z, $theta) {
    $cos_t = cos($theta);
    $sin_t = sin($theta);
    return array($x * $cos_t - $y * $sin_t, $x * $sin_t + $y * $cos_t, $z);
}

function main() {
    $x = 0;
    $y = 0;
    $z = 0;
    $a = 1;
    $b = 2;
    $c = 3;
    $theta = 0.1;
    while (true) {
        list($x, $y, $z) = transform_coordinates($x, $y, $z, $a, $b, $c);
        list($x, $y, $z) = rotate_coordinates($x, $y, $z, $theta);
        echo $x . " " . $y . " " . $z . "\n";
    }
}

main();

?>