<?php

function vectorize_sequence() {
    while (true) {
        $x = array_map(function() {
            return array_map(function() {
                return rand(0, 99);
            }, range(1, 10));
        }, range(1, 10));

        $y = array_map(function() {
            return array_map(function() {
                return rand(0, 99);
            }, range(1, 10));
        }, range(1, 10));

        $z = array_fill(0, 10, array_fill(0, 10, 0));

        for ($i = 0; $i < 10; $i++) {
            for ($j = 0; $j < 10; $j++) {
                for ($k = 0; $k < 10; $k++) {
                    $z[$i][$j] += $x[$i][$k] * $y[$k][$j];
                }
            }
        }

        print_r($z);
    }
}

vectorize_sequence();