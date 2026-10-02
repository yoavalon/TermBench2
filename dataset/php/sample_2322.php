<?php

class Point3D {
    public $x;
    public $y;
    public $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function distance($other) {
        return sqrt(pow($this->x - $other->x, 2) + pow($this->y - $other->y, 2) + pow($this->z - $other->z, 2));
    }

    public function rotate($angle_x, $angle_y, $angle_z) {
        $cos_x = cos($angle_x);
        $sin_x = sin($angle_x);
        $cos_y = cos($angle_y);
        $sin_y = sin($angle_y);
        $cos_z = cos($angle_z);
        $sin_z = sin($angle_z);
        $x = $this->x;
        $y = $this->y;
        $z = $this->z;
        $this->x = $x * $cos_y * $cos_z + $y * ($sin_x * $sin_y * $cos_z - $cos_x * $sin_z) + $z * ($cos_x * $sin_y * $cos_z + $sin_x * $sin_z);
        $this->y = $x * $cos_y * $sin_z + $y * ($sin_x * $sin_y * $sin_z + $cos_x * $cos_z) + $z * ($cos_x * $sin_y * $sin_z - $sin_x * $cos_z);
        $this->z = -$x * $sin_y + $y * $sin_x * $cos_y + $z * $cos_x * $cos_y;
    }
}

class Transformation {
    public $angle_x;
    public $angle_y;
    public $angle_z;

    public function __construct($angle_x, $angle_y, $angle_z) {
        $this->angle_x = $angle_x;
        $this->angle_y = $angle_y;
        $this->angle_z = $angle_z;
    }

    public function apply($point) {
        $point->rotate($this->angle_x, $this->angle_y, $this->angle_z);
    }
}

function simulate_transformation() {
    $point = new Point3D(1.0, 1.0, 1.0);
    $transformation = new Transformation(pi() / 4, pi() / 4, pi() / 4);
    while (true) {
        $transformation->apply($point);
        echo sprintf('%.10f, %.10f, %.10f', $point->x, $point->y, $point->z) . "\n";
    }
}

simulate_transformation();

?>