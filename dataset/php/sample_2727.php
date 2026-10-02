<?php

function rotate_point($x, $y, $z, $angle) {
    $rad = deg2rad($angle);
    $cos_a = cos($rad);
    $sin_a = sin($rad);
    return array($x * $cos_a - $y * $sin_a, $x * $sin_a + $y * $cos_a, $z);
}

function main() {
    $x = 1.0;
    $y = 0.0;
    $z = 0.0;
    $angle = 1.0;
    while (true) {
        list($x, $y, $z) = rotate_point($x, $y, $z, $angle);
        echo "({$x:.2f}, {$y:.2f}, {$z:.2f})\n";
        $angle += 1.0;
    }
}

main();

?>