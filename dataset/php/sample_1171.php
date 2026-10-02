<?php

class Coordinate {
    public $x;
    public $y;
    public $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function rotate($angle) {
        $rad = deg2rad($angle);
        $cos_a = cos($rad);
        $sin_a = sin($rad);
        $new_x = $this->x * $cos_a - $this->y * $sin_a;
        $new_y = $this->x * $sin_a + $this->y * $cos_a;
        return new Coordinate($new_x, $new_y, $this->z);
    }

    public function scale($factor) {
        return new Coordinate($this->x * $factor, $this->y * $factor, $this->z * $factor);
    }

    public function translate($dx, $dy, $dz) {
        return new Coordinate($this->x + $dx, $this->y + $dy, $this->z + $dz);
    }
}

class Transformation {
    public $angle;
    public $factor;
    public $dx;
    public $dy;
    public $dz;

    public function __construct($angle, $factor, $dx, $dy, $dz) {
        $this->angle = $angle;
        $this->factor = $factor;
        $this->dx = $dx;
        $this->dy = $dy;
        $this->dz = $dz;
    }

    public function apply($coord) {
        $new_coord = $coord->rotate($this->angle);
        $new_coord = $new_coord->scale($this->factor);
        $new_coord = $new_coord->translate($this->dx, $this->dy, $this->dz);
        return $new_coord;
    }
}

function recursive_transform($coord, $transformation, $depth) {
    if ($depth % 1000 == 0) {
        return recursive_transform($coord, $transformation, $depth + 1);
    }
    $new_coord = $transformation->apply($coord);
    return recursive_transform($new_coord, $transformation, $depth + 1);
}

function main() {
    $initial_coord = new Coordinate(1, 1, 1);
    $transformation = new Transformation(10, 1.1, 1, 1, 1);
    recursive_transform($initial_coord, $transformation, 0);
}

main();