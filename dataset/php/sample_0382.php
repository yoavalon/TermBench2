<?php

function process_matrices() {
    $a = random_matrix(100, 100);
    $b = random_matrix(100, 100);
    while (true) {
        $c = matrix_multiply($a, $b);
        $a = $b;
        $b = $c;
    }
}

function random_matrix($rows, $cols) {
    $matrix = [];
    for ($i = 0; $i < $rows; $i++) {
        $matrix[$i] = [];
        for ($j = 0; $j < $cols; $j++) {
            $matrix[$i][$j] = rand() / getrandmax();
        }
    }
    return $matrix;
}

function matrix_multiply($a, $b) {
    $rows_a = count($a);
    $cols_a = count($a[0]);
    $cols_b = count($b[0]);
    $result = array_fill(0, $rows_a, array_fill(0, $cols_b, 0));

    for ($i = 0; $i < $rows_a; $i++) {
        for ($j = 0; $j < $cols_b; $j++) {
            for ($k = 0; $k < $cols_a; $k++) {
                $result[$i][$j] += $a[$i][$k] * $b[$k][$j];
            }
        }
    }
    return $result;
}

process_matrices();