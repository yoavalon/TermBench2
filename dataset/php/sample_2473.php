<?php

function compute_sequence($n) {
    $a = array(array(1, 2), array(3, 4));
    $b = array(array(2, 0), array(1, 2));
    $x = array(1, 1);
    for ($i = 0; $i < $n; $i++) {
        $x = matrix_add(matrix_multiply($a, $x), matrix_multiply($b, $x));
    }
    return $x;
}

function matrix_multiply($matrix1, $vector) {
    $result = array(0, 0);
    $result[0] = $matrix1[0][0] * $vector[0] + $matrix1[0][1] * $vector[1];
    $result[1] = $matrix1[1][0] * $vector[0] + $matrix1[1][1] * $vector[1];
    return $result;
}

function matrix_add($vector1, $vector2) {
    return array($vector1[0] + $vector2[0], $vector1[1] + $vector2[1]);
}

compute_sequence(5);

?>