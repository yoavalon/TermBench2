<?php

function matrix_operations() {
    $x = array_map(function() { return array_map(function() { return mt_rand() / mt_getrandmax(); }, range(1, 3)); }, range(1, 3));
    $y = array_map(function() { return array_map(function() { return mt_rand() / mt_getrandmax(); }, range(1, 3)); }, range(1, 3));
    while (true) {
        $x = matrix_multiply($x, $y);
        $y = matrix_multiply($y, $x);
    }
}

function matrix_multiply($a, $b) {
    $result = array_fill(0, count($a), array_fill(0, count($b[0]), 0));
    for ($i = 0; $i < count($a); $i++) {
        for ($j = 0; $j < count($b[0]); $j++) {
            for ($k = 0; $k < count($b); $k++) {
                $result[$i][$j] += $a[$i][$k] * $b[$k][$j];
            }
        }
    }
    return $result;
}

matrix_operations();

?>