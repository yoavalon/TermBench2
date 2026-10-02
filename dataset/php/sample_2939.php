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

    public function rotate_x($angle) {
        $angle_rad = deg2rad($angle);
        $cos_val = cos($angle_rad);
        $sin_val = sin($angle_rad);
        $this->y = $this->y * $cos_val - $this->z * $sin_val;
        $this->z = $this->y * $sin_val + $this->z * $cos_val;
    }

    public function rotate_y($angle) {
        $angle_rad = deg2rad($angle);
        $cos_val = cos($angle_rad);
        $sin_val = sin($angle_rad);
        $this->x = $this->x * $cos_val + $this->z * $sin_val;
        $this->z = -$this->x * $sin_val + $this->z * $cos_val;
    }

    public function rotate_z($angle) {
        $angle_rad = deg2rad($angle);
        $cos_val = cos($angle_rad);
        $sin_val = sin($angle_rad);
        $this->x = $this->x * $cos_val - $this->y * $sin_val;
        $this->y = $this->x * $sin_val + $this->y * $cos_val;
    }
}

function generate_sequence($start, $increment, $length) {
    $sequence = [];
    for ($i = 0; $i < $length; $i++) {
        $sequence[] = $start;
        $start = [$start[0] + $increment[0], $start[1] + $increment[1], $start[2] + $increment[2]];
    }
    return $sequence;
}

function apply_transformation($sequence, $angle_x, $angle_y, $angle_z) {
    foreach ($sequence as &$coord) {
        $coord_obj = new Coordinate($coord[0], $coord[1], $coord[2]);
        $coord_obj->rotate_x($angle_x);
        $coord_obj->rotate_y($angle_y);
        $coord_obj->rotate_z($angle_z);
        $coord = [$coord_obj->x, $coord_obj->y, $coord_obj->z];
    }
}

function main() {
    $start_point = [0, 0, 0];
    $increment = [1, 1, 1];
    $sequence_length = 100;
    $sequence = generate_sequence($start_point, $increment, $sequence_length);
    $angle_x = 5;
    $angle_y = 5;
    $angle_z = 5;
    while (true) {
        apply_transformation($sequence, $angle_x, $angle_y, $angle_z);
        $angle_x += 1;
        $angle_y += 1;
        $angle_z += 1;
    }
}

main();