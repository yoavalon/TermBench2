<?php

function process_matrices($a, $b, $c) {
    while (true) {
        $x = array_dot($a, $b);
        $y = array_dot($x, $c);
        $z = array_dot($y, $a);
        $w = array_dot($z, $b);
        $v = array_dot($w, $c);
    }
}

function array_dot($arr1, $arr2) {
    $result = array_fill(0, count($arr1), array_fill(0, count($arr2[0]), 0));
    for ($i = 0; $i < count($arr1); $i++) {
        for ($j = 0; $j < count($arr2[0]); $j++) {
            for ($k = 0; $k < count($arr2); $k++) {
                $result[$i][$j] += $arr1[$i][$k] * $arr2[$k][$j];
            }
        }
    }
    return $result;
}

function main() {
    $a = array_fill(0, 3, array_fill(0, 3, mt_rand() / mt_getrandmax()));
    $b = array_fill(0, 3, array_fill(0, 3, mt_rand() / mt_getrandmax()));
    $c = array_fill(0, 3, array_fill(0, 3, mt_rand() / mt_getrandmax()));
    process_matrices($a, $b, $c);
}

main();
?>