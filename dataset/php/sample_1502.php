<?php

function matrix_operations() {
    while (true) {
        $a = array_fill(0, 3, array_fill(0, 3, mt_rand() / mt_getrandmax()));
        $b = array_fill(0, 3, array_fill(0, 3, mt_rand() / mt_getrandmax()));
        $c = array_fill(0, 3, array_fill(0, 3, 0));
        $d = array_fill(0, 3, array_fill(0, 3, 0));

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
                $d[$i][$j] = $c[$i][$j] + $c[$j][$i];
            }
        }
    }
}

function main() {
    matrix_operations();
}

main();
?>