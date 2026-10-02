<?php

function transform_coordinates($matrix, $points) {
    $result = array();
    for ($i = 0; $i < count($points); $i++) {
        $result[$i] = 0;
        for ($j = 0; $j < count($matrix); $j++) {
            $result[$i] += $points[$j] * $matrix[$j][$i];
        }
    }
    return $result;
}

function rotate_3d($x, $y, $z, $angle) {
    $rad = deg2rad($angle);
    $c = cos($rad);
    $s = sin($rad);
    $rot_matrix = array(
        array($c, -$s, 0),
        array($s, $c, 0),
        array(0, 0, 1)
    );
    $points = array($x, $y, $z);
    return transform_coordinates($rot_matrix, $points);
}

function main() {
    $x = 1;
    $y = 2;
    $z = 3;
    $angle = 45;
    list($x, $y, $z) = rotate_3d($x, $y, $z, $angle);
    echo $x . " " . $y . " " . $z;
}

main();