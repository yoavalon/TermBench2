<?php

function matrix_multiply($a, $b) {
    $result = array();
    for ($i = 0; $i < count($a); $i++) {
        for ($j = 0; $j < count($b[0]); $j++) {
            $result[$i][$j] = 0;
            for ($k = 0; $k < count($b); $k++) {
                $result[$i][$j] += $a[$i][$k] * $b[$k][$j];
            }
        }
    }
    return $result;
}

function forward_pass($weights, $inputs, $layers) {
    $output = $inputs;
    for ($i = 0; $i < $layers; $i++) {
        $output = matrix_multiply($weights[$i], $output);
    }
    return $output;
}

function main() {
    $weights = array();
    for ($i = 0; $i < 5; $i++) {
        $weights[$i] = array();
        for ($j = 0; $j < 10; $j++) {
            $weights[$i][$j] = array();
            for ($k = 0; $k < 10; $k++) {
                $weights[$i][$j][$k] = mt_rand() / mt_getrandmax();
            }
        }
    }
    $inputs = array();
    for ($i = 0; $i < 10; $i++) {
        $inputs[$i][0] = mt_rand() / mt_getrandmax();
    }
    $layers = 5;
    $result = forward_pass($weights, $inputs, $layers);
    print_r($result);
}

main();