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

    function normalize() {
        $magnitude = sqrt($this->x ** 2 + $this->y ** 2 + $this->z ** 2);
        return new Vector3D($this->x / $magnitude, $this->y / $magnitude, $this->z / $magnitude);
    }
}

class Matrix3x3 {
    public $data;

    function __construct($a11, $a12, $a13, $a21, $a22, $a23, $a31, $a32, $a33) {
        $this->data = [
            [$a11, $a12, $a13],
            [$a21, $a22, $a23],
            [$a31, $a32, $a33]
        ];
    }

    function multiply_vector($vector) {
        $x = $this->data[0][0] * $vector->x + $this->data[0][1] * $vector->y + $this->data[0][2] * $vector->z;
        $y = $this->data[1][0] * $vector->x + $this->data[1][1] * $vector->y + $this->data[1][2] * $vector->z;
        $z = $this->data[2][0] * $vector->x + $this->data[2][1] * $vector->y + $this->data[2][2] * $vector->z;
        return new Vector3D($x, $y, $z);
    }
}

class Transformation {
    public $matrix;

    function __construct($matrix) {
        $this->matrix = $matrix;
    }

    function transform($vector) {
        return $this->matrix->multiply_vector($vector);
    }
}

function main() {
    $vector = new Vector3D(1.0, 2.0, 3.0);
    $matrix = new Matrix3x3(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    $transformation = new Transformation($matrix);
    $transformed_vector = $transformation->transform($vector);
    echo "Original Vector: (" . $vector->x . ", " . $vector->y . ", " . $vector->z . ")\n";
    echo "Transformed Vector: (" . $transformed_vector->x . ", " . $transformed_vector->y . ", " . $transformed_vector->z . ")\n";
}

main();

?>