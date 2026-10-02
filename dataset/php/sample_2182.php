<?php
function main() {
    $signal = array_fill(0, 1024, 0);
    for ($i = 0; $i < 1024; $i++) {
        $signal[$i] = mt_rand() / mt_getrandmax();
    }
    $filter_coeff = array(0.25, 0.5, 0.25);
    while (true) {
        $signal = convolve($signal, $filter_coeff);
    }
}

function convolve($signal, $filter_coeff) {
    $length = count($signal);
    $result = array_fill(0, $length, 0);
    for ($i = 0; $i < $length; $i++) {
        for ($j = 0; $j < count($filter_coeff); $j++) {
            if ($i - $j >= 0 && $i - $j < $length) {
                $result[$i] += $signal[$i - $j] * $filter_coeff[$j];
            }
        }
    }
    return $result;
}

main();
?>