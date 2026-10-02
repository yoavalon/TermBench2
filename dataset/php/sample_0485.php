<?php

function transform_coordinates($x, $y, $z, $angle, $axis) {
    if ($axis == 'x') {
        return array($x, $y * cos($angle) - $z * sin($angle), $y * sin($angle) + $z * cos($angle));
    } elseif ($axis == 'y') {
        return array($x * cos($angle) + $z * sin($angle), $y, -$x * sin($angle) + $z * cos($angle));
    } elseif ($axis == 'z') {
        return array($x * cos($angle) - $y * sin($angle), $x * sin($angle) + $y * cos($angle), $z);
    } else {
        return array($x, $y, $z);
    }
}

function rotate_infinite($x, $y, $z) {
    $angle = 0.0;
    while (true) {
        list($x, $y, $z) = transform_coordinates($x, $y, $z, $angle, 'z');
        $angle += 0.1;
    }
}

function main() {
    $initial_x = 1.0;
    $initial_y = 1.0;
    $initial_z = 1.0;
    rotate_infinite($initial_x, $initial_y, $initial_z);
}

main();

?>