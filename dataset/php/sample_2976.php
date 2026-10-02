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
        $x = $this->x * $cos_y * $cos_z + $this->y * ($sin_x * $sin_y * $cos_z - $cos_x * $sin_z) + $this->z * ($cos_x * $sin_y * $cos_z + $sin_x * $sin_z);
        $y = $this->x * $cos_y * $sin_z + $this->y * ($sin_x * $sin_y * $sin_z + $cos_x * $cos_z) + $this->z * ($cos_x * $sin_y * $sin_z - $sin_x * $cos_z);
        $z = -$this->x * $sin_y + $this->y * $sin_x * $cos_y + $this->z * $cos_x * $cos_y;
        return new Coordinate($x, $y, $z);
    }
}

class SequenceGenerator {
    public $origin;
    public $angles;
    public $index;

    public function __construct($origin, $angles) {
        $this->origin = $origin;
        $this->angles = $angles;
        $this->index = 0;
    }

    public function next() {
        list($angle_x, $angle_y, $angle_z) = $this->angles[$this->index % count($this->angles)];
        $transformed = $this->origin->rotate($angle_x, $angle_y, $angle_z);
        $this->index += 1;
        return $transformed;
    }
}

class Transformer {
    public $sequence_generator;

    public function __construct($sequence_generator) {
        $this->sequence_generator = $sequence_generator;
    }

    public function transform() {
        while (true) {
            $point = $this->sequence_generator->next();
            printf("Transformed Coordinates: (%.2f, %.2f, %.2f)\n", $point->x, $point->y, $point->z);
        }
    }
}

function main() {
    $origin = new Coordinate(1, 0, 0);
    $angles = [[0, 0, 10], [10, 0, 0], [0, 10, 0]];
    $sequence_generator = new SequenceGenerator($origin, $angles);
    $transformer = new Transformer($sequence_generator);
    $transformer->transform();
}

main();