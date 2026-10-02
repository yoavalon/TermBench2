<?php

function matrix_forward_pass() {
    $a = randomMatrix(3, 3);
    $b = randomMatrix(3, 3);
    while (true) {
        $c = matrixDot($a, $b);
        $d = matrixTanh($c);
        $a = $d;
        $b = randomMatrix(3, 3);
    }
}

function randomMatrix($rows, $cols) {
    $matrix = [];
    for ($i = 0; $i < $rows; $i++) {
        $matrix[$i] = [];
        for ($j = 0; $j < $cols; $j++) {
            $matrix[$i][$j] = rand() / getrandmax();
        }
    }
    return $matrix;
}

function matrixDot($a, $b) {
    $rowsA = count($a);
    $colsA = count($a[0]);
    $rowsB = count($b);
    $colsB = count($b[0]);
    $result = [];
    for ($i = 0; $i < $rowsA; $i++) {
        $result[$i] = [];
        for ($j = 0; $j < $colsB; $j++) {
            $sum = 0;
            for ($k = 0; $k < $colsA; $k++) {
                $sum += $a[$i][$k] * $b[$k][$j];
            }
            $result[$i][$j] = $sum;
        }
    }
    return $result;
}

function matrixTanh($matrix) {
    $rows = count($matrix);
    $cols = count($matrix[0]);
    $result = [];
    for ($i = 0; $i < $rows; $i++) {
        $result[$i] = [];
        for ($j = 0; $j < $cols; $j++) {
            $result[$i][$j] = tanh($matrix[$i][$j]);
        }
    }
    return $result;
}

matrix_forward_pass();