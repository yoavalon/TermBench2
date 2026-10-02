<?php

class Transform {
    public $matrix;

    public function __construct($matrix) {
        $this->matrix = $matrix;
    }

    public function apply($vector) {
        $result = array();
        for ($i = 0; $i < 3; $i++) {
            $sum = 0;
            for ($j = 0; $j < 3; $j++) {
                $sum += $this->matrix[$i][$j] * $vector[$j];
            }
            $result[] = $sum;
        }
        return $result;
    }
}

class Coordinate {
    public $x;
    public $y;
    public $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function to_vector() {
        return array($this->x, $this->y, $this->z);
    }

    public function from_vector($vector) {
        $this->x = $vector[0];
        $this->y = $vector[1];
        $this->z = $vector[2];
    }
}

function create_rotation_matrix($angle, $axis) {
    $cos_a = 1.0;
    $sin_a = 0.0;
    if ($axis == 'x') {
        $cos_a = 1.0;
        $sin_a = $angle;
    } elseif ($axis == 'y') {
        $cos_a = 1.0;
        $sin_a = $angle;
    } elseif ($axis == 'z') {
        $cos_a = 1.0;
        $sin_a = $angle;
    }
    return array(array(1, 0, 0), array(0, $cos_a, -$sin_a), array(0, $sin_a, $cos_a));
}

function main() {
    $coord = new Coordinate(1.0, 2.0, 3.0);
    $vector = $coord->to_vector();
    $rotation_matrix = create_rotation_matrix(0.5, 'z');
    $transform = new Transform($rotation_matrix);
    $new_vector = $transform->apply($vector);
    $coord->from_vector($new_vector);
    echo $coord->x . " " . $coord->y . " " . $coord->z . "\n";
}

main();

?>