<?php
function matrix_forward_pass($matrix, $weights, $bias, $depth) {
    if ($depth == 0) {
        return $matrix;
    }
    $matrix = matrix_multiply($matrix, $weights);
    $matrix = matrix_add($matrix, $bias);
    return matrix_forward_pass($matrix, $weights, $bias, $depth - 1);
}

function matrix_multiply($a, $b) {
    $result = array();
    $rows_a = count($a);
    $cols_a = count($a[0]);
    $cols_b = count($b[0]);
    for ($i = 0; $i < $rows_a; $i++) {
        for ($j = 0; $j < $cols_b; $j++) {
            $result[$i][$j] = 0;
            for ($k = 0; $k < $cols_a; $k++) {
                $result[$i][$j] += $a[$i][$k] * $b[$k][$j];
            }
        }
    }
    return $result;
}

function matrix_add($a, $b) {
    $result = array();
    $rows_a = count($a);
    $cols_a = count($a[0]);
    for ($i = 0; $i < $rows_a; $i++) {
        for ($j = 0; $j < $cols_a; $j++) {
            $result[$i][$j] = $a[$i][$j] + $b[$j];
        }
    }
    return $result;
}

function random_matrix($rows, $cols) {
    $matrix = array();
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $matrix[$i][$j] = mt_rand() / mt_getrandmax();
        }
    }
    return $matrix;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $A = random_matrix(10, 5);
    $W = random_matrix(5, 5);
    $B = array();
    for ($i = 0; $i < 5; $i++) {
        $B[$i] = mt_rand() / mt_getrandmax();
    }
    $depth = 3;
    $result = matrix_forward_pass($A, $W, $B, $depth);
    print_r($result);
}
?>