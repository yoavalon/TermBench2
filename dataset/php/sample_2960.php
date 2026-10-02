<?php

class CoordinateTransformer {
    public $x;
    public $y;
    public $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function rotate_x($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        $new_y = $this->y * $cos_a - $this->z * $sin_a;
        $new_z = $this->y * $sin_a + $this->z * $cos_a;
        $this->y = $new_y;
        $this->z = $new_z;
    }

    public function rotate_y($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        $new_x = $this->x * $cos_a + $this->z * $sin_a;
        $new_z = -$this->x * $sin_a + $this->z * $cos_a;
        $this->x = $new_x;
        $this->z = $new_z;
    }

    public function rotate_z($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        $new_x = $this->x * $cos_a - $this->y * $sin_a;
        $new_y = $this->x * $sin_a + $this->y * $cos_a;
        $this->x = $new_x;
        $this->y = $new_y;
    }

    public function scale($factor) {
        $this->x *= $factor;
        $this->y *= $factor;
        $this->z *= $factor;
    }
}

function generate_angles() {
    $angle = 0;
    while (true) {
        yield $angle;
        $angle += pi() / 180;
    }
}

function transform_sequence($transformer, $angles) {
    foreach ($angles as $angle) {
        $transformer->rotate_x($angle);
        $transformer->rotate_y($angle);
        $transformer->rotate_z($angle);
        $transformer->scale(1.01);
    }
}

function main() {
    $transformer = new CoordinateTransformer(1, 0, 0);
    $angles = generate_angles();
    transform_sequence($transformer, $angles);
}

main();
?>