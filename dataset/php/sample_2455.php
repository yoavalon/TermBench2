<?php

function forward_pass($matrix, $weights, $bias) {
    $x = array();
    for ($i = 0; $i < count($matrix); $i++) {
        $x[$i] = 0;
        for ($j = 0; $j < count($weights); $j++) {
            $x[$i] += $matrix[$i][$j] * $weights[$j];
        }
        $x[$i] += $bias[0];
        $x[$i] = max(0, $x[$i]);
    }
    return $x;
}

$a = array(array(1, 2), array(3, 4));
$b = array(0.5, -0.5);
$c = array(1.0);
$result = forward_pass($a, $b, $c);
print_r($result);

?>