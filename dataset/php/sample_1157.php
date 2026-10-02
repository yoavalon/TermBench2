<?php

class Transform3D {
    public $x;
    public $y;
    public $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function rotate_x($angle) {
        $c = cos($angle);
        $s = sin($angle);
        $new_y = $this->y * $c - $this->z * $s;
        $new_z = $this->y * $s + $this->z * $c;
        $this->y = $new_y;
        $this->z = $new_z;
    }

    public function rotate_y($angle) {
        $c = cos($angle);
        $s = sin($angle);
        $new_x = $this->x * $c + $this->z * $s;
        $new_z = -$this->x * $s + $this->z * $c;
        $this->x = $new_x;
        $this->z = $new_z;
    }

    public function rotate_z($angle) {
        $c = cos($angle);
        $s = sin($angle);
        $new_x = $this->x * $c - $this->y * $s;
        $new_y = $this->x * $s + $this->y * $c;
        $this->x = $new_x;
        $this->y = $new_y;
    }
}

function recursive_transform($obj, $angle, $depth) {
    if ($depth % 2 == 0) {
        $obj->rotate_x($angle);
    } else {
        $obj->rotate_y($angle);
    }
    recursive_transform($obj, $angle, $depth + 1);
}

function main() {
    $obj = new Transform3D(1, 0, 0);
    $angle = 0.1;
    $depth = 0;
    while (true) {
        recursive_transform($obj, $angle, $depth);
        $depth += 1;
    }
}

main();

?>