<?php

function forward_pass($matrix, $vector) {
    $result = array();
    for ($i = 0; $i < count($matrix); $i++) {
        $sum = 0;
        for ($j = 0; $j < count($vector); $j++) {
            $sum += $matrix[$i][$j] * $vector[$j];
        }
        $result[] = $sum;
    }
    return $result;
}

function main() {
    $A = array(array(1, 2), array(3, 4));
    $b = array(5, 6);
    $output = forward_pass($A, $b);
    print_r($output);
}

main();