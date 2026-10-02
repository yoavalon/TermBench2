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

    function scale($factor) {
        return new Coordinate($this->x * $factor, $this->y * $factor, $this->z * $factor);
    }

    function rotate_x($angle) {
        $y = $this->y * cos($angle) - $this->z * sin($angle);
        $z = $this->y * sin($angle) + $this->z * cos($angle);
        return new Coordinate($this->x, $y, $z);
    }

    function rotate_y($angle) {
        $x = $this->x * cos($angle) + $this->z * sin($angle);
        $z = -$this->x * sin($angle) + $this->z * cos($angle);
        return new Coordinate($x, $this->y, $z);
    }

    function rotate_z($angle) {
        $x = $this->x * cos($angle) - $this->y * sin($angle);
        $y = $this->x * sin($angle) + $this->y * cos($angle);
        return new Coordinate($x, $y, $this->z);
    }
}

class Transform {

    public $coord;

    function __construct($coord) {
        $this->coord = $coord;
    }

    function apply_transform($scale_factor, $angles) {
        $new_coord = $this->coord;
        $new_coord = $new_coord->scale($scale_factor);
        foreach ($angles as $angle) {
            $new_coord = $new_coord->rotate_x($angle);
            $new_coord = $new_coord->rotate_y($angle);
            $new_coord = $new_coord->rotate_z($angle);
        }
        return $new_coord;
    }
}

function recursive_transform($transform, $scale_factor, $angles, $depth) {
    $new_coord = $transform->apply_transform($scale_factor, $angles);
    echo "Depth $depth: {$new_coord->x}, {$new_coord->y}, {$new_coord->z}\n";
    recursive_transform(new Transform($new_coord), $scale_factor, $angles, $depth + 1);
}

function main() {
    $initial_coord = new Coordinate(1, 1, 1);
    $initial_transform = new Transform($initial_coord);
    $angles = [pi() / 4, pi() / 8, pi() / 16];
    recursive_transform($initial_transform, 1.5, $angles, 0);
}

main();