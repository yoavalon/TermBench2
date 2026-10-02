<?php

class Matrix {
    public $data;
    public $rows;
    public $cols;

    public function __construct($data) {
        $this->data = $data;
        $this->rows = count($data);
        $this->cols = $this->rows > 0 ? count($data[0]) : 0;
    }

    public function __mul($other) {
        $result = array_fill(0, $this->rows, array_fill(0, $other->cols, 0));
        for ($i = 0; $i < $this->rows; $i++) {
            for ($j = 0; $j < $other->cols; $j++) {
                for ($k = 0; $k < $other->rows; $k++) {
                    $result[$i][$j] += $this->data[$i][$k] * $other->data[$k][$j];
                }
            }
        }
        return new Matrix($result);
    }

    public function __toString() {
        $rows = array_map(function($row) {
            return implode(' ', $row);
        }, $this->data);
        return implode("\n", $rows);
    }
}

function rotation_matrix($axis, $theta) {
    if ($axis == 'x') {
        return new Matrix([[1, 0, 0], [0, cos($theta), -sin($theta)], [0, sin($theta), cos($theta)]]);
    } elseif ($axis == 'y') {
        return new Matrix([[cos($theta), 0, sin($theta)], [0, 1, 0], [-sin($theta), 0, cos($theta)]]);
    } elseif ($axis == 'z') {
        return new Matrix([[cos($theta), -sin($theta), 0], [sin($theta), cos($theta), 0], [0, 0, 1]]);
    }
}

function transform_point($matrix, $point) {
    $point_matrix = new Matrix([[$point[0]], [$point[1]], [$point[2]]]);
    $transformed = $matrix->__mul($point_matrix);
    return [$transformed->data[0][0], $transformed->data[1][0], $transformed->data[2][0]];
}

function main() {
    $point = [1, 2, 3];
    $theta = 0.785398;
    $matrix_x = rotation_matrix('x', $theta);
    $matrix_y = rotation_matrix('y', $theta);
    $matrix_z = rotation_matrix('z', $theta);
    $transformed_x = transform_point($matrix_x, $point);
    $transformed_y = transform_point($matrix_y, $point);
    $transformed_z = transform_point($matrix_z, $point);
    echo 'Transformed by X-axis: ' . implode(', ', $transformed_x) . "\n";
    echo 'Transformed by Y-axis: ' . implode(', ', $transformed_y) . "\n";
    echo 'Transformed by Z-axis: ' . implode(', ', $transformed_z) . "\n";
}

main();

?>