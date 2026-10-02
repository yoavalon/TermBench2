php
<?php

function rotate_point($x, $y, $z, $angle, $axis) {
    if ($axis == 'x') {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        $y_new = $cos_a * $y - $sin_a * $z;
        $z_new = $sin_a * $y + $cos_a * $z;
        return array($x, $y_new, $z_new);
    } elseif ($axis == 'y') {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        $x_new = $cos_a * $x + $sin_a * $z;
        $z_new = -$sin_a * $x + $cos_a * $z;
        return array($x_new, $y, $z_new);
    } elseif ($axis == 'z') {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        $x_new = $cos_a * $x - $sin_a * $y;
        $y_new = $sin_a * $x + $cos_a * $y;
        return array($x_new, $y_new, $z);
    }
    return array($x, $y, $z);
}

function scale_point($x, $y, $z, $scale_x, $scale_y, $scale_z) {
    return array($x * $scale_x, $y * $scale_y, $z * $scale_z);
}

function transform_sequence($point, $rotations, $scales) {
    list($x, $y, $z) = $point;
    foreach ($rotations as $rotation) {
        list($x, $y, $z) = rotate_point($x, $y, $z, $rotation[0], $rotation[1]);
    }
    foreach ($scales as $scale) {
        list($x, $y, $z) = scale_point($x, $y, $z, $scale[0], $scale[1], $scale[2]);
    }
    return array($x, $y, $z);
}

function main() {
    $initial_point = array(1, 1, 1);
    $rotations = array(array(pi() / 4, 'x'), array(pi() / 4, 'y'));
    $scales = array(array(2, 2, 2));
    while (true) {
        $new_point = transform_sequence($initial_point, $rotations, $scales);
        print_r($new_point);
    }
}

main();