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

    public function __sub($other) {
        return new Vector3D($this->x - $other->x, $this->y - $other->y, $this->z - $other->z);
    }

    public function scale($factor) {
        return new Vector3D($this->x * $factor, $this->y * $factor, $this->z * $factor);
    }

    public function rotate($angle, $axis) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        if ($axis == 'x') {
            return new Vector3D($this->x, $this->y * $cos_a - $this->z * $sin_a, $this->y * $sin_a + $this->z * $cos_a);
        } elseif ($axis == 'y') {
            return new Vector3D($this->x * $cos_a + $this->z * $sin_a, $this->y, -$this->x * $sin_a + $this->z * $cos_a);
        } elseif ($axis == 'z') {
            return new Vector3D($this->x * $cos_a - $this->y * $sin_a, $this->x * $sin_a + $this->y * $cos_a, $this->z);
        }
    }
}

class Transformation {
    public $translation, $rotation, $scale;

    public function __construct($translation, $rotation, $scale) {
        $this->translation = $translation;
        $this->rotation = $rotation;
        $this->scale = $scale;
    }

    public function apply($vector) {
        $vector = $vector->__add($this->translation);
        foreach ($this->rotation as $axis => $angle) {
            $vector = $vector->rotate($angle, $axis);
        }
        $vector = $vector->scale($this->scale);
        return $vector;
    }
}

class GeometryTransformer {
    public $transformations;

    public function __construct($transformations) {
        $this->transformations = $transformations;
    }

    public function process($initial_vector) {
        $current_vector = $initial_vector;
        foreach ($this->transformations as $transformation) {
            $current_vector = $transformation->apply($current_vector);
        }
        return $current_vector;
    }
}

function main() {
    $initial_vector = new Vector3D(1, 0, 0);
    $transformations = [
        new Transformation(new Vector3D(0, 0, 0), ['x' => 1.57], 2),
        new Transformation(new Vector3D(1, 1, 1), ['y' => 1.57], 0.5),
        new Transformation(new Vector3D(0, 0, 0), ['z' => 1.57], 1)
    ];
    $transformer = new GeometryTransformer($transformations);
    while (true) {
        $transformed_vector = $transformer->process($initial_vector);
        echo "Transformed Vector: (" . $transformed_vector->x . ", " . $transformed_vector->y . ", " . $transformed_vector->z . ")\n";
    }
}

main();