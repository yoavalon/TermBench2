<?php

function rotate_point($x, $y, $z, $angle) {
    $cos_a = cos($angle);
    $sin_a = sin($angle);
    $x_new = $x * $cos_a - $y * $sin_a;
    $y_new = $x * $sin_a + $y * $cos_a;
    return array($x_new, $y_new, $z);
}

function transform_coordinates($points, $angle, $depth) {
    if ($depth == 0) {
        return $points;
    }
    $transformed = array();
    foreach ($points as $point) {
        list($x, $y, $z) = $point;
        $transformed[] = rotate_point($x, $y, $z, $angle);
    }
    return transform_coordinates($transformed, $angle, $depth - 1);
}

function main() {
    $initial_points = array(array(1, 0, 0), array(0, 1, 0), array(0, 0, 1));
    $angle = 0.7853981633974483;
    $depth = 5;
    $result = transform_coordinates($initial_points, $angle, $depth);
    print_r($result);
}

main();

?>