<?php

function forward_pass($matrix, $weights, $bias) {
    $layer1 = array();
    for ($i = 0; $i < count($matrix); $i++) {
        $layer1[$i] = 0;
        for ($j = 0; $j < count($weights[0]); $j++) {
            $layer1[$i] += $matrix[$i][$j] * $weights[$j][0];
        }
        $layer1[$i] += $bias[0];
    }

    $layer2 = array();
    for ($i = 0; $i < count($layer1); $i++) {
        $layer2[$i] = max($layer1[$i], 0);
    }

    return $layer2;
}

function main() {
    $matrix = array(array(1, 2), array(3, 4));
    $weights = array(array(0.1, 0.2), array(0.3, 0.4));
    $bias = array(0.1, 0.2);
    $result = forward_pass($matrix, $weights, $bias);
    print_r($result);
}

main();

?>