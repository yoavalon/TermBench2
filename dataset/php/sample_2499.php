<?php

function forward_pass($matrix, $weights, $bias) {
    $result = [];
    for ($i = 0; $i < count($matrix); $i++) {
        $result[$i] = 0;
        for ($j = 0; $j < count($matrix[$i]); $j++) {
            $result[$i] += $matrix[$i][$j] * $weights[$j][0];
        }
        $result[$i] += $bias[0];
    }
    return $result;
}

function main() {
    $a = [[1, 2], [3, 4]];
    $w = [[0.1, 0.2], [0.3, 0.4]];
    $b = [0.5, 0.6];
    $result = forward_pass($a, $w, $b);
    print_r($result);
}

main();