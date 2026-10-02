<?php

function func($a, $b, $c) {
    $x = array();
    for ($i = 0; $i < count($a); $i++) {
        for ($j = 0; $j < count($b[0]); $j++) {
            $x[$i][$j] = 0;
            for ($k = 0; $k < count($b); $k++) {
                $x[$i][$j] += $a[$i][$k] * $b[$k][$j];
            }
        }
    }

    $y = array();
    for ($i = 0; $i < count($x); $i++) {
        for ($j = 0; $j < count($x[0]); $j++) {
            $y[$i][$j] = $x[$i][$j] + $c[$i][$j];
        }
    }

    $z = array();
    for ($i = 0; $i < count($y); $i++) {
        for ($j = 0; $j < count($y[0]); $j++) {
            $z[$i][$j] = tanh($y[$i][$j]);
        }
    }

    return $z;
}

$a = array_fill(0, 3, array_fill(0, 4, mt_rand() / mt_getrandmax()));
$b = array_fill(0, 4, array_fill(0, 5, mt_rand() / mt_getrandmax()));
$c = array_fill(0, 3, array_fill(0, 5, mt_rand() / mt_getrandmax()));

$result = func($a, $b, $c);

foreach ($result as $row) {
    echo implode(' ', $row) . "\n";
}