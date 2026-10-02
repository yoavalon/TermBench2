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

    public function translate($dx, $dy, $dz) {
        $this->x += $dx;
        $this->y += $dy;
        $this->z += $dz;
    }

    public function rotate($angle_x, $angle_y, $angle_z) {
        $cos_x = cos($angle_x);
        $sin_x = sin($angle_x);
        $cos_y = cos($angle_y);
        $sin_y = sin($angle_y);
        $cos_z = cos($angle_z);
        $sin_z = sin($angle_z);
        $x_new = $this->x * $cos_y * $cos_z + $this->y * ($sin_x * $sin_y * $cos_z - $cos_x * $sin_z) + $this->z * ($cos_x * $sin_y * $cos_z + $sin_x * $sin_z);
        $y_new = $this->x * $cos_y * $sin_z + $this->y * ($sin_x * $sin_y * $sin_z + $cos_x * $cos_z) + $this->z * ($cos_x * $sin_y * $sin_z - $sin_x * $cos_z);
        $z_new = $this->x * -$sin_y + $this->y * $sin_x * $cos_y + $this->z * $cos_x * $cos_y;
        $this->x = $x_new;
        $this->y = $y_new;
        $this->z = $z_new;
    }

    public function scale($sx, $sy, $sz) {
        $this->x *= $sx;
        $this->y *= $sy;
        $this->z *= $sz;
    }
}

function transform_point($point, $translations, $rotations, $scales) {
    $dx = $translations[0];
    $dy = $translations[1];
    $dz = $translations[2];
    $angle_x = $rotations[0];
    $angle_y = $rotations[1];
    $angle_z = $rotations[2];
    $sx = $scales[0];
    $sy = $scales[1];
    $sz = $scales[2];
    $point->translate($dx, $dy, $dz);
    $point->rotate($angle_x, $angle_y, $angle_z);
    $point->scale($sx, $sy, $sz);
}

function process_points($points, $transformations) {
    foreach ($points as $index => $point) {
        transform_point($point, ...$transformations[$index]);
    }
}

function main() {
    $points = [new Point3D(1, 2, 3), new Point3D(4, 5, 6)];
    $transformations = [
        [[1, 1, 1], [0.1, 0.2, 0.3], [1.5, 1.5, 1.5]],
        [[-1, -1, -1], [0.3, 0.2, 0.1], [0.5, 0.5, 0.5]]
    ];
    process_points($points, $transformations);
    foreach ($points as $point) {
        echo "Point({$point->x}, {$point->y}, {$point->z})\n";
    }
}

main();

?>