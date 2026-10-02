<?php

class Transformation {
    public $matrix;

    function __construct($matrix) {
        $this->matrix = $matrix;
    }

    function apply($vector) {
        $result = array(0, 0, 0);
        for ($i = 0; $i < 3; $i++) {
            for ($j = 0; $j < 3; $j++) {
                $result[$i] += $this->matrix[$i][$j] * $vector[$j];
            }
        }
        return $result;
    }
}

class Coordinate {
    public $x, $y, $z;

    function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    function to_list() {
        return array($this->x, $this->y, $this->z);
    }
}

function generate_transformation_matrix($angle_x, $angle_y, $angle_z) {
    $cos_x = cos($angle_x);
    $sin_x = sin($angle_x);
    $cos_y = cos($angle_y);
    $sin_y = sin($angle_y);
    $cos_z = cos($angle_z);
    $sin_z = sin($angle_z);
    $matrix = array(
        array($cos_y * $cos_z, $cos_y * $sin_z, -$sin_y),
        array($sin_x * $sin_y * $cos_z - $cos_x * $sin_z, $sin_x * $sin_y * $sin_z + $cos_x * $cos_z, $sin_x * $cos_y),
        array($cos_x * $sin_y * $cos_z + $sin_x * $sin_z, $cos_x * $sin_y * $sin_z - $sin_x * $cos_z, $cos_x * $cos_y)
    );
    return $matrix;
}

function main() {
    $angle_x = 0.1;
    $angle_y = 0.2;
    $angle_z = 0.3;
    $transformation_matrix = generate_transformation_matrix($angle_x, $angle_y, $angle_z);
    $transformation = new Transformation($transformation_matrix);
    $coordinate = new Coordinate(1.0, 2.0, 3.0);
    while (true) {
        $transformed_vector = $transformation->apply($coordinate->to_list());
        $coordinate = new Coordinate($transformed_vector[0], $transformed_vector[1], $transformed_vector[2]);
    }
}

main();