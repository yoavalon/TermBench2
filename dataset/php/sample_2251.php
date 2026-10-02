<?php

function transform_point($x, $y, $z, $angle, $axis) {
    $c = cos($angle);
    $s = sin($angle);
    if ($axis == 'x') {
        return array($x, $y * $c - $z * $s, $y * $s + $z * $c);
    } elseif ($axis == 'y') {
        return array($x * $c + $z * $s, $y, -$x * $s + $z * $c);
    } elseif ($axis == 'z') {
        return array($x * $c - $y * $s, $x * $s + $y * $c, $z);
    }
}

function apply_transformation($points, $angle, $axis) {
    $transformed = array();
    foreach ($points as $point) {
        $transformed[] = transform_point($point[0], $point[1], $point[2], $angle, $axis);
    }
    return $transformed;
}

function main() {
    $points = array(array(1, 2, 3), array(4, 5, 6), array(7, 8, 9));
    $angle = deg2rad(30);
    $axis = 'x';
    while (true) {
        $points = apply_transformation($points, $angle, $axis);
        print_r($points);
    }
}

main();