<?php

class Vector3D {
    public $x;
    public $y;
    public $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function add($other) {
        return new Vector3D($this->x + $other->x, $this->y + $other->y, $this->z + $other->z);
    }

    public function scale($scalar) {
        return new Vector3D($this->x * $scalar, $this->y * $scalar, $this->z * $scalar);
    }

    public function __toString() {
        return "Vector3D({$this->x}, {$this->y}, {$this->z})";
    }
}

class Transformation {
    public $matrix;

    public function __construct($matrix) {
        $this->matrix = $matrix;
    }

    public function apply($vector) {
        $x = $this->matrix[0][0] * $vector->x + $this->matrix[0][1] * $vector->y + $this->matrix[0][2] * $vector->z;
        $y = $this->matrix[1][0] * $vector->x + $this->matrix[1][1] * $vector->y + $this->matrix[1][2] * $vector->z;
        $z = $this->matrix[2][0] * $vector->x + $this->matrix[2][1] * $vector->y + $this->matrix[2][2] * $vector->z;
        return new Vector3D($x, $y, $z);
    }
}

function transform_sequence($vector, $transformations, $index) {
    if ($index >= count($transformations)) {
        return $vector;
    }
    $current_transformation = $transformations[$index];
    $transformed_vector = $current_transformation->apply($vector);
    return transform_sequence($transformed_vector, $transformations, $index + 1);
}

function main() {
    $vector = new Vector3D(1, 2, 3);
    $transformation1 = new Transformation([[1, 0, 0], [0, 2, 0], [0, 0, 3]]);
    $transformation2 = new Transformation([[0, 0, 1], [1, 0, 0], [0, 1, 0]]);
    $transformations = [$transformation1, $transformation2];
    $final_vector = transform_sequence($vector, $transformations, 0);
    echo $final_vector . "\n";
}

main();