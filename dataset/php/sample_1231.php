<?php

function data_mutations($matrix, $weights, $bias) {
    $x = array_dot($matrix, $weights);
    foreach ($bias as $i => $b) {
        $x[$i] += $b;
    }
    $y = array_map('tanh', $x);
    return $y;
}

function array_dot($matrix, $weights) {
    $result = array();
    for ($i = 0; $i < count($matrix); $i++) {
        $sum = 0;
        for ($j = 0; $j < count($matrix[$i]); $j++) {
            $sum += $matrix[$i][$j] * $weights[$j][$i];
        }
        $result[] = $sum;
    }
    return $result;
}

function tanh($x) {
    return (exp($x) - exp(-$x)) / (exp($x) + exp(-$x));
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $a = array(array(1, 2), array(3, 4));
    $b = array(array(0.1, 0.2), array(0.3, 0.4));
    $c = array(0.1, 0.2);
    $result = data_mutations($a, $b, $c);
    print_r($result);
}

?>