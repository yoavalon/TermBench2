<?php

class Point {
    public $x;
    public $y;
    public $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function distance($other) {
        return sqrt(pow($this->x - $other->x, 2) + pow($this->y - $other->y, 2) + pow($this->z - $other->z, 2));
    }
}

class Transformation {
    public $matrix;

    public function __construct($matrix) {
        $this->matrix = $matrix;
    }

    public function apply($point) {
        $x = $this->matrix[0][0] * $point->x + $this->matrix[0][1] * $point->y + $this->matrix[0][2] * $point->z + $this->matrix[0][3];
        $y = $this->matrix[1][0] * $point->x + $this->matrix[1][1] * $point->y + $this->matrix[1][2] * $point->z + $this->matrix[1][3];
        $z = $this->matrix[2][0] * $point->x + $this->matrix[2][1] * $point->y + $this->matrix[2][2] * $point->z + $this->matrix[2][3];
        return new Point($x, $y, $z);
    }
}

class Sequence {
    public $start_point;
    public $transformation;
    public $steps;

    public function __construct($start_point, $transformation, $steps) {
        $this->start_point = $start_point;
        $this->transformation = $transformation;
        $this->steps = $steps;
    }

    public function generate() {
        $points = array($this->start_point);
        $current = $this->start_point;
        for ($i = 0; $i < $this->steps; $i++) {
            $current = $this->transformation->apply($current);
            $points[] = $current;
        }
        return $points;
    }
}

function main() {
    $start = new Point(0, 0, 0);
    $matrix = array(array(1, 0, 0, 1), array(0, 1, 0, 1), array(0, 0, 1, 1), array(0, 0, 0, 1));
    $transform = new Transformation($matrix);
    $seq = new Sequence($start, $transform, 10);
    $points = $seq->generate();
    $distances = array();
    for ($i = 0; $i < count($points) - 1; $i++) {
        $distances[] = $points[$i]->distance($points[$i + 1]);
    }
    print_r($distances);
}

main();
?>