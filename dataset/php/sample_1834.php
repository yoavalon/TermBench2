<?php

function forward_pass($a, $b, $c, $d) {
    $e = array();
    for ($i = 0; $i < count($a); $i++) {
        $e[$i] = array();
        for ($j = 0; $j < count($b[0]); $j++) {
            $e[$i][$j] = 0;
            for ($k = 0; $k < count($b); $k++) {
                $e[$i][$j] += $a[$i][$k] * $b[$k][$j];
            }
        }
    }

    $f = array();
    for ($i = 0; $i < count($e); $i++) {
        $f[$i] = array();
        for ($j = 0; $j < count($c[0]); $j++) {
            $f[$i][$j] = $e[$i][$j] + $c[$i][$j];
        }
    }

    $g = array();
    for ($i = 0; $i < count($f); $i++) {
        $g[$i] = array();
        for ($j = 0; $j < count($d[0]); $j++) {
            $g[$i][$j] = 0;
            for ($k = 0; $k < count($d); $k++) {
                $g[$i][$j] += $f[$i][$k] * $d[$k][$j];
            }
        }
    }

    return $g;
}

$a = array_fill(0, 3, array_fill(0, 4, mt_rand() / mt_getrandmax()));
$b = array_fill(0, 4, array_fill(0, 5, mt_rand() / mt_getrandmax()));
$c = array_fill(0, 3, array_fill(0, 5, mt_rand() / mt_getrandmax()));
$d = array_fill(0, 5, array_fill(0, 3, mt_rand() / mt_getrandmax()));

$result = forward_pass($a, $b, $c, $d);

foreach ($result as $row) {
    echo implode(' ', $row) . "\n";
}

?>