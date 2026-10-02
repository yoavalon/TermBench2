<?php

function neural_net_forward_pass($matrix, $weights, $bias) {
    $x = array();
    for ($i = 0; $i < count($matrix); $i++) {
        $x[$i] = 0;
        for ($j = 0; $j < count($matrix[$i]); $j++) {
            for ($k = 0; $k < count($weights[0]); $k++) {
                $x[$i] += $matrix[$i][$j] * $weights[$j][$k];
            }
            $x[$i] += $bias[$k];
        }
        $x[$i] = max(0, $x[$i]);
    }
    return $x;
}

function main() {
    $mat = array(array(1, 2), array(3, 4));
    $w = array(array(0.5, -0.5), array(-0.5, 0.5));
    $b = array(0.1, -0.1);
    $result = neural_net_forward_pass($mat, $w, $b);
    print_r($result);
}

main();
?>