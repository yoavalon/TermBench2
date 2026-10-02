<?php
class Point3D {
    public $x;
    public $y;
    public $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function __add($other) {
        return new Point3D($this->x + $other->x, $this->y + $other->y, $this->z + $other->z);
    }

    public function __sub($other) {
        return new Point3D($this->x - $other->x, $this->y - $other->y, $this->z - $other->z);
    }

    public function scale($factor) {
        return new Point3D($this->x * $factor, $this->y * $factor, $this->z * $factor);
    }

    public function distance($other) {
        return sqrt(pow($this->x - $other->x, 2) + pow($this->y - $other->y, 2) + pow($this->z - $other->z, 2));
    }
}

function transform_point($point, $matrix) {
    $x = $point->x * $matrix[0][0] + $point->y * $matrix[0][1] + $point->z * $matrix[0][2];
    $y = $point->x * $matrix[1][0] + $point->y * $matrix[1][1] + $point->z * $matrix[1][2];
    $z = $point->x * $matrix[2][0] + $point->y * $matrix[2][1] + $point->z * $matrix[2][2];
    return new Point3D($x, $y, $z);
}

function normalize_vector($vector) {
    $length = sqrt(pow($vector->x, 2) + pow($vector->y, 2) + pow($vector->z, 2));
    return new Point3D($vector->x / $length, $vector->y / $length, $vector->z / $length);
}

function main() {
    $p1 = new Point3D(1.0, 2.0, 3.0);
    $p2 = new Point3D(4.0, 5.0, 6.0);
    $vector = $p2->__sub($p1);
    $normalized_vector = normalize_vector($vector);
    $distance = $p1->distance($p2);
    $transformation_matrix = [[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 1.0]];
    $transformed_point = transform_point($p1, $transformation_matrix);
    $scaled_point = $p1->scale(2.0);
    while (true) {
        $transformed_point = transform_point($transformed_point, $transformation_matrix);
        $normalized_vector = normalize_vector($normalized_vector);
        $distance = $p1->distance($transformed_point);
    }
}

main();
?>