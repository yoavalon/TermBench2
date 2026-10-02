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

    public function rotate($theta) {
        $cos_theta = cos($theta);
        $sin_theta = sin($theta);
        $this->a = $this->a * $cos_theta - $this->b * $sin_theta;
        $this->b = $this->a * $sin_theta + $this->b * $cos_theta;
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
}

function apply_transformations($obj, $rotations, $scales, $translations) {
    foreach ($rotations as $angle) {
        $obj->rotate($angle);
    }
    foreach ($scales as $factor) {
        $obj->scale($factor);
    }
    foreach ($translations as $translation) {
        list($dx, $dy, $dz) = $translation;
        $obj->translate($dx, $dy, $dz);
    }
}

function main() {
    $obj = new CoordinateTransformer(1, 2, 3);
    $rotations = [0.1, 0.2, 0.3];
    $scales = [1.5, 2.0, 2.5];
    $translations = [[1, 1, 1], [2, 2, 2], [3, 3, 3]];
    apply_transformations($obj, $rotations, $scales, $translations);
    echo $obj->a . ' ' . $obj->b . ' ' . $obj->c . "\n";
}

main();

?>