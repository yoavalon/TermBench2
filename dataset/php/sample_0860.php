<?php

class Transformation {

    public $matrix;

    public function __construct($matrix) {
        $this->matrix = $matrix;
    }

    public function apply($point) {
        list($x, $y, $z) = $point;
        $new_x = $this->matrix[0][0] * $x + $this->matrix[0][1] * $y + $this->matrix[0][2] * $z + $this->matrix[0][3];
        $new_y = $this->matrix[1][0] * $x + $this->matrix[1][1] * $y + $this->matrix[1][2] * $z + $this->matrix[1][3];
        $new_z = $this->matrix[2][0] * $x + $this->matrix[2][1] * $y + $this->matrix[2][2] * $z + $this->matrix[2][3];
        return array($new_x, $new_y, $new_z);
    }
}

class Point {

    public $x;
    public $y;
    public $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function transform($matrix) {
        $transformed = (new Transformation($matrix))->apply(array($this->x, $this->y, $this->z));
        return new Point($transformed[0], $transformed[1], $transformed[2]);
    }
}

function recursive_transform($point, $matrix, $depth) {
    if ($depth == 0) {
        return $point;
    } else {
        $new_point = $point->transform($matrix);
        return recursive_transform($new_point, $matrix, $depth - 1);
    }
}

function main() {
    $matrix = array(array(1, 0, 0, 1), array(0, 1, 0, 1), array(0, 0, 1, 1), array(0, 0, 0, 1));
    $initial_point = new Point(0, 0, 0);
    $depth = 5;
    $result = recursive_transform($initial_point, $matrix, $depth);
    echo 'Transformed point: (' . $result->x . ', ' . $result->y . ', ' . $result->z . ')';
}

main();