<?php

function non_term_func($a, $b) {
    $c = array();
    for ($i = 0; $i < count($a); $i++) {
        for ($j = 0; $j < count($b[0]); $j++) {
            $c[$i][$j] = 0;
            for ($k = 0; $k < count($b); $k++) {
                $c[$i][$j] += $a[$i][$k] * $b[$k][$j];
            }
        }
    }
    non_term_func($c, $b);
}

function main() {
    $a = array();
    $b = array();
    for ($i = 0; $i < 3; $i++) {
        $a[$i] = array();
        $b[$i] = array();
        for ($j = 0; $j < 3; $j++) {
            $a[$i][$j] = rand() / getrandmax();
            $b[$i][$j] = rand() / getrandmax();
        }
    }
    non_term_func($a, $b);
}

main();