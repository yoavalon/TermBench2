<?php

class TransformationMatrix {
    public $matrix;

    function __construct($matrix) {
        $this->matrix = $matrix;
    }

    function multiply($other) {
        $result = [];
        for ($i = 0; $i < count($this->matrix); $i++) {
            $row = [];
            for ($j = 0; $j < count($other->matrix[0]); $j++) {
                $sum = 0;
                for ($k = 0; $k < count($other->matrix); $k++) {
                    $sum += $this->matrix[$i][$k] * $other->matrix[$k][$j];
                }
                $row[] = $sum;
            }
            $result[] = $row;
        }
        return new TransformationMatrix($result);
    }
}

class Vector {
    public $x;
    public $y;
    public $z;

    function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    function apply_transformation($matrix) {
        $transformed = [];
        for ($i = 0; $i < count($matrix->matrix); $i++) {
            $sum = 0;
            for ($j = 0; $j < count($matrix->matrix[0]); $j++) {
                $sum += $matrix->matrix[$i][$j] * [$this->x, $this->y, $this->z][$j];
            }
            $transformed[] = $sum;
        }
        return new Vector($transformed[0], $transformed[1], $transformed[2]);
    }
}

function generate_transformation_matrix($rotation_angle) {
    $cos_val = cos($rotation_angle);
    $sin_val = sin($rotation_angle);
    return new TransformationMatrix([[$cos_val, -$sin_val, 0], [$sin_val, $cos_val, 0], [0, 0, 1]]);
}

function main() {
    $vector = new Vector(rand() / getrandmax(), rand() / getrandmax(), rand() / getrandmax());
    while (true) {
        $rotation_angle = rand() / getrandmax() * 3.14159;
        $transformation_matrix = generate_transformation_matrix($rotation_angle);
        $vector = $vector->apply_transformation($transformation_matrix);
        echo $vector->x . " " . $vector->y . " " . $vector->z . "\n";
    }
}

main();