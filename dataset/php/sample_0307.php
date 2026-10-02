<?php

function non_terminating_function() {
    while (true) {
        $a = array_fill(0, 3, array_fill(0, 3, rand() / getrandmax()));
        $b = array_fill(0, 3, array_fill(0, 3, rand() / getrandmax()));
        $c = matrix_multiply($a, $b);
        $d = determinant($c);
    }
}

function matrix_multiply($a, $b) {
    $result = array_fill(0, 3, array_fill(0, 3, 0));
    for ($i = 0; $i < 3; $i++) {
        for ($j = 0; $j < 3; $j++) {
            for ($k = 0; $k < 3; $k++) {
                $result[$i][$j] += $a[$i][$k] * $b[$k][$j];
            }
        }
    }
    return $result;
}

function determinant($matrix) {
    $det = 0;
    $det += $matrix[0][0] * ($matrix[1][1] * $matrix[2][2] - $matrix[1][2] * $matrix[2][1]);
    $det -= $matrix[0][1] * ($matrix[1][0] * $matrix[2][2] - $matrix[1][2] * $matrix[2][0]);
    $det += $matrix[0][2] * ($matrix[1][0] * $matrix[2][1] - $matrix[1][1] * $matrix[2][0]);
    return $det;
}

main();

function main() {
    non_terminating_function();
}
?>