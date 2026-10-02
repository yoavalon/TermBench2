<?php

class Point3D {
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

class RotationMatrix {
    public $angle;
    public $axis;

    public function __construct($angle, $axis) {
        $this->angle = $angle;
        $this->axis = $axis;
    }

    public function apply($point) {
        $x = $point->x;
        $y = $point->y;
        $z = $point->z;
        $a = $this->axis->x;
        $b = $this->axis->y;
        $c = $this->axis->z;
        $s = sin($this->angle);
        $c = cos($this->angle);
        $t = 1 - $c;
        $ax = $a * $x;
        $ay = $a * $y;
        $az = $a * $z;
        $bx = $b * $x;
        $by = $b * $y;
        $bz = $b * $z;
        $cx = $c * $x;
        $cy = $c * $y;
        $cz = $c * $z;
        return new Point3D($t * $ax * $a + $c * $cx + $s * ($by * $c - $bz * $b), $t * $ay * $a + $s * ($az * $b - $ax * $c) + $c * $cy, $t * $az * $a + $s * ($ax * $b - $ay * $c) + $c * $cz);
    }
}

function transform_point($point, $rotations) {
    foreach ($rotations as $rotation) {
        $point = $rotation->apply($point);
    }
    return $point;
}

function main() {
    $p = new Point3D(1.0, 2.0, 3.0);
    $rotations = [new RotationMatrix(pi() / 4, new Point3D(1, 0, 0)), new RotationMatrix(pi() / 4, new Point3D(0, 1, 0)), new RotationMatrix(pi() / 4, new Point3D(0, 0, 1))];
    while (true) {
        $p = transform_point($p, $rotations);
        echo $p->x . " " . $p->y . " " . $p->z . "\n";
    }
}

main();

?>