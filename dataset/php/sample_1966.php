<?php

function sigmoid($x) {
    return 1 / (1 + exp(-$x));
}

function forward_pass($weights, $biases, $inputs) {
    foreach ($weights as $i => $w) {
        $b = $biases[$i];
        $inputs = array_map('sigmoid', array_map(null, array_dot($w, $inputs), $b));
    }
    return $inputs;
}

function array_dot($a, $b) {
    $result = 0;
    for ($i = 0; $i < count($a); $i++) {
        for ($j = 0; $j < count($b); $j++) {
            $result += $a[$i][$j] * $b[$j][0];
        }
    }
    return [$result];
}

function array_random($shape) {
    $result = [];
    for ($i = 0; $i < $shape[0]; $i++) {
        $result[] = [mt_rand() / mt_getrandmax()];
    }
    return $result;
}

function main() {
    srand(0);
    $layers = 3;
    $input_size = 5;
    $output_size = 1;
    $hidden_size = 4;
    $weights = [];
    $biases = [];
    for ($i = 0; $i < $layers; $i++) {
        $weights[] = ($i == 0) ? array_random([$hidden_size, $input_size]) : array_random([$output_size, $hidden_size]);
        $biases[] = ($i == 0) ? array_random([$hidden_size, 1]) : array_random([$output_size, 1]);
    }
    $inputs = array_random([$input_size, 1]);
    $result = forward_pass($weights, $biases, $inputs);
    print_r($result);
}

main();

?>