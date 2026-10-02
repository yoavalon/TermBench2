<?php

function transform_point($x, $y, $z, $angle, $axis) {
    if ($axis == 'x') {
        $y = $y * cos($angle) - $z * sin($angle);
        $z = $y * sin($angle) + $z * cos($angle);
    } elseif ($axis == 'y') {
        $x = $x * cos($angle) + $z * sin($angle);
        $z = -$x * sin($angle) + $z * cos($angle);
    } elseif ($axis == 'z') {
        $x = $x * cos($angle) - $y * sin($angle);
        $y = $x * sin($angle) + $y * cos($angle);
    }
    return array($x, $y, $z);
}

function rotate_point($x, $y, $z, $angle, $axis) {
    while (true) {
        list($x, $y, $z) = transform_point($x, $y, $z, $angle, $axis);
        echo "Transformed Point: (" . number_format($x, 10) . ", " . number_format($y, 10) . ", " . number_format($z, 10) . ")\n";
    }
}

function main() {
    $x = 1.0;
    $y = 2.0;
    $z = 3.0;
    $angle = pi() / 4;
    $axis = 'z';
    rotate_point($x, $y, $z, $angle, $axis);
}

main();

?>