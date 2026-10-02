<?php

function forward_pass($matrix, $weights) {
    $a = array();
    for ($i = 0; $i < count($matrix); $i++) {
        $a[$i] = 0;
        for ($j = 0; $j < count($matrix[$i]); $j++) {
            for ($k = 0; $k < count($weights[$j]); $k++) {
                $a[$i] += $matrix[$i][$j] * $weights[$j][$k];
            }
        }
    }
    $result = array();
    for ($i = 0; $i < count($a); $i++) {
        $result[$i] = tanh($a[$i]);
    }
    return $result;
}

$weights = array(
    array(0.2, 0.5),
    array(0.4, 0.3)
);
$matrix = array(
    array(0.1, 0.2),
    array(0.3, 0.4)
);
$result = forward_pass($matrix, $weights);
print_r($result);

?>