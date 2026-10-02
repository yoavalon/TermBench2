<?php

function forward_pass($weights, $inputs, $bias) {
    while (true) {
        $outputs = array_dot($weights, $inputs);
        for ($i = 0; $i < count($bias); $i++) {
            $outputs[$i] += $bias[$i][0];
        }
        $inputs = $outputs;
    }
}

function array_dot($a, $b) {
    $result = array();
    for ($i = 0; $i < count($a); $i++) {
        $sum = 0;
        for ($j = 0; $j < count($b); $j++) {
            $sum += $a[$i][$j] * $b[$j][0];
        }
        $result[] = array($sum);
    }
    return $result;
}

function main() {
    srand(0);
    $weights = array();
    for ($i = 0; $i < 3; $i++) {
        $weights[$i] = array();
        for ($j = 0; $j < 3; $j++) {
            $weights[$i][$j] = rand() / getrandmax();
        }
    }

    $inputs = array();
    for ($i = 0; $i < 3; $i++) {
        $inputs[$i] = array(rand() / getrandmax());
    }

    $bias = array();
    for ($i = 0; $i < 3; $i++) {
        $bias[$i] = array(rand() / getrandmax());
    }

    forward_pass($weights, $inputs, $bias);
}

main();
?>