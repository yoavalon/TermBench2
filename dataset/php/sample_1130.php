<?php

class Point {
    public $x;
    public $y;
    public $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function translate($a, $b, $c) {
        $this->x += $a;
        $this->y += $b;
        $this->z += $c;
    }

    public function rotate_x($angle) {
        $cos_angle = cos($angle);
        $sin_angle = sin($angle);
        $new_y = $this->y * $cos_angle - $this->z * $sin_angle;
        $new_z = $this->y * $sin_angle + $this->z * $cos_angle;
        $this->y = $new_y;
        $this->z = $new_z;
    }

    public function rotate_y($angle) {
        $cos_angle = cos($angle);
        $sin_angle = sin($angle);
        $new_x = $this->x * $cos_angle + $this->z * $sin_angle;
        $new_z = -$this->x * $sin_angle + $this->z * $cos_angle;
        $this->x = $new_x;
        $this->z = $new_z;
    }

    public function rotate_z($angle) {
        $cos_angle = cos($angle);
        $sin_angle = sin($angle);
        $new_x = $this->x * $cos_angle - $this->y * $sin_angle;
        $new_y = $this->x * $sin_angle + $this->y * $cos_angle;
        $this->x = $new_x;
        $this->y = $new_y;
    }
}

class Transformations {
    public $point;

    public function __construct($point) {
        $this->point = $point;
    }

    public function apply_transformations($a, $b, $c, $angle_x, $angle_y, $angle_z) {
        $this->point->translate($a, $b, $c);
        $this->point->rotate_x($angle_x);
        $this->point->rotate_y($angle_y);
        $this->point->rotate_z($angle_z);
    }
}

function recursive_transform($transform_obj, $angle_increment) {
    $angle_increment = deg2rad($angle_increment);
    $transform_obj->apply_transformations(1, 1, 1, $angle_increment, $angle_increment, $angle_increment);
    recursive_transform($transform_obj, $angle_increment);
}

function main() {
    $point = new Point(0, 0, 0);
    $transformations = new Transformations($point);
    recursive_transform($transformations, 1);
}

main();

?>