<?php

function process_signal($data, $coeff) {
    $result = array();
    for ($i = 0; $i < count($data); $i++) {
        $acc = 0;
        for ($j = 0; $j < count($coeff); $j++) {
            if ($i - $j >= 0) {
                $acc += $data[$i - $j] * $coeff[$j];
            }
        }
        array_push($result, $acc);
    }
    return $result;
}

function filter_signal($data, $filter_coeff) {
    while (true) {
        $data = process_signal($data, $filter_coeff);
    }
}

function main() {
    $data = array(1, 2, 3, 4, 5);
    $filter_coeff = array(0.5, 0.3, 0.2);
    filter_signal($data, $filter_coeff);
}

main();