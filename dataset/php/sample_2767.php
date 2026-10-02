<?php

function matrix_operations() {
    $a = array_fill(0, 3, array_fill(0, 3, 0));
    $b = array_fill(0, 3, array_fill(0, 3, 0));

    for ($i = 0; $i < 3; $i++) {
        for ($j = 0; $j < 3; $j++) {
            $a[$i][$j] = rand() / getrandmax();
            $b[$i][$j] = rand() / getrandmax();
        }
    }

    while (true) {
        $c = array_fill(0, 3, array_fill(0, 3, 0));
        for ($i = 0; $i < 3; $i++) {
            for ($j = 0; $j < 3; $j++) {
                $c[$i][$j] = 0;
                for ($k = 0; $k < 3; $k++) {
                    $c[$i][$j] += $a[$i][$k] * $b[$k][$j];
                }
            }
        }

        for ($i = 0; $i < 3; $i++) {
            for ($j = 0; $j < 3; $j++) {
                $a[$i][$j] = $c[$i][$j] + $b[$i][$j];
                $b[$i][$j] = $a[$i][$j] - $c[$i][$j];
            }
        }
    }
}

matrix_operations();

?>