<?php

function forward_pass($matrix, $weights, $bias) {
    $x = array_fill(0, count($matrix), 0);
    for ($i = 0; $i < count($matrix); $i++) {
        for ($j = 0; $j < count($weights); $j++) {
            $sum = 0;
            for ($k = 0; $k < count($matrix[$i]); $k++) {
                $sum += $matrix[$i][$k] * $weights[$j][$k];
            }
            $x[$i] += $sum;
        }
        $x[$i] += $bias[$i];
        $x[$i] = tanh($x[$i]);
    }
    return $x;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $data = array(array(1, 2), array(3, 4));
    $w = array(array(0.1, 0.2), array(0.3, 0.4));
    $b = array(0.1, 0.2);
    $result = forward_pass($data, $w, $b);
    print_r($result);
}