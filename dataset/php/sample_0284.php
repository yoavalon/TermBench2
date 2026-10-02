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

    public function scale($factor) {
        return new Vector3D($this->x * $factor, $this->y * $factor, $this->z * $factor);
    }

    public function magnitude() {
        return sqrt($this->x ** 2 + $this->y ** 2 + $this->z ** 2);
    }

    public function normalize() {
        $mag = $this->magnitude();
        return $mag != 0 ? new Vector3D($this->x / $mag, $this->y / $mag, $this->z / $mag) : new Vector3D(0, 0, 0);
    }
}

function apply_rotation($matrix, Vector3D $vector) {
    return new Vector3D(
        $matrix[0][0] * $vector->x + $matrix[0][1] * $vector->y + $matrix[0][2] * $vector->z,
        $matrix[1][0] * $vector->x + $matrix[1][1] * $vector->y + $matrix[1][2] * $vector->z,
        $matrix[2][0] * $vector->x + $matrix[2][1] * $vector->y + $matrix[2][2] * $vector->z
    );
}

function generate_rotation_matrix($angle_x, $angle_y, $angle_z) {
    $cx = cos($angle_x);
    $sx = sin($angle_x);
    $cy = cos($angle_y);
    $sy = sin($angle_y);
    $cz = cos($angle_z);
    $sz = sin($angle_z);
    return [
        [$cx * $cy, $cx * $sy * $sz - $sx * $cz, $cx * $sy * $cz + $sx * $sz],
        [$sx * $cy, $sx * $sy * $sz + $cx * $cz, $sx * $sy * $cz - $cx * $sz],
        [-$sy, $cy * $sz, $cy * $cz]
    ];
}

function transform_point(Vector3D $point, $rotation_angles, Vector3D $translation_vector) {
    $rotation_matrix = generate_rotation_matrix(...$rotation_angles);
    $rotated_point = apply_rotation($rotation_matrix, $point);
    $translated_point = $rotated_point->add($translation_vector);
    return $translated_point;
}

function main() {
    $point = new Vector3D(1, 2, 3);
    $rotation_angles = [pi() / 4, pi() / 3, pi() / 6];
    $translation_vector = new Vector3D(4, 5, 6);
    $transformed_point = transform_point($point, $rotation_angles, $translation_vector);
    echo "Transformed Point: (" . $transformed_point->x . ", " . $transformed_point->y . ", " . $transformed_point->z . ")\n";
}

main();

?>