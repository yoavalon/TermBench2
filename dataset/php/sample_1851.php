<?php

function forward_pass($weights, $inputs) {
    $activations = array();
    for ($i = 0; $i < count($weights); $i++) {
        $sum = 0;
        for ($j = 0; $j < count($inputs); $j++) {
            $sum += $weights[$i][$j] * $inputs[$j];
        }
        $activations[] = $sum;
    }
    return $activations;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $a = array();
    for ($i = 0; $i < 10; $i++) {
        $a[$i] = array();
        for ($j = 0; $j < 5; $j++) {
            $a[$i][$j] = mt_rand() / mt_getrandmax();
        }
    }

    $b = array();
    for ($i = 0; $i < 5; $i++) {
        $b[$i] = array();
        for ($j = 0; $j < 3; $j++) {
            $b[$i][$j] = mt_rand() / mt_getrandmax();
        }
    }

    $c = forward_pass($a, $b);
    print_r($c);
}
?>