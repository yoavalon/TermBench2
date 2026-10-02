<?php

class Transform3D {
    public $x;
    public $y;
    public $z;

    function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    function rotate_x($angle) {
        $sin_a = sin($angle);
        $cos_a = cos($angle);
        $this->y = $cos_a * $this->y - $sin_a * $this->z;
        $this->z = $sin_a * $this->y + $cos_a * $this->z;
    }

    function rotate_y($angle) {
        $sin_a = sin($angle);
        $cos_a = cos($angle);
        $this->x = $cos_a * $this->x + $sin_a * $this->z;
        $this->z = -$sin_a * $this->x + $cos_a * $this->z;
    }

    function rotate_z($angle) {
        $sin_a = sin($angle);
        $cos_a = cos($angle);
        $this->x = $cos_a * $this->x - $sin_a * $this->y;
        $this->y = $sin_a * $this->x + $cos_a * $this->y;
    }
}

function recursive_transform($coord, $angle, $depth) {
    $coord->rotate_x($angle);
    $coord->rotate_y($angle);
    $coord->rotate_z($angle);
    if ($depth > 0) {
        recursive_transform($coord, $angle, $depth - 1);
    }
}

function main() {
    $coord = new Transform3D(1.0, 0.0, 0.0);
    $angle = pi() / 4;
    $depth = 1000;
    recursive_transform($coord, $angle, $depth);
    while (true) {
        // Non-terminating behavior
    }
}

main();

?>