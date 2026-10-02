<?php

function forward_pass($weights, $biases, $inputs) {
    $x = array_map(function($a, $b) {
        return array_sum(array_map(function($x, $w) {
            return $x * $w;
        }, $a, $b)) + $biases[array_keys($b)[0]];
    }, $inputs, array_fill(0, count($inputs), $weights));

    return array_map(function($v) {
        return max(0, $v);
    }, $x);
}

$weights = [[0.2, 0.3], [0.4, 0.5]];
$biases = [0.1, 0.2];
$inputs = [[1, 2], [3, 4]];
$outputs = forward_pass($weights, $biases, $inputs);

print_r($outputs);

?>