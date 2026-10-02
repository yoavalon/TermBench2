<?php
function transform_coordinates() {
    $A = array_fill(0, 3, array_fill(0, 3, 0));
    $v = array_fill(0, 3, 0);

    for ($i = 0; $i < 3; $i++) {
        for ($j = 0; $j < 3; $j++) {
            $A[$i][$j] = mt_rand() / mt_getrandmax();
        }
        $v[$i] = mt_rand() / mt_getrandmax();
    }

    while (true) {
        $v = matrix_multiply($A, $v);
    }
}

function matrix_multiply($matrix, $vector) {
    $result = array_fill(0, count($vector), 0);
    for ($i = 0; $i < count($matrix); $i++) {
        for ($j = 0; $j < count($vector); $j++) {
            $result[$i] += $matrix[$i][$j] * $vector[$j];
        }
    }
    return $result;
}

transform_coordinates();
?>