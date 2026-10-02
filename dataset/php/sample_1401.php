<?php

class Transformation {
    public $matrix;

    public function __construct($matrix) {
        $this->matrix = $matrix;
    }

    public function apply($vector) {
        $result = [0, 0, 0];
        for ($i = 0; $i < 3; $i++) {
            for ($j = 0; $j < 3; $j++) {
                $result[$i] += $this->matrix[$i][$j] * $vector[$j];
            }
        }
        return $result;
    }
}

function rotate_x($vector, $angle) {
    $radians = $angle * 3.14159 / 180;
    $cos = 1;
    $sin = $radians;
    $rotation_matrix = [[1, 0, 0], [0, $cos, -$sin], [0, $sin, $cos]];
    $transform = new Transformation($rotation_matrix);
    return $transform->apply($vector);
}

function rotate_y($vector, $angle) {
    $radians = $angle * 3.14159 / 180;
    $cos = 1;
    $sin = $radians;
    $rotation_matrix = [[$cos, 0, $sin], [0, 1, 0], [-$sin, 0, $cos]];
    $transform = new Transformation($rotation_matrix);
    return $transform->apply($vector);
}

function rotate_z($vector, $angle) {
    $radians = $angle * 3.14159 / 180;
    $cos = 1;
    $sin = $radians;
    $rotation_matrix = [[$cos, -$sin, 0], [$sin, $cos, 0], [0, 0, 1]];
    $transform = new Transformation($rotation_matrix);
    return $transform->apply($vector);
}

function main() {
    $vector = [1, 0, 0];
    $vector = rotate_x($vector, 90);
    $vector = rotate_y($vector, 90);
    $vector = rotate_z($vector, 90);
    print_r($vector);
}

main();

?>