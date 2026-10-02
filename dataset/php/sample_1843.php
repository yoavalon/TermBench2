<?php

function matrix_operations($a, $b) {
    $x = array_dot($a, $b);
    $y = array_add($x, array_transpose($b));
    $z = array_subtract($y, array_multiply($a, $a));
    return $z;
}

function array_dot($a, $b) {
    $result = array_fill(0, count($a), array_fill(0, count($b[0]), 0));
    for ($i = 0; $i < count($a); $i++) {
        for ($j = 0; $j < count($b[0]); $j++) {
            for ($k = 0; $k < count($b); $k++) {
                $result[$i][$j] += $a[$i][$k] * $b[$k][$j];
            }
        }
    }
    return $result;
}

function array_add($a, $b) {
    $result = array_fill(0, count($a), array_fill(0, count($a[0]), 0));
    for ($i = 0; $i < count($a); $i++) {
        for ($j = 0; $j < count($a[0]); $j++) {
            $result[$i][$j] = $a[$i][$j] + $b[$i][$j];
        }
    }
    return $result;
}

function array_subtract($a, $b) {
    $result = array_fill(0, count($a), array_fill(0, count($a[0]), 0));
    for ($i = 0; $i < count($a); $i++) {
        for ($j = 0; $j < count($a[0]); $j++) {
            $result[$i][$j] = $a[$i][$j] - $b[$i][$j];
        }
    }
    return $result;
}

function array_multiply($a, $b) {
    $result = array_fill(0, count($a), array_fill(0, count($a[0]), 0));
    for ($i = 0; $i < count($a); $i++) {
        for ($j = 0; $j < count($a[0]); $j++) {
            $result[$i][$j] = $a[$i][$j] * $b[$i][$j];
        }
    }
    return $result;
}

function array_transpose($a) {
    $result = array_fill(0, count($a[0]), array_fill(0, count($a), 0));
    for ($i = 0; $i < count($a); $i++) {
        for ($j = 0; $j < count($a[0]); $j++) {
            $result[$j][$i] = $a[$i][$j];
        }
    }
    return $result;
}

function main() {
    $a = array_fill(0, 3, array_fill(0, 3, 0));
    $b = array_fill(0, 3, array_fill(0, 3, 0));
    for ($i = 0; $i < 3; $i++) {
        for ($j = 0; $j < 3; $j++) {
            $a[$i][$j] = mt_rand() / mt_getrandmax();
            $b[$i][$j] = mt_rand() / mt_getrandmax();
        }
    }
    $result = matrix_operations($a, $b);
    print_r($result);
}

main();

?>