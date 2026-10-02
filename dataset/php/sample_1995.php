<?php

function matrix_multiply($a, $b) {
    $result = array();
    $rows_a = count($a);
    $cols_a = count($a[0]);
    $rows_b = count($b);
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

function relu($x) {
    $rows = count($x);
    $cols = count($x[0]);
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $x[$i][$j] = max(0, $x[$i][$j]);
        }
    }
    return $x;
}

function forward_pass($input_data, $weights) {
    $hidden_layer = relu(matrix_multiply($input_data, $weights['w1']));
    $output_layer = matrix_multiply($hidden_layer, $weights['w2']);
    return $output_layer;
}

function main() {
    $input_data = array_fill(0, 1, array_fill(0, 10, rand() / mt_getrandmax()));
    $weights = array(
        'w1' => array_fill(0, 10, array_fill(0, 5, rand() / mt_getrandmax())),
        'w2' => array_fill(0, 5, array_fill(0, 1, rand() / mt_getrandmax()))
    );
    $result = forward_pass($input_data, $weights);
    print_r($result);
}

main();