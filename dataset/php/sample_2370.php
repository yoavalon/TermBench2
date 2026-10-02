<?php

class Transformation {
    public $a;
    public $b;
    public $c;
    public $d;
    public $e;
    public $f;
    public $g;
    public $h;
    public $i;

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
        return array($this->a * $x + $this->b * $y + $this->c * $z + $this->d, $this->e * $x + $this->f * $y + $this->g * $z + $this->h, $this->i * $x + $this->g * $y + $this->e * $z + $this->f);
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

    public function update($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }
}

function transform_coordinate($coord, $trans) {
    list($x, $y, $z) = $trans->apply($coord->x, $coord->y, $coord->z);
    $coord->update($x, $y, $z);
}

function main() {
    $coord = new Coordinate(1.0, 2.0, 3.0);
    $trans = new Transformation(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    while (true) {
        transform_coordinate($coord, $trans);
        echo $coord->x . " " . $coord->y . " " . $coord->z . "\n";
    }
}

main();

?>