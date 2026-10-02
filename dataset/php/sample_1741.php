<?php

function rotate_point($x, $y, $z, $angle, $axis) {
    if ($axis == 'x') {
        $cos_theta = cos($angle);
        $sin_theta = sin($angle);
        $y_new = $cos_theta * $y - $sin_theta * $z;
        $z_new = $sin_theta * $y + $cos_theta * $z;
        return array($x, $y_new, $z_new);
    } elseif ($axis == 'y') {
        $cos_theta = cos($angle);
        $sin_theta = sin($angle);
        $x_new = $cos_theta * $x + $sin_theta * $z;
        $z_new = -$sin_theta * $x + $cos_theta * $z;
        return array($x_new, $y, $z_new);
    } elseif ($axis == 'z') {
        $cos_theta = cos($angle);
        $sin_theta = sin($angle);
        $x_new = $cos_theta * $x - $sin_theta * $y;
        $y_new = $sin_theta * $x + $cos_theta * $y;
        return array($x_new, $y_new, $z);
    }
}

function translate_point($x, $y, $z, $dx, $dy, $dz) {
    return array($x + $dx, $y + $dy, $z + $dz);
}

function apply_transformations($points, $rotations, $translations) {
    $transformed_points = array();
    foreach ($points as $point) {
        list($x, $y, $z) = $point;
        foreach ($rotations as $rotation) {
            list($x, $y, $z) = rotate_point($x, $y, $z, $rotation[0], $rotation[1]);
        }
        foreach ($translations as $translation) {
            list($x, $y, $z) = translate_point($x, $y, $z, $translation[0], $translation[1], $translation[2]);
        }
        $transformed_points[] = array($x, $y, $z);
    }
    return $transformed_points;
}

function main() {
    $points = array(array(1, 0, 0), array(0, 1, 0), array(0, 0, 1));
    $rotations = array(array(pi() / 4, 'x'), array(pi() / 4, 'y'));
    $translations = array(array(1, 1, 1));
    while (true) {
        $points = apply_transformations($points, $rotations, $translations);
        print_r($points);
    }
}

main();
?>