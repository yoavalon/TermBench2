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

    public function translate($dx, $dy, $dz) {
        return new Point($this->x + $dx, $this->y + $dy, $this->z + $dz);
    }

    public function rotate_x($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        return new Point($this->x, $this->y * $cos_a - $this->z * $sin_a, $this->y * $sin_a + $this->z * $cos_a);
    }

    public function rotate_y($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        return new Point($this->x * $cos_a + $this->z * $sin_a, $this->y, -$this->x * $sin_a + $this->z * $cos_a);
    }

    public function rotate_z($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        return new Point($this->x * $cos_a - $this->y * $sin_a, $this->x * $sin_a + $this->y * $cos_a, $this->z);
    }
}

function apply_transformations($point, $tx, $ty, $tz, $rx, $ry, $rz, $depth) {
    if ($depth == 0) {
        return $point;
    }
    $point = $point->translate($tx, $ty, $tz);
    $point = $point->rotate_x($rx);
    $point = $point->rotate_y($ry);
    $point = $point->rotate_z($rz);
    return apply_transformations($point, $tx, $ty, $tz, $rx, $ry, $rz, $depth - 1);
}

function main() {
    $point = new Point(0, 0, 0);
    $tx = 1;
    $ty = 1;
    $tz = 1;
    $rx = 0.5;
    $ry = 0.5;
    $rz = 0.5;
    $depth = 5;
    $final_point = apply_transformations($point, $tx, $ty, $tz, $rx, $ry, $rz, $depth);
    echo 'Final Point: (' . $final_point->x . ', ' . $final_point->y . ', ' . $final_point->z . ')';
}

main();

?>