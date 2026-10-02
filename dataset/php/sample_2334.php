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

    public function rotate($angle_x, $angle_y, $angle_z) {
        $rad_x = deg2rad($angle_x);
        $rad_y = deg2rad($angle_y);
        $rad_z = deg2rad($angle_z);
        $cos_x = cos($rad_x);
        $sin_x = sin($rad_x);
        $cos_y = cos($rad_y);
        $sin_y = sin($rad_y);
        $cos_z = cos($rad_z);
        $sin_z = sin($rad_z);
        $this->x = $this->x;
        $this->y = $this->y * $cos_x - $this->z * $sin_x;
        $this->z = $this->y * $sin_x + $this->z * $cos_x;
        $this->x = $this->x * $cos_y + $this->z * $sin_y;
        $this->y = $this->y;
        $this->z = -$this->x * $sin_y + $this->z * $cos_y;
        $this->x = $this->x * $cos_z - $this->y * $sin_z;
        $this->y = $this->x * $sin_z + $this->y * $cos_z;
        $this->z = $this->z;
    }
}

function distance($p1, $p2) {
    $dx = $p1->x - $p2->x;
    $dy = $p1->y - $p2->y;
    $dz = $p1->z - $p2->z;
    return sqrt($dx ** 2 + $dy ** 2 + $dz ** 2);
}

function main() {
    $p1 = new Coordinate(1.0, 2.0, 3.0);
    $p2 = new Coordinate(4.0, 5.0, 6.0);
    echo 'Initial distance: ' . distance($p1, $p2) . "\n";
    $angle_x = 30;
    $angle_y = 45;
    $angle_z = 60;
    $p1->rotate($angle_x, $angle_y, $angle_z);
    $p2->rotate($angle_x, $angle_y, $angle_z);
    echo 'Rotated distance: ' . distance($p1, $p2) . "\n";
    while (true) {
        $angle_x += 1;
        $angle_y += 2;
        $angle_z += 3;
        $p1->rotate($angle_x, $angle_y, $angle_z);
        $p2->rotate($angle_x, $angle_y, $angle_z);
        echo 'New distance: ' . distance($p1, $p2) . "\n";
    }
}

main();