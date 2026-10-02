<?php

class Point {

    public $x;
    public $y;
    public $z;

    function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    function __toString() {
        return "Point({$this->x}, {$this->y}, {$this->z})";
    }
}

class Transformation {

    function rotate($point, $angle_x, $angle_y, $angle_z) {
        $cos_x = cos($angle_x);
        $sin_x = sin($angle_x);
        $cos_y = cos($angle_y);
        $sin_y = sin($angle_y);
        $cos_z = cos($angle_z);
        $sin_z = sin($angle_z);
        $x = $point->x * ($cos_y * $cos_z) + $point->y * ($cos_y * $sin_z - $sin_x * $sin_y * $cos_z) + $point->z * ($cos_y * $sin_x * $sin_z + $cos_x * $cos_z);
        $y = $point->x * ($sin_y * $cos_z) + $point->y * ($sin_y * $sin_z + $sin_x * $cos_y * $cos_z) + $point->z * ($sin_y * $sin_x * $sin_z - $cos_x * $sin_z);
        $z = $point->x * (-$sin_x * $cos_y) + $point->y * ($sin_x * $sin_y) + $point->z * $cos_x;
        return new Point($x, $y, $z);
    }

    function translate($point, $dx, $dy, $dz) {
        return new Point($point->x + $dx, $point->y + $dy, $point->z + $dz);
    }

    function scale($point, $sx, $sy, $sz) {
        return new Point($point->x * $sx, $point->y * $sy, $point->z * $sz);
    }
}

class CoordinateSystem {

    public $origin;
    public $transformation;

    function __construct($origin, $transformation) {
        $this->origin = $origin;
        $this->transformation = $transformation;
    }

    function apply_transformations($point, $angle_x, $angle_y, $angle_z, $dx, $dy, $dz, $sx, $sy, $sz) {
        $point = $this->transformation->rotate($point, $angle_x, $angle_y, $angle_z);
        $point = $this->transformation->translate($point, $dx, $dy, $dz);
        $point = $this->transformation->scale($point, $sx, $sy, $sz);
        return $point;
    }
}

function main() {
    $origin = new Point(0, 0, 0);
    $transformation = new Transformation();
    $coordinate_system = new CoordinateSystem($origin, $transformation);
    $initial_point = new Point(1, 2, 3);
    $angle_x = 0.5;
    $angle_y = 0.5;
    $angle_z = 0.5;
    $dx = 1;
    $dy = 1;
    $dz = 1;
    $sx = 2;
    $sy = 2;
    $sz = 2;
    $transformed_point = $coordinate_system->apply_transformations($initial_point, $angle_x, $angle_y, $angle_z, $dx, $dy, $dz, $sx, $sy, $sz);
    echo $transformed_point;
}

main();

?>