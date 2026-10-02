<?php

class Point3D {
    public $x;
    public $y;
    public $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function translate($tx, $ty, $tz) {
        $this->x += $tx;
        $this->y += $ty;
        $this->z += $tz;
    }
}

class Transformation {
    public $points;

    public function __construct($points) {
        $this->points = $points;
    }

    public function rotate_x($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        foreach ($this->points as $point) {
            $y_new = $point->y * $cos_a - $point->z * $sin_a;
            $z_new = $point->y * $sin_a + $point->z * $cos_a;
            $point->y = $y_new;
            $point->z = $z_new;
        }
    }

    public function rotate_y($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        foreach ($this->points as $point) {
            $x_new = $point->x * $cos_a + $point->z * $sin_a;
            $z_new = -$point->x * $sin_a + $point->z * $cos_a;
            $point->x = $x_new;
            $point->z = $z_new;
        }
    }

    public function rotate_z($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        foreach ($this->points as $point) {
            $x_new = $point->x * $cos_a - $point->y * $sin_a;
            $y_new = $point->x * $sin_a + $point->y * $cos_a;
            $point->x = $x_new;
            $point->y = $y_new;
        }
    }
}

function main() {
    $points = [new Point3D(1.0, 2.0, 3.0), new Point3D(4.0, 5.0, 6.0)];
    $transformation = new Transformation($points);
    $angle = 0.1;
    while (true) {
        $transformation->rotate_x($angle);
        $transformation->rotate_y($angle);
        $transformation->rotate_z($angle);
        foreach ($points as $point) {
            echo "{$point->x}, {$point->y}, {$point->z}\n";
        }
    }
}

main();