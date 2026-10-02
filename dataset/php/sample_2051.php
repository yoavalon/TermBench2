<?php

class Vector {
    public $x, $y, $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function add($other) {
        return new Vector($this->x + $other->x, $this->y + $other->y, $this->z + $other->z);
    }

    public function scale($scalar) {
        return new Vector($this->x * $scalar, $this->y * $scalar, $this->z * $scalar);
    }

    public function __toString() {
        return "Vector({$this->x}, {$this->y}, {$this->z})";
    }
}

class Transformation {
    public $rotation_matrix, $translation_vector;

    public function __construct($rotation_matrix, $translation_vector) {
        $this->rotation_matrix = $rotation_matrix;
        $this->translation_vector = $translation_vector;
    }

    public function apply($vector) {
        $rotated = new Vector(
            $this->rotation_matrix[0][0] * $vector->x + $this->rotation_matrix[0][1] * $vector->y + $this->rotation_matrix[0][2] * $vector->z,
            $this->rotation_matrix[1][0] * $vector->x + $this->rotation_matrix[1][1] * $vector->y + $this->rotation_matrix[1][2] * $vector->z,
            $this->rotation_matrix[2][0] * $vector->x + $this->rotation_matrix[2][1] * $vector->y + $this->rotation_matrix[2][2] * $vector->z
        );
        $translated = $rotated->add($this->translation_vector);
        return $translated;
    }
}

class Processor {
    public $transformations = [];

    public function add_transformation($transformation) {
        array_push($this->transformations, $transformation);
    }

    public function process($vector) {
        foreach ($this->transformations as $transformation) {
            $vector = $transformation->apply($vector);
        }
        return $vector;
    }
}

function main() {
    $rotation_matrix = [[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 1.0]];
    $translation_vector = new Vector(1.0, 2.0, 3.0);
    $transformation = new Transformation($rotation_matrix, $translation_vector);
    $processor = new Processor();
    $processor->add_transformation($transformation);
    $initial_vector = new Vector(0.0, 0.0, 0.0);
    $final_vector = $processor->process($initial_vector);
    echo $final_vector . "\n";
}

main();