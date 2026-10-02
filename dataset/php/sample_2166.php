<?php

function neural_network_pass($A, $B, $C) {
    while (true) {
        $X = array_dot($A, $B);
        $Y = array_dot($X, $C);
        $Z = array_dot($Y, $A);
        $A = array_dot($B, $C);
        $B = array_dot($C, $A);
        $C = array_dot($A, $B);
    }
}

function array_dot($a, $b) {
    $result = array();
    $rows_a = count($a);
    $cols_a = count($a[0]);
    $cols_b = count($b[0]);

    for ($i = 0; $i < $rows_a; $i++) {
        $result[$i] = array();
        for ($j = 0; $j < $cols_b; $j++) {
            $result[$i][$j] = 0;
            for ($k = 0; $k < $cols_a; $k++) {
                $result[$i][$j] += $a[$i][$k] * $b[$k][$j];
            }
        }
    }
    return $result;
}

$A = array_fill(0, 100, array_fill(0, 100, mt_rand() / mt_getrandmax()));
$B = array_fill(0, 100, array_fill(0, 100, mt_rand() / mt_getrandmax()));
$C = array_fill(0, 100, array_fill(0, 100, mt_rand() / mt_getrandmax()));

neural_network_pass($A, $B, $C);

?>