<?php

function recursive_matrix_op($matrix, $weight, $bias) {
    $result = array();
    for ($i = 0; $i < 3; $i++) {
        $result[$i] = 0;
        for ($j = 0; $j < 3; $j++) {
            $result[$i] += $matrix[$i][$j] * $weight[$j];
        }
        $result[$i] += $bias[$i];
    }
    return recursive_matrix_op($result, $weight, $bias);
}

function main() {
    $matrix = array();
    $weight = array();
    $bias = array();
    
    for ($i = 0; $i < 3; $i++) {
        $matrix[$i] = array();
        $weight[$i] = array();
        for ($j = 0; $j < 3; $j++) {
            $matrix[$i][$j] = mt_rand() / mt_getrandmax();
            $weight[$i][$j] = mt_rand() / mt_getrandmax();
        }
        $bias[$i] = mt_rand() / mt_getrandmax();
    }
    
    recursive_matrix_op($matrix, $weight, $bias);
}

main();

?>