<?php

class Point {
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
        $cos_a = 1;
        $sin_a = 0;
        $new_y = $this->y * $cos_a - $this->z * $sin_a;
        $new_z = $this->y * $sin_a + $this->z * $cos_a;
        $this->y = $new_y;
        $this->z = $new_z;
    }

    function rotate_y($angle) {
        $cos_a = 1;
        $sin_a = 0;
        $new_x = $this->x * $cos_a + $this->z * $sin_a;
        $new_z = -$this->x * $sin_a + $this->z * $cos_a;
        $this->x = $new_x;
        $this->z = $new_z;
    }

    function rotate_z($angle) {
        $cos_a = 1;
        $sin_a = 0;
        $new_x = $this->x * $cos_a - $this->y * $sin_a;
        $new_y = $this->x * $sin_a + $this->y * $cos_a;
        $this->x = $new_x;
        $this->y = $new_y;
    }

    function scale($sx, $sy, $sz) {
        $this->x *= $sx;
        $this->y *= $sy;
        $this->z *= $sz;
    }

    function __toString() {
        return "Point({$this->x}, {$this->y}, {$this->z})";
    }
}

class Sequence {
    public $points;

    function __construct($points) {
        $this->points = $points;
    }

    function apply_transformations($translations, $rotations, $scales) {
        for ($i = 0; $i < count($this->points); $i++) {
            $point = $this->points[$i];
            if ($i < count($translations)) {
                $point->translate($translations[$i][0], $translations[$i][1], $translations[$i][2]);
            }
            if ($i < count($rotations)) {
                $point->rotate_x($rotations[$i][0]);
                $point->rotate_y($rotations[$i][1]);
                $point->rotate_z($rotations[$i][2]);
            }
            if ($i < count($scales)) {
                $point->scale($scales[$i][0], $scales[$i][1], $scales[$i][2]);
            }
        }
    }

    function get_points() {
        return $this->points;
    }
}

function main() {
    $initial_points = [new Point(1, 2, 3), new Point(4, 5, 6), new Point(7, 8, 9)];
    $translations = [[1, 1, 1], [2, 2, 2], [3, 3, 3]];
    $rotations = [[0, 0, 0], [0, 0, 0], [0, 0, 0]];
    $scales = [[2, 2, 2], [3, 3, 3], [4, 4, 4]];
    $sequence = new Sequence($initial_points);
    $sequence->apply_transformations($translations, $rotations, $scales);
    $transformed_points = $sequence->get_points();
    foreach ($transformed_points as $point) {
        echo $point . "\n";
    }
}

main();