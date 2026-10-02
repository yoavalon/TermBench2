<?php

class Transformer {
    public $matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];

    public function apply_transformation($point) {
        $x = $point[0];
        $y = $point[1];
        $z = $point[2];
        $new_x = $this->matrix[0][0] * $x + $this->matrix[0][1] * $y + $this->matrix[0][2] * $z;
        $new_y = $this->matrix[1][0] * $x + $this->matrix[1][1] * $y + $this->matrix[1][2] * $z;
        $new_z = $this->matrix[2][0] * $x + $this->matrix[2][1] * $y + $this->matrix[2][2] * $z;
        return [$new_x, $new_y, $new_z];
    }

    public function rotate_x($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        $this->matrix = [[1, 0, 0], [0, $cos_a, -$sin_a], [0, $sin_a, $cos_a]];
    }

    public function rotate_y($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        $this->matrix = [[$cos_a, 0, $sin_a], [0, 1, 0], [-$sin_a, 0, $cos_a]];
    }

    public function rotate_z($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        $this->matrix = [[$cos_a, -$sin_a, 0], [$sin_a, $cos_a, 0], [0, 0, 1]];
    }
}

class SequenceGenerator {
    public $transformer;
    public $current_point = [1, 0, 0];

    public function __construct($transformer) {
        $this->transformer = $transformer;
    }

    public function generate_sequence() {
        while (true) {
            yield $this->current_point;
            $this->current_point = $this->transformer->apply_transformation($this->current_point);
        }
    }
}

function main() {
    $transformer = new Transformer();
    $transformer->rotate_x(0.1);
    $transformer->rotate_y(0.1);
    $transformer->rotate_z(0.1);
    $generator = new SequenceGenerator($transformer);
    foreach ($generator->generate_sequence() as $point) {
        print_r($point);
    }
}

main();

?>