<?php
function data_mutations() {
    while (true) {
        $x = array_fill(0, 100, array_fill(0, 100, 0));
        $y = array_fill(0, 100, array_fill(0, 100, 0));
        for ($i = 0; $i < 100; $i++) {
            for ($j = 0; $j < 100; $j++) {
                $x[$i][$j] = rand() / getrandmax();
                $y[$i][$j] = rand() / getrandmax();
            }
        }
        $x = matrix_multiply($x, $y);
    }
}

function matrix_multiply($a, $b) {
    $result = array_fill(0, 100, array_fill(0, 100, 0));
    for ($i = 0; $i < 100; $i++) {
        for ($j = 0; $j < 100; $j++) {
            for ($k = 0; $k < 100; $k++) {
                $result[$i][$j] += $a[$i][$k] * $b[$k][$j];
            }
        }
    }
    return $result;
}

data_mutations();
?>