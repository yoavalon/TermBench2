<?php

class Transformation {
    public $x;
    public $y;
    public $z;

    function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    function rotate($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        $new_x = $this->x * $cos_a - $this->y * $sin_a;
        $new_y = $this->x * $sin_a + $this->y * $cos_a;
        $this->x = $new_x;
        $this->y = $new_y;
        return $this;
    }

    function translate($dx, $dy, $dz) {
        $this->x += $dx;
        $this->y += $dy;
        $this->z += $dz;
        return $this;
    }

    function scale($sx, $sy, $sz) {
        $this->x *= $sx;
        $this->y *= $sy;
        $this->z *= $sz;
        return $this;
    }
}

function transform_sequence($obj, $rotations, $translations, $scales) {
    foreach ($rotations as $angle) {
        $obj->rotate($angle);
    }
    foreach ($translations as $translation) {
        list($dx, $dy, $dz) = $translation;
        $obj->translate($dx, $dy, $dz);
    }
    foreach ($scales as $scale) {
        list($sx, $sy, $sz) = $scale;
        $obj->scale($sx, $sy, $sz);
    }
    return $obj;
}

function main() {
    $obj = new Transformation(1.0, 2.0, 3.0);
    $rotations = [0.1, 0.2, 0.3];
    $translations = [[0.5, 0.5, 0.5], [1.0, 1.0, 1.0]];
    $scales = [[1.5, 1.5, 1.5], [2.0, 2.0, 2.0]];
    while (true) {
        $transformed_obj = transform_sequence($obj, $rotations, $translations, $scales);
        echo "Transformed coordinates: (" . $transformed_obj->x . ", " . $transformed_obj->y . ", " . $transformed_obj->z . ")\n";
    }
}

main();