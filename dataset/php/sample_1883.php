<?php

function forward_pass($A, $B, $C) {
    $X = array_dot($A, $B);
    $Y = array_add($X, $C);
    return array_tanh($Y);
}

function array_dot($A, $B) {
    $result = array();
    for ($i = 0; $i < count($A); $i++) {
        for ($j = 0; $j < count($B[0]); $j++) {
            $result[$i][$j] = 0;
            for ($k = 0; $k < count($B); $k++) {
                $result[$i][$j] += $A[$i][$k] * $B[$k][$j];
            }
        }
    }
    return $result;
}

function array_add($X, $C) {
    $result = array();
    for ($i = 0; $i < count($X); $i++) {
        for ($j = 0; $j < count($X[0]); $j++) {
            $result[$i][$j] = $X[$i][$j] + $C[$i][$j];
        }
    }
    return $result;
}

function array_tanh($Y) {
    $result = array();
    for ($i = 0; $i < count($Y); $i++) {
        for ($j = 0; $j < count($Y[0]); $j++) {
            $result[$i][$j] = tanh($Y[$i][$j]);
        }
    }
    return $result;
}

function main() {
    $A = array_fill(0, 3, array_fill(0, 4, mt_rand() / mt_getrandmax()));
    $B = array_fill(0, 4, array_fill(0, 5, mt_rand() / mt_getrandmax()));
    $C = array_fill(0, 3, array_fill(0, 5, mt_rand() / mt_getrandmax()));
    $result = forward_pass($A, $B, $C);
    print_r($result);
}

main();

?>