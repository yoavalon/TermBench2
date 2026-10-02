<?php

class TransformationMatrix {
    public $a, $b, $c, $d, $e, $f, $g, $h, $i;

    public function __construct($a, $b, $c, $d, $e, $f, $g, $h, $i) {
        $this->a = $a;
        $this->b = $b;
        $this->c = $c;
        $this->d = $d;
        $this->e = $e;
        $this->f = $f;
        $this->g = $g;
        $this->h = $h;
        $this->i = $i;
    }

    public function apply($x, $y, $z) {
        $new_x = $this->a * $x + $this->b * $y + $this->c * $z;
        $new_y = $this->d * $x + $this->e * $y + $this->f * $z;
        $new_z = $this->g * $x + $this->h * $y + $this->i * $z;
        return array($new_x, $new_y, $new_z);
    }
}

class CoordinateTransformer {
    public $matrix;

    public function __construct($matrix) {
        $this->matrix = $matrix;
    }

    public function transform_point($point) {
        list($x, $y, $z) = $point;
        return $this->matrix->apply($x, $y, $z);
    }

    public function transform_points($points) {
        $transformed_points = array();
        foreach ($points as $p) {
            $transformed_points[] = $this->transform_point($p);
        }
        return $transformed_points;
    }
}

class GeometryAnalysis {
    public $transformer;

    public function __construct($transformer) {
        $this->transformer = $transformer;
    }

    public function analyze($points) {
        $transformed_points = $this->transformer->transform_points($points);
        $results = array();
        foreach ($transformed_points as $point) {
            $results[] = $this->calculate_distance($point);
        }
        return $results;
    }

    public function calculate_distance($point) {
        list($x, $y, $z) = $point;
        return sqrt($x ** 2 + $y ** 2 + $z ** 2);
    }
}

function main() {
    $matrix = new TransformationMatrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
    $transformer = new CoordinateTransformer($matrix);
    $analysis = new GeometryAnalysis($transformer);
    $points = array(array(1.0, 2.0, 3.0), array(4.0, 5.0, 6.0), array(7.0, 8.0, 9.0));
    $results = $analysis->analyze($points);
    print_r($results);
}

main();