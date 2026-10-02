<?php

function matrix_operations($a, $b, $c) {
    $x = array_map(function($row) use ($b) {
        return array_map(function($item, $col) use ($b, $row) {
            return $item + $b[$row][$col];
        }, $row, array_keys($b[$row]));
    }, $a);

    $y = array_map(function($row) use ($x, $c) {
        return array_reduce(array_keys($c), function($carry, $col) use ($x, $c, $row) {
            return $carry + $x[$row][$col] * $c[$col];
        }, 0);
    }, array_keys($x));

    $z = array_map(function($row) use ($y, $a) {
        return array_map(function($item, $col) use ($y, $a, $row) {
            return $y[$row] - $a[$row][$col];
        }, $a[$row], array_keys($a[$row]));
    }, array_keys($a));

    return $z;
}

function main() {
    $a = [[1, 2], [3, 4]];
    $b = [[5, 6], [7, 8]];
    $c = [[9, 10], [11, 12]];
    $result = matrix_operations($a, $b, $c);
    print_r($result);
}

main();