<?php

class CoordinateTransform {
    public $x;
    public $y;
    public $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function rotate_x($angle) {
        $cos_val = cos($angle);
        $sin_val = sin($angle);
        $new_y = $this->y * $cos_val - $this->z * $sin_val;
        $new_z = $this->y * $sin_val + $this->z * $cos_val;
        $this->y = $new_y;
        $this->z = $new_z;
    }

    public function rotate_y($angle) {
        $cos_val = cos($angle);
        $sin_val = sin($angle);
        $new_x = $this->x * $cos_val + $this->z * $sin_val;
        $new_z = -$this->x * $sin_val + $this->z * $cos_val;
        $this->x = $new_x;
        $this->z = $new_z;
    }

    public function rotate_z($angle) {
        $cos_val = cos($angle);
        $sin_val = sin($angle);
        $new_x = $this->x * $cos_val - $this->y * $sin_val;
        $new_y = $this->x * $sin_val + $this->y * $cos_val;
        $this->x = $new_x;
        $this->y = $new_y;
    }
}

function main() {
    $coord = new CoordinateTransform(1.0, 2.0, 3.0);
    $angle = 0.1;
    while (true) {
        $coord->rotate_x($angle);
        $coord->rotate_y($angle);
        $coord->rotate_z($angle);
        echo 'New coordinates: (' . $coord->x . ', ' . $coord->y . ', ' . $coord->z . ")\n";
    }
}

main();

?>