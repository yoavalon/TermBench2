<?php

class Coordinate {

    public $x;
    public $y;
    public $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function distance_to($other) {
        $dx = $this->x - $other->x;
        $dy = $this->y - $other->y;
        $dz = $this->z - $other->z;
        return sqrt($dx ** 2 + $dy ** 2 + $dz ** 2);
    }

}

class Transformation {

    public $angle;
    public $axis;

    public function __construct($angle, $axis) {
        $this->angle = $angle;
        $this->axis = $axis;
    }

    public function rotate($point) {
        $x = $point->x;
        $y = $point->y;
        $z = $point->z;
        $u = $this->axis->x;
        $v = $this->axis->y;
        $w = $this->axis->z;
        $cos_a = cos($this->angle);
        $sin_a = sin($this->angle);
        $norm = sqrt($u ** 2 + $v ** 2 + $w ** 2);
        $u = $u / $norm;
        $v = $v / $norm;
        $w = $w / $norm;
        $x_new = ($u ** 2 + (1 - $u ** 2) * $cos_a) * $x + ($u * $v * (1 - $cos_a) - $w * $sin_a) * $y + ($u * $w * (1 - $cos_a) + $v * $sin_a) * $z;
        $y_new = ($u * $v * (1 - $cos_a) + $w * $sin_a) * $x + ($v ** 2 + (1 - $v ** 2) * $cos_a) * $y + ($v * $w * (1 - $cos_a) - $u * $sin_a) * $z;
        $z_new = ($u * $w * (1 - $cos_a) - $v * $sin_a) * $x + ($v * $w * (1 - $cos_a) + $u * $sin_a) * $y + ($w ** 2 + (1 - $w ** 2) * $cos_a) * $z;
        return new Coordinate($x_new, $y_new, $z_new);
    }

}

function transform_sequence($points, $transformations) {
    $transformed_points = array();
    foreach ($points as $point) {
        foreach ($transformations as $transform) {
            $point = $transform->rotate($point);
        }
        array_push($transformed_points, $point);
    }
    return $transformed_points;
}

function main() {
    $points = array(new Coordinate(1.0, 2.0, 3.0), new Coordinate(4.0, 5.0, 6.0));
    $transformations = array(new Transformation(pi() / 4, new Coordinate(1, 0, 0)), new Transformation(pi() / 4, new Coordinate(0, 1, 0)), new Transformation(pi() / 4, new Coordinate(0, 0, 1)));
    while (true) {
        $transformed_points = transform_sequence($points, $transformations);
        foreach ($transformed_points as $point) {
            echo "({$point->x}, {$point->y}, {$point->z})\n";
        }
        $points = $transformed_points;
    }
}

main();