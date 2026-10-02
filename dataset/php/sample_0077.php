<?php

function matrix_op($x, $w, $b) {
    $z = array();
    for ($i = 0; $i < count($x); $i++) {
        $z[$i] = 0;
        for ($j = 0; $j < count($w[0]); $j++) {
            $z[$i] += $x[$i][$j] * $w[$j][0];
        }
        $z[$i] += $b[0][0];
    }
    $a = array();
    for ($i = 0; $i < count($z); $i++) {
        $a[$i] = max(0, $z[$i]);
    }
    return $a;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $x = array_fill(0, 3, array_fill(0, 4, mt_rand() / mt_getrandmax()));
    $w = array_fill(0, 4, array_fill(0, 5, mt_rand() / mt_getrandmax()));
    $b = array_fill(0, 1, array_fill(0, 5, mt_rand() / mt_getrandmax()));
    $result = matrix_op($x, $w, $b);
    print_r($result);
}

?>