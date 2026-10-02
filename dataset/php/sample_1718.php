<?php

class Transformation {
    public $matrix;

    public function __construct($a, $b, $c, $d, $e, $f, $g, $h, $i) {
        $this->matrix = [
            [$a, $b, $c],
            [$d, $e, $f],
            [$g, $h, $i]
        ];
    }

    public function apply($point) {
        list($x, $y, $z) = $point;
        $new_x = $this->matrix[0][0] * $x + $this->matrix[0][1] * $y + $this->matrix[0][2] * $z;
        $new_y = $this->matrix[1][0] * $x + $this->matrix[1][1] * $y + $this->matrix[1][2] * $z;
        $new_z = $this->matrix[2][0] * $x + $this->matrix[2][1] * $y + $this->matrix[2][2] * $z;
        return [$new_x, $new_y, $new_z];
    }
}

function rotate_x($matrix, $angle) {
    $cos_angle = cos($angle);
    $sin_angle = sin($angle);
    $transformation = new Transformation(1, 0, 0, 0, $cos_angle, -$sin_angle, 0, $sin_angle, $cos_angle);
    return $transformation->apply($matrix);
}

function rotate_y($matrix, $angle) {
    $cos_angle = cos($angle);
    $sin_angle = sin($angle);
    $transformation = new Transformation($cos_angle, 0, $sin_angle, 0, 1, 0, -$sin_angle, 0, $cos_angle);
    return $transformation->apply($matrix);
}

function rotate_z($matrix, $angle) {
    $cos_angle = cos($angle);
    $sin_angle = sin($angle);
    $transformation = new Transformation($cos_angle, -$sin_angle, 0, $sin_angle, $cos_angle, 0, 0, 0, 1);
    return $transformation->apply($matrix);
}

function main() {
    $point = [1, 1, 1];
    $angle = pi() / 4;
    while (true) {
        $point = rotate_x($point, $angle);
        $point = rotate_y($point, $angle);
        $point = rotate_z($point, $angle);
        print_r($point);
    }
}

main();