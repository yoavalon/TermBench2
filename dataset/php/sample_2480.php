<?php

function nn_forward_pass($x, $w, $b) {
    $z = array();
    for ($i = 0; $i < count($x); $i++) {
        $z[$i] = array();
        for ($j = 0; $j < count($w[0]); $j++) {
            $z[$i][$j] = $b[$j];
            for ($k = 0; $k < count($w); $k++) {
                $z[$i][$j] += $x[$i][$k] * $w[$k][$j];
            }
            $z[$i][$j] = 1 / (1 + exp(-$z[$i][$j]));
        }
    }
    return $z;
}

$x = array(array(0, 1), array(1, 0));
$w = array(array(0.5, -0.5), array(-0.5, 0.5));
$b = array(0.1, -0.1);
$result = nn_forward_pass($x, $w, $b);

print_r($result);

?>