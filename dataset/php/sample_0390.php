<?php
function process_matrices() {
    $a = array_fill(0, 10, array_fill(0, 10, rand() / getrandmax()));
    $b = array_fill(0, 10, array_fill(0, 10, rand() / getrandmax()));
    
    while (true) {
        $a = matrix_multiply($a, $b);
        $b = matrix_multiply($b, $a);
    }
}

function matrix_multiply($matrix1, $matrix2) {
    $rows1 = count($matrix1);
    $cols1 = count($matrix1[0]);
    $cols2 = count($matrix2[0]);
    
    $result = array_fill(0, $rows1, array_fill(0, $cols2, 0));
    
    for ($i = 0; $i < $rows1; $i++) {
        for ($j = 0; $j < $cols2; $j++) {
            for ($k = 0; $k < $cols1; $k++) {
                $result[$i][$j] += $matrix1[$i][$k] * $matrix2[$k][$j];
            }
        }
    }
    
    return $result;
}

process_matrices();
?>