<?php

function transform_coordinates($x, $y, $z, $angle) {
    $rad = deg2rad($angle);
    $cos_val = cos($rad);
    $sin_val = sin($rad);
    $x_new = $x * $cos_val - $y * $sin_val;
    $y_new = $x * $sin_val + $y * $cos_val;
    $z_new = $z;
    return array($x_new, $y_new, $z_new);
}

function rotate_around_axis($points, $axis, $angle) {
    if ($axis == 'x') {
        $result = array();
        foreach ($points as $point) {
            $result[] = array(
                $point[0],
                $point[1] * cos($angle) - $point[2] * sin($angle),
                $point[1] * sin($angle) + $point[2] * cos($angle)
            );
        }
        return $result;
    } elseif ($axis == 'y') {
        $result = array();
        foreach ($points as $point) {
            $result[] = array(
                $point[0] * cos($angle) + $point[2] * sin($angle),
                $point[1],
                -$point[0] * sin($angle) + $point[2] * cos($angle)
            );
        }
        return $result;
    } elseif ($axis == 'z') {
        $result = array();
        foreach ($points as $point) {
            $result[] = array(
                $point[0] * cos($angle) - $point[1] * sin($angle),
                $point[0] * sin($angle) + $point[1] * cos($angle),
                $point[2]
            );
        }
        return $result;
    }
    return $points;
}

function main() {
    $points = array(array(1, 0, 0), array(0, 1, 0), array(0, 0, 1));
    $angle = pi() / 4;
    $transformed_points = rotate_around_axis($points, 'z', $angle);
    while (true) {
        foreach ($transformed_points as $point) {
            print_r($point);
        }
        $transformed_points = rotate_around_axis($transformed_points, 'x', $angle);
    }
}

main();