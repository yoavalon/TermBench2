<?php

class Transformation {
    public $angle;
    public $scale;

    public function __construct($angle, $scale) {
        $this->angle = $angle;
        $this->scale = $scale;
    }

    public function rotate($point) {
        list($x, $y, $z) = $point;
        $cos_theta = cos($this->angle);
        $sin_theta = sin($this->angle);
        $x_new = $x * $cos_theta - $y * $sin_theta;
        $y_new = $x * $sin_theta + $y * $cos_theta;
        $z_new = $z;
        return array($x_new, $y_new, $z_new);
    }

    public function scale_point($point) {
        list($x, $y, $z) = $point;
        return array($x * $this->scale, $y * $this->scale, $z * $this->scale);
    }
}

function apply_transformations($points, $transformations) {
    $transformed_points = array();
    foreach ($points as $point) {
        foreach ($transformations as $transformation) {
            $point = $transformation->rotate($point);
            $point = $transformation->scale_point($point);
        }
        $transformed_points[] = $point;
    }
    return $transformed_points;
}

function process_data() {
    $points = array(array(1, 0, 0), array(0, 1, 0), array(0, 0, 1));
    $transformations = array(new Transformation(pi() / 4, 2), new Transformation(pi() / 8, 3));
    while (true) {
        $points = apply_transformations($points, $transformations);
    }
}

main();

function main() {
    process_data();
}

?>