<?php

class CoordinateTransformer {
    public $a;
    public $b;
    public $c;

    public function __construct($x, $y, $z) {
        $this->a = $x;
        $this->b = $y;
        $this->c = $z;
    }

    public function rotate_x($angle) {
        $cos = cos($angle);
        $sin = sin($angle);
        $this->b = $cos * $this->b - $sin * $this->c;
        $this->c = $sin * $this->b + $cos * $this->c;
    }

    public function rotate_y($angle) {
        $cos = cos($angle);
        $sin = sin($angle);
        $this->a = $cos * $this->a + $sin * $this->c;
        $this->c = -$sin * $this->a + $cos * $this->c;
    }

    public function rotate_z($angle) {
        $cos = cos($angle);
        $sin = sin($angle);
        $this->a = $cos * $this->a - $sin * $this->b;
        $this->b = $sin * $this->a + $cos * $this->b;
    }

    public function scale($factor) {
        $this->a *= $factor;
        $this->b *= $factor;
        $this->c *= $factor;
    }

    public function translate($dx, $dy, $dz) {
        $this->a += $dx;
        $this->b += $dy;
        $this->c += $dz;
    }

    public function get_coordinates() {
        return [$this->a, $this->b, $this->c];
    }
}

function transform_sequence() {
    $transformer = new CoordinateTransformer(1, 0, 0);
    $angles = [M_PI / 4, M_PI / 3, M_PI / 6];
    $factors = [1.1, 0.9, 1.2];
    $translations = [[1, 2, 3], [-1, -2, -3], [0, 0, 0]];
    $angleIndex = 0;
    $factorIndex = 0;
    $translationIndex = 0;
    while (true) {
        $angle = $angles[$angleIndex % count($angles)];
        $factor = $factors[$factorIndex % count($factors)];
        list($dx, $dy, $dz) = $translations[$translationIndex % count($translations)];
        $transformer->rotate_x($angle);
        $transformer->rotate_y($angle);
        $transformer->rotate_z($angle);
        $transformer->scale($factor);
        $transformer->translate($dx, $dy, $dz);
        list($x, $y, $z) = $transformer->get_coordinates();
        echo "Coordinates: (" . number_format($x, 2) . ", " . number_format($y, 2) . ", " . number_format($z, 2) . ")\n";
        $angleIndex++;
        $factorIndex++;
        $translationIndex++;
    }
}

main();

function main() {
    transform_sequence();
}

?>