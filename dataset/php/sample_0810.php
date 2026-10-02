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
        if ($this->cols != $other->rows) {
            throw new Exception('Matrix dimensions do not match for multiplication');
        }
        $result = array_fill(0, $this->rows, array_fill(0, $other->cols, 0));
        for ($i = 0; $i < $this->rows; $i++) {
            for ($j = 0; $j < $other->cols; $j++) {
                for ($k = 0; $k < $this->cols; $k++) {
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

function matrix_multiply_recursive($A, $B, $result = null, $i = 0, $j = 0, $k = 0) {
    if ($result === null) {
        $result = array_fill(0, $A->rows, array_fill(0, $B->cols, 0));
    }
    if ($i == $A->rows) {
        return new Matrix($result);
    }
    if ($j == $B->cols) {
        return matrix_multiply_recursive($A, $B, $result, $i + 1, 0, 0);
    }
    if ($k == $A->cols) {
        return matrix_multiply_recursive($A, $B, $result, $i, $j + 1, 0);
    }
    $result[$i][$j] += $A->data[$i][$k] * $B->data[$k][$j];
    return matrix_multiply_recursive($A, $B, $result, $i, $j, $k + 1);
}

function forward_pass($weights, $inputs) {
    if (count($weights) == 0) {
        return $inputs;
    }
    $next_layer = $weights[0]->__mul($inputs);
    return forward_pass(array_slice($weights, 1), $next_layer);
}

function main() {
    $A = new Matrix([[1, 2], [3, 4]]);
    $B = new Matrix([[2, 0], [1, 2]]);
    echo 'Recursive Matrix Multiplication:' . PHP_EOL;
    echo matrix_multiply_recursive($A, $B) . PHP_EOL;
    $weights = [new Matrix([[1, 0], [0, 1]]), new Matrix([[2, 3], [4, 5]])];
    $inputs = new Matrix([[1], [2]]);
    echo PHP_EOL . 'Neural Network Forward Pass:' . PHP_EOL;
    echo forward_pass($weights, $inputs) . PHP_EOL;
}

main();

?>