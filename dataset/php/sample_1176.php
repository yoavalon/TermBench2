<?php

class Point3D {
    public $x;
    public $y;
    public $z;

    function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    function translate($dx, $dy, $dz) {
        $this->x += $dx;
        $this->y += $dy;
        $this->z += $dz;
    }

    function rotate_x($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        $y = $this->y * $cos_a - $this->z * $sin_a;
        $z = $this->y * $sin_a + $this->z * $cos_a;
        $this->y = $y;
        $this->z = $z;
    }

    function rotate_y($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        $x = $this->x * $cos_a + $this->z * $sin_a;
        $z = -$this->x * $sin_a + $this->z * $cos_a;
        $this->x = $x;
        $this->z = $z;
    }

    function rotate_z($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        $x = $this->x * $cos_a - $this->y * $sin_a;
        $y = $this->x * $sin_a + $this->y * $cos_a;
        $this->x = $x;
        $this->y = $y;
    }
}

function transform_point($point, $angles, $translations) {
    $point->rotate_x($angles[0]);
    $point->rotate_y($angles[1]);
    $point->rotate_z($angles[2]);
    $point->translate($translations[0], $translations[1], $translations[2]);
}

function recursive_transform($point, $angles, $translations) {
    transform_point($point, $angles, $translations);
    recursive_transform($point, $angles, $translations);
}

function main() {
    $p = new Point3D(1, 0, 0);
    $a = [0.1, 0.2, 0.3];
    $t = [0.1, 0.1, 0.1];
    recursive_transform($p, $a, $t);
}

main();

?>