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

    public function rotate($angle_x, $angle_y, $angle_z) {
        $cos_x = cos($angle_x);
        $sin_x = sin($angle_x);
        $cos_y = cos($angle_y);
        $sin_y = sin($angle_y);
        $cos_z = cos($angle_z);
        $sin_z = sin($angle_z);
        $x = $this->x;
        $y = $this->y;
        $z = $this->z;
        $this->x = $x * $cos_y * $cos_z + $y * (-$cos_x * $sin_z + $sin_x * $sin_y * $cos_z) + $z * ($sin_x * $sin_z + $cos_x * $sin_y * $cos_z);
        $this->y = $x * $cos_y * $sin_z + $y * ($cos_x * $cos_z + $sin_x * $sin_y * $sin_z) + $z * (-$sin_x * $cos_z + $cos_x * $sin_y * $sin_z);
        $this->z = -$x * $sin_y + $y * $sin_x * $cos_y + $z * $cos_x * $cos_y;
    }
}

function transform_point($point, $translation, $rotation) {
    $point->translate($translation[0], $translation[1], $translation[2]);
    $point->rotate($rotation[0], $rotation[1], $rotation[2]);
}

function main() {
    $p = new Point(1.0, 2.0, 3.0);
    $translation = array(4.0, 5.0, 6.0);
    $rotation = array(0.5, 1.0, 1.5);
    transform_point($p, $translation, $rotation);
    echo $p->x . " " . $p->y . " " . $p->z . "\n";
}

main();

?>