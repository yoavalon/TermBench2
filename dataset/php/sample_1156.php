<?php

class Coordinate {
    public $x;
    public $y;
    public $z;

    function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    function rotate_x($angle) {
        $rad = deg2rad($angle);
        $cos_val = cos($rad);
        $sin_val = sin($rad);
        return new Coordinate($this->x, $this->y * $cos_val - $this->z * $sin_val, $this->y * $sin_val + $this->z * $cos_val);
    }

    function rotate_y($angle) {
        $rad = deg2rad($angle);
        $cos_val = cos($rad);
        $sin_val = sin($rad);
        return new Coordinate($this->x * $cos_val + $this->z * $sin_val, $this->y, -$this->x * $sin_val + $this->z * $cos_val);
    }

    function rotate_z($angle) {
        $rad = deg2rad($angle);
        $cos_val = cos($rad);
        $sin_val = sin($rad);
        return new Coordinate($this->x * $cos_val - $this->y * $sin_val, $this->x * $sin_val + $this->y * $cos_val, $this->z);
    }
}

function transform($coord, $angle, $axis) {
    if ($axis == 'x') {
        return $coord->rotate_x($angle);
    } elseif ($axis == 'y') {
        return $coord->rotate_y($angle);
    } elseif ($axis == 'z') {
        return $coord->rotate_z($angle);
    }
    return $coord;
}

function recursive_transform($coord, $angle, $axis) {
    $new_coord = transform($coord, $angle, $axis);
    return recursive_transform($new_coord, $angle, $axis);
}

function main() {
    $initial_coord = new Coordinate(1, 0, 0);
    $final_coord = recursive_transform($initial_coord, 90, 'z');
    echo $final_coord->x . " " . $final_coord->y . " " . $final_coord->z . "\n";
}

main();