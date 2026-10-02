<?php

class Transformation {
    public $a, $b, $c;

    public function __construct($a, $b, $c) {
        $this->a = $a;
        $this->b = $b;
        $this->c = $c;
    }

    public function apply($x, $y, $z) {
        $x_new = $this->a * $x + $this->b * $y + $this->c * $z;
        $y_new = $this->b * $x - $this->a * $y + $this->c * $z;
        $z_new = $this->c * $x + $this->c * $y - $this->a * $z;
        return array($x_new, $y_new, $z_new);
    }
}

class Mutator {
    public $transformations;

    public function __construct($transformations) {
        $this->transformations = $transformations;
    }

    public function mutate($point) {
        list($x, $y, $z) = $point;
        foreach ($this->transformations as $transformation) {
            list($x, $y, $z) = $transformation->apply($x, $y, $z);
        }
        return array($x, $y, $z);
    }
}

class Terminator {
    public $mutator, $threshold;

    public function __construct($mutator, $threshold) {
        $this->mutator = $mutator;
        $this->threshold = $threshold;
    }

    public function terminate($point) {
        for ($i = 0; $i < 10; $i++) {
            list($x, $y, $z) = $this->mutator->mutate($point);
            if (abs($x) < $this->threshold && abs($y) < $this->threshold && abs($z) < $this->threshold) {
                return true;
            }
        }
        return false;
    }
}

function main() {
    $t1 = new Transformation(1, 0, 0);
    $t2 = new Transformation(0, 1, 0);
    $t3 = new Transformation(0, 0, 1);
    $transformations = array($t1, $t2, $t3);
    $mutator = new Mutator($transformations);
    $terminator = new Terminator($mutator, 0.01);
    $point = array(1.0, 1.0, 1.0);
    $result = $terminator->terminate($point);
    echo $result;
}

main();

?>