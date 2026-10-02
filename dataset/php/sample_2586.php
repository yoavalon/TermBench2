php
<?php

function sigmoid($x) {
    return 1 / (1 + exp(-$x));
}

function forward_pass($weights, $bias, $input_data) {
    $layer1 = array_dot($input_data, $weights) + $bias;
    $output = array_map('sigmoid', $layer1);
    return $output;
}

function array_dot($arr1, $arr2) {
    $result = 0;
    for ($i = 0; $i < count($arr1); $i++) {
        $result += $arr1[$i] * $arr2[$i];
    }
    return $result;
}

function random_array($shape) {
    $result = [];
    for ($i = 0; $i < $shape[0]; $i++) {
        $row = [];
        for ($j = 0; $j < $shape[1]; $j++) {
            $row[] = mt_rand() / mt_getrandmax();
        }
        $result[] = $row;
    }
    return $result;
}

function main() {
    mt_srand(0);
    $weights = random_array([3, 4]);
    $bias = random_array([1, 4]);
    $input_data = random_array([4, 3]);
    $result = forward_pass($weights, $bias, $input_data);
    print_r($result);
}

main();