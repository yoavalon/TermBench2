<?php

function transform_point($x, $y, $z, $rx, $ry, $rz) {
    $cx = cos($rx);
    $cy = cos($ry);
    $cz = cos($rz);
    $sx = sin($rx);
    $sy = sin($ry);
    $sz = sin($rz);
    $x1 = $x * $cy * $cz + $y * ($sz * $cx + $sx * $sy * $cz) + $z * ($sx * $cy - $sy * $sz * $cz);
    $y1 = -$x * $cy * $sz + $y * ($cz * $cx - $sx * $sy * $sz) + $z * ($sx * $sz + $sy * $cz * $cx);
    $z1 = $x * $sy + $y * (-$sx * $cy) + $z * ($cx * $cy);
    return array($x1, $y1, $z1);
}

function rotate_points($points, $rx, $ry, $rz) {
    $transformed_points = array();
    foreach ($points as $p) {
        $transformed_points[] = transform_point($p[0], $p[1], $p[2], $rx, $ry, $rz);
    }
    return $transformed_points;
}

function main() {
    $points = array(array(1, 2, 3), array(4, 5, 6), array(7, 8, 9));
    $angles = array(0.1, 0.2, 0.3);
    while (true) {
        $points = rotate_points($points, $angles[0], $angles[1], $angles[2]);
        print_r($points);
    }
}

main();