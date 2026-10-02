<?php

class Point {
    public $x;
    public $y;
    public $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function translate($dx, $dy, $dz) {
        $this->x += $dx;
        $this->y += $dy;
        $this->z += $dz;
    }

    public function scale($sx, $sy, $sz) {
        $this->x *= $sx;
        $this->y *= $sy;
        $this->z *= $sz;
    }

    public function rotate_x($angle) {
        $cos_angle = cos($angle);
        $sin_angle = sin($angle);
        $this->y = $this->y * $cos_angle - $this->z * $sin_angle;
        $this->z = $this->y * $sin_angle + $this->z * $cos_angle;
    }

    public function rotate_y($angle) {
        $cos_angle = cos($angle);
        $sin_angle = sin($angle);
        $this->x = $this->x * $cos_angle + $this->z * $sin_angle;
        $this->z = -$this->x * $sin_angle + $this->z * $cos_angle;
    }

    public function rotate_z($angle) {
        $cos_angle = cos($angle);
        $sin_angle = sin($angle);
        $this->x = $this->x * $cos_angle - $this->y * $sin_angle;
        $this->y = $this->x * $sin_angle + $this->y * $cos_angle;
    }
}

class Transformation {
    public $points;

    public function __construct($points) {
        $this->points = $points;
    }

    public function apply_translation($dx, $dy, $dz) {
        foreach ($this->points as $point) {
            $point->translate($dx, $dy, $dz);
        }
    }

    public function apply_scale($sx, $sy, $sz) {
        foreach ($this->points as $point) {
            $point->scale($sx, $sy, $sz);
        }
    }

    public function apply_rotation_x($angle) {
        foreach ($this->points as $point) {
            $point->rotate_x($angle);
        }
    }

    public function apply_rotation_y($angle) {
        foreach ($this->points as $point) {
            $point->rotate_y($angle);
        }
    }

    public function apply_rotation_z($angle) {
        foreach ($this->points as $point) {
            $point->rotate_z($angle);
        }
    }
}

function main() {
    $points = [new Point(1, 2, 3), new Point(4, 5, 6), new Point(7, 8, 9)];
    $transformation = new Transformation($points);
    $transformation->apply_translation(1, 1, 1);
    $transformation->apply_scale(2, 2, 2);
    $transformation->apply_rotation_x(3.14159 / 4);
    $transformation->apply_rotation_y(3.14159 / 4);
    $transformation->apply_rotation_z(3.14159 / 4);
    foreach ($points as $point) {
        echo "({$point->x}, {$point->y}, {$point->z})\n";
    }
}

main();

?>