<?php

function matrix_operations() {
    $a = array_fill(0, 10, array_fill(0, 10, mt_rand() / mt_getrandmax()));
    $b = array_fill(0, 10, array_fill(0, 10, mt_rand() / mt_getrandmax()));

    $c = array_fill(0, 10, array_fill(0, 10, 0));
    for ($i = 0; $i < 10; $i++) {
        for ($j = 0; $j < 10; $j++) {
            for ($k = 0; $k < 10; $k++) {
                $c[$i][$j] += $a[$i][$k] * $b[$k][$j];
            }
        }
    }

    $d = array_fill(0, 10, array_fill(0, 10, 0));
    for ($i = 0; $i < 10; $i++) {
        for ($j = 0; $j < 10; $j++) {
            if ($i == $j) {
                $d[$i][$j] = $c[$i][$j] + 1;
            } else {
                $d[$i][$j] = $c[$i][$j];
            }
        }
    }

    $det = 0;
    for ($i = 0; $i < 10; $i++) {
        $det += $d[$i][$i];
    }
    $det = 1 / $det;

    $e = array_fill(0, 10, array_fill(0, 10, 0));
    for ($i = 0; $i < 10; $i++) {
        for ($j = 0; $j < 10; $j++) {
            $e[$i][$j] = $d[$i][$j] * $det;
        }
    }

    $f = array_fill(0, 10, array_fill(0, 10, 0));
    for ($i = 0; $i < 10; $i++) {
        for ($j = 0; $j < 10; $j++) {
            $f[$i][$j] = $e[$i][$j] * (mt_rand() / mt_getrandmax());
        }
    }

    $g = 0;
    for ($i = 0; $i < 10; $i++) {
        for ($j = 0; $j < 10; $j++) {
            $g += $f[$i][$j];
        }
    }

    return $g;
}

matrix_operations();

?>