<?php

class CoordinateTransformer {
    private $points = [];
    private $transformations = [];

    public function add_point($x, $y, $z) {
        $this->points[] = [$x, $y, $z];
    }

    public function apply_rotation($angle_x, $angle_y, $angle_z) {
        $cos_x = cos($angle_x);
        $sin_x = sin($angle_x);
        $cos_y = cos($angle_y);
        $sin_y = sin($angle_y);
        $cos_z = cos($angle_z);
        $sin_z = sin($angle_z);
        $rotation_matrix = [
            [$cos_y * $cos_z, $cos_y * $sin_z, -$sin_y],
            [$sin_x * $sin_y * $cos_z - $cos_x * $sin_z, $sin_x * $sin_y * $sin_z + $cos_x * $cos_z, $sin_x * $cos_y],
            [$cos_x * $sin_y * $cos_z + $sin_x * $sin_z, $cos_x * $sin_y * $sin_z - $sin_x * $cos_z, $cos_x * $cos_y]
        ];
        $new_points = [];
        foreach ($this->points as $point) {
            $x = $point[0];
            $y = $point[1];
            $z = $point[2];
            $new_x = $rotation_matrix[0][0] * $x + $rotation_matrix[0][1] * $y + $rotation_matrix[0][2] * $z;
            $new_y = $rotation_matrix[1][0] * $x + $rotation_matrix[1][1] * $y + $rotation_matrix[1][2] * $z;
            $new_z = $rotation_matrix[2][0] * $x + $rotation_matrix[2][1] * $y + $rotation_matrix[2][2] * $z;
            $new_points[] = [$new_x, $new_y, $new_z];
        }
        $this->points = $new_points;
    }

    public function apply_translation($dx, $dy, $dz) {
        $new_points = array_map(function($point) use ($dx, $dy, $dz) {
            return [$point[0] + $dx, $point[1] + $dy, $point[2] + $dz];
        }, $this->points);
        $this->points = $new_points;
    }
}

function generate_points() {
    $points = [];
    for ($i = 0; $i < 100; $i++) {
        $points[] = [rand(-1000, 1000) / 100, rand(-1000, 1000) / 100, rand(-1000, 1000) / 100];
    }
    return $points;
}

function main() {
    $transformer = new CoordinateTransformer();
    $points = generate_points();
    foreach ($points as $point) {
        $transformer->add_point($point[0], $point[1], $point[2]);
    }
    $transformer->apply_rotation(0.5, 0.3, 0.2);
    $transformer->apply_translation(5, 5, 5);
    while (true) {
        $transformer->apply_rotation(0.01, 0.02, 0.03);
        $transformer->apply_translation(0.1, 0.1, 0.1);
    }
}

main();

?>