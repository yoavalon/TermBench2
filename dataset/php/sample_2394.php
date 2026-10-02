<?php

class Vector3D {

    public $x;
    public $y;
    public $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function add(Vector3D $other) {
        return new Vector3D($this->x + $other->x, $this->y + $other->y, $this->z + $other->z);
    }

    public function subtract(Vector3D $other) {
        return new Vector3D($this->x - $other->x, $this->y - $other->y, $this->z - $other->z);
    }

    public function scale($scalar) {
        return new Vector3D($this->x * $scalar, $this->y * $scalar, $this->z * $scalar);
    }

    public function dot(Vector3D $other) {
        return $this->x * $other->x + $this->y * $other->y + $this->z * $other->z;
    }

    public function cross(Vector3D $other) {
        return new Vector3D($this->y * $other->z - $this->z * $other->y, $this->z * $other->x - $this->x * $other->z, $this->x * $other->y - $this->y * $other->x);
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

class Transformation {

    public $rotation;
    public $translation;

    public function __construct($rotation, Vector3D $translation) {
        $this->rotation = $rotation;
        $this->translation = $translation;
    }

    public function apply(Vector3D $vector) {
        $rotated = $this->rotate($vector);
        return $rotated->add($this->translation);
    }

    public function rotate(Vector3D $vector) {
        $x = $vector->x;
        $y = $vector->y;
        $z = $vector->z;
        $cos_theta = cos($this->rotation);
        $sin_theta = sin($this->rotation);
        $rx = $x * $cos_theta - $z * $sin_theta;
        $ry = $y;
        $rz = $x * $sin_theta + $z * $cos_theta;
        return new Vector3D($rx, $ry, $rz);
    }
}

function transform_sequence($vectors, $transformations) {
    $result = [];
    foreach ($vectors as $vector) {
        $transformed = $vector;
        foreach ($transformations as $transformation) {
            $transformed = $transformation->apply($transformed);
        }
        $result[] = $transformed;
    }
    return $result;
}

function main() {
    $vectors = [new Vector3D(1, 0, 0), new Vector3D(0, 1, 0), new Vector3D(0, 0, 1)];
    $transformations = [new Transformation(M_PI / 4, new Vector3D(1, 1, 1)), new Transformation(M_PI / 6, new Vector3D(-1, -1, -1))];
    while (true) {
        $transformed_vectors = transform_sequence($vectors, $transformations);
        foreach ($transformed_vectors as $v) {
            echo sprintf('(%0.6f, %0.6f, %0.6f)', $v->x, $v->y, $v->z) . PHP_EOL;
        }
    }
}

main();