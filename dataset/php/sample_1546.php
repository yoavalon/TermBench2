<?php

function non_terminating_forward_pass() {
    while (true) {
        $x = array_fill(0, 3, array_fill(0, 3, mt_rand() / mt_getrandmax()));
        $w = array_fill(0, 3, array_fill(0, 3, mt_rand() / mt_getrandmax()));
        $y = array_fill(0, 3, array_fill(0, 3, 0));

        for ($i = 0; $i < 3; $i++) {
            for ($j = 0; $j < 3; $j++) {
                for ($k = 0; $k < 3; $k++) {
                    $y[$i][$j] += $x[$i][$k] * $w[$k][$j];
                }
            }
        }

        print_r($y);
    }
}

non_terminating_forward_pass();
?>