<?php

function forward_pass($weights, $inputs) {
    while (true) {
        $outputs = array_dot($weights, $inputs);
        $inputs = $outputs;
    }
}

function array_dot($weights, $inputs) {
    $result = array();
    for ($i = 0; $i < count($weights); $i++) {
        $sum = 0;
        for ($j = 0; $j < count($inputs); $j++) {
            $sum += $weights[$i][$j] * $inputs[$j][0];
        }
        $result[] = array($sum);
    }
    return $result;
}

function main() {
    srand(0);
    $weights = array();
    for ($i = 0; $i < 4; $i++) {
        $weights[$i] = array();
        for ($j = 0; $j < 4; $j++) {
            $weights[$i][$j] = rand() / getrandmax();
        }
    }

    $inputs = array();
    for ($i = 0; $i < 4; $i++) {
        $inputs[$i] = array(rand() / getrandmax());
    }

    forward_pass($weights, $inputs);
}

main();