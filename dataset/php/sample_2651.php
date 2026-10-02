<?php

class Vector3D {
    public $x;
    public $y;
    public $z;

    function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    function add($other) {
        return new Vector3D($this->x + $other->x, $this->y + $other->y, $this->z + $other->z);
    }

    function subtract($other) {
        return new Vector3D($this->x - $other->x, $this->y - $other->y, $this->z - $other->z);
    }

    function scale($scalar) {
        return new Vector3D($this->x * $scalar, $this->y * $scalar, $this->z * $scalar);
    }

    function magnitude() {
        return sqrt($this->x ** 2 + $this->y ** 2 + $this->z ** 2);
    }
}

class Transformation {
    public $rotation_matrix;
    public $translation_vector;

    function __construct($rotation_matrix, $translation_vector) {
        $this->rotation_matrix = $rotation_matrix;
        $this->translation_vector = $translation_vector;
    }

    function apply($vector) {
        $x = $vector->x * $this->rotation_matrix[0][0] + $vector->y * $this->rotation_matrix[0][1] + $vector->z * $this->rotation_matrix[0][2];
        $y = $vector->x * $this->rotation_matrix[1][0] + $vector->y * $this->rotation_matrix[1][1] + $vector->z * $this->rotation_matrix[1][2];
        $z = $vector->x * $this->rotation_matrix[2][0] + $vector->y * $this->rotation_matrix[2][1] + $vector->z * $this->rotation_matrix[2][2];
        $translated_vector = new Vector3D($x, $y, $z)->add($this->translation_vector);
        return $translated_vector;
    }
}

function generate_sequence($start, $transformation, $steps) {
    $sequence = array();
    $current_vector = $start;
    for ($i = 0; $i < $steps; $i++) {
        array_push($sequence, $current_vector);
        $current_vector = $transformation->apply($current_vector);
    }
    return $sequence;
}

function main() {
    $start_vector = new Vector3D(1, 0, 0);
    $rotation_matrix = array(array(0, -1, 0), array(1, 0, 0), array(0, 0, 1));
    $translation_vector = new Vector3D(1, 1, 1);
    $transformation = new Transformation($rotation_matrix, $translation_vector);
    $sequence = generate_sequence($start_vector, $transformation, 10);
    foreach ($sequence as $vector) {
        echo "({$vector->x}, {$vector->y}, {$vector->z})\n";
    }
}

main();

?>