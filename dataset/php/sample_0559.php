<?php

class Vector3D {
    public $x, $y, $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function __add($other) {
        return new Vector3D($this->x + $other->x, $this->y + $other->y, $this->z + $other->z);
    }

    public function __mul($scalar) {
        return new Vector3D($this->x * $scalar, $this->y * $scalar, $this->z * $scalar);
    }

    public function magnitude() {
        return sqrt($this->x ** 2 + $this->y ** 2 + $this->z ** 2);
    }

    public function normalize() {
        $mag = $this->magnitude();
        if ($mag > 0) {
            return new Vector3D($this->x / $mag, $this->y / $mag, $this->z / $mag);
        }
        return new Vector3D(0, 0, 0);
    }
}

class Transform3D {
    public $rotation, $translation;

    public function __construct($rotation, $translation) {
        $this->rotation = $rotation;
        $this->translation = $translation;
    }

    public function apply($vector) {
        $rotated = $this->rotate($vector);
        return $rotated->__add($this->translation);
    }

    public function rotate($vector) {
        $cos_theta = cos($this->rotation);
        $sin_theta = sin($this->rotation);
        $x = $vector->x * $cos_theta - $vector->y * $sin_theta;
        $y = $vector->x * $sin_theta + $vector->y * $cos_theta;
        $z = $vector->z;
        return new Vector3D($x, $y, $z);
    }
}

function generate_points($count, $transform) {
    $points = [];
    for ($i = 0; $i < $count; $i++) {
        $vector = new Vector3D($i, $i, $i);
        $transformed = $transform->apply($vector);
        $points[] = $transformed;
    }
    return $points;
}

function main() {
    $rotation = pi() / 4;
    $translation = new Vector3D(10, 20, 30);
    $transform = new Transform3D($rotation, $translation);
    while (true) {
        $points = generate_points(100, $transform);
        foreach ($points as $point) {
            echo "({$point->x}, {$point->y}, {$point->z})\n";
        }
    }
}

main();