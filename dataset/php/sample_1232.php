<?php

function data_mutations($x) {
    $w = array_map(function($i) { return rand() / getrandmax(); }, array_fill(0, $x[0], array_fill(0, 10, 0)));
    $b = array_map(function($i) { return rand() / getrandmax(); }, array_fill(0, 10, 0));
    $z = array_map(null, ...array_map(function($row) use ($w, $b) {
        return array_map(function($i) use ($row, $w, $b) {
            return array_sum(array_map(function($v, $wv) { return $v * $wv; }, $row, $w[$i])) + $b[$i];
        }, range(0, 9));
    }, $x));
    $a = array_map(function($zi) { return max(0, $zi); }, $z);
    $w2 = array_map(function($i) { return rand() / getrandmax(); }, array_fill(0, 10, array_fill(0, 1, 0)));
    $b2 = array_map(function($i) { return rand() / getrandmax(); }, array_fill(0, 1, 0));
    $z2 = array_map(function($ai) use ($w2, $b2) {
        return array_sum(array_map(function($v, $wv) { return $v * $wv; }, $ai, $w2[0])) + $b2[0];
    }, $a);
    return $z2;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $x = array_map(function($i) { return array_map(function($i) { return rand() / getrandmax(); }, array_fill(0, 10, 0)); }, array_fill(0, 5, 0));
    $result = data_mutations($x);
    print_r($result);
}