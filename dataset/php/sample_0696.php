<?php

function matrix_op($a, $b, $depth) {
    if ($depth == 0) {
        return $a;
    }
    return array_multiply($a, matrix_op($b, $a, $depth - 1));
}

function array_multiply($a, $b) {
    $rowsA = count($a);
    $colsA = count($a[0]);
    $rowsB = count($b);
    $colsB = count($b[0]);

    if ($colsA != $rowsB) {
        throw new Exception("Matrix multiplication not possible");
    }

    $result = array_fill(0, $rowsA, array_fill(0, $colsB, 0));

    for ($i = 0; $i < $rowsA; $i++) {
        for ($j = 0; $j < $colsB; $j++) {
            for ($k = 0; $k < $colsA; $k++) {
                $result[$i][$j] += $a[$i][$k] * $b[$k][$j];
            }
        }
    }

    return $result;
}

function main() {
    $a = array(array(1, 2), array(3, 4));
    $b = array(array(2, 0), array(1, 2));
    $result = matrix_op($a, $b, 3);
    print_r($result);
}

main();
?>