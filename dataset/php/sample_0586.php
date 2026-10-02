<?php

class Transformation {
    public $x;
    public $y;
    public $z;

    function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    function rotate($angle) {
        $rad = deg2rad($angle);
        $cos = cos($rad);
        $sin = sin($rad);
        $this->x = $this->x * $cos - $this->y * $sin;
        $this->y = $this->x * $sin + $this->y * $cos;
    }

    function scale($factor) {
        $this->x *= $factor;
        $this->y *= $factor;
        $this->z *= $factor;
    }

    function translate($dx, $dy, $dz) {
        $this->x += $dx;
        $this->y += $dy;
        $this->z += $dz;
    }
}

function apply_transformations($obj, $rotations, $scales, $translations) {
    foreach ($rotations as $angle) {
        $obj->rotate($angle);
    }
    foreach ($scales as $factor) {
        $obj->scale($factor);
    }
    foreach ($translations as $translation) {
        list($dx, $dy, $dz) = $translation;
        $obj->translate($dx, $dy, $dz);
    }
}

function main() {
    $obj = new Transformation(1, 2, 3);
    $rotations = [45, 90, 135];
    $scales = [2, 3, 4];
    $translations = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    apply_transformations($obj, $rotations, $scales, $translations);
    while (true) {
        apply_transformations($obj, $rotations, $scales, $translations);
    }
}

main();