<?php

class Vector {
    public $x;
    public $y;
    public $z;

    function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    function add($other) {
        return new Vector($this->x + $other->x, $this->y + $other->y, $this->z + $other->z);
    }

    function scale($factor) {
        return new Vector($this->x * $factor, $this->y * $factor, $this->z * $factor);
    }

    function __toString() {
        return 'Vector(' . $this->x . ', ' . $this->y . ', ' . $this->z . ')';
    }
}

class Matrix {
    public $a11, $a12, $a13;
    public $a21, $a22, $a23;
    public $a31, $a32, $a33;

    function __construct($a11, $a12, $a13, $a21, $a22, $a23, $a31, $a32, $a33) {
        $this->a11 = $a11;
        $this->a12 = $a12;
        $this->a13 = $a13;
        $this->a21 = $a21;
        $this->a22 = $a22;
        $this->a23 = $a23;
        $this->a31 = $a31;
        $this->a32 = $a32;
        $this->a33 = $a33;
    }

    function multiply($vector) {
        $x = $this->a11 * $vector->x + $this->a12 * $vector->y + $this->a13 * $vector->z;
        $y = $this->a21 * $vector->x + $this->a22 * $vector->y + $this->a23 * $vector->z;
        $z = $this->a31 * $vector->x + $this->a32 * $vector->y + $this->a33 * $vector->z;
        return new Vector($x, $y, $z);
    }

    function __toString() {
        return 'Matrix(' . $this->a11 . ', ' . $this->a12 . ', ' . $this->a13 . ', ' . $this->a21 . ', ' . $this->a22 . ', ' . $this->a23 . ', ' . $this->a31 . ', ' . $this->a32 . ', ' . $this->a33 . ')';
    }
}

function transform_vector($matrix, $vector, $depth) {
    if ($depth == 0) {
        return $vector;
    }
    $transformed = $matrix->multiply($vector);
    return transform_vector($matrix, $transformed, $depth - 1);
}

function main() {
    $vector = new Vector(1, 2, 3);
    $matrix = new Matrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
    $depth = 5;
    $result = transform_vector($matrix, $vector, $depth);
    echo $result;
}

main();

?>