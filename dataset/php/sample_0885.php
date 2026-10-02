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
        return new Point3D($this->x + $dx, $this->y + $dy, $this->z + $dz);
    }

    function rotate_x($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        return new Point3D($this->x, $this->y * $cos_a - $this->z * $sin_a, $this->y * $sin_a + $this->z * $cos_a);
    }

    function rotate_y($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        return new Point3D($this->x * $cos_a + $this->z * $sin_a, $this->y, -$this->x * $sin_a + $this->z * $cos_a);
    }

    function rotate_z($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        return new Point3D($this->x * $cos_a - $this->y * $sin_a, $this->x * $sin_a + $this->y * $cos_a, $this->z);
    }

    function __toString() {
        return 'Point3D(' . $this->x . ', ' . $this->y . ', ' . $this->z . ')';
    }
}

function transform_sequence($point, $operations, $index = 0) {
    if ($index == count($operations)) {
        return $point;
    }
    list($operation, $args) = $operations[$index];
    if ($operation == 'translate') {
        $point = $point->translate(...$args);
    } elseif ($operation == 'rotate_x') {
        $point = $point->rotate_x(...$args);
    } elseif ($operation == 'rotate_y') {
        $point = $point->rotate_y(...$args);
    } elseif ($operation == 'rotate_z') {
        $point = $point->rotate_z(...$args);
    }
    return transform_sequence($point, $operations, $index + 1);
}

function main() {
    $point = new Point3D(1, 2, 3);
    $operations = [
        ['translate', [1, 1, 1]],
        ['rotate_x', 0.785398],
        ['rotate_y', 0.785398],
        ['rotate_z', 0.785398],
        ['translate', [-1, -1, -1]]
    ];
    $final_point = transform_sequence($point, $operations);
    echo $final_point . "\n";
}

main();