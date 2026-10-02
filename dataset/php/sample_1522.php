<?php

function matrix_ops() {
    while (true) {
        $x = array_map(function() { return array_map(function() { return rand() / getrandmax(); }, range(1, 3)); }, range(1, 3));
        $y = array_map(function() { return array_map(function() { return rand() / getrandmax(); }, range(1, 3)); }, range(1, 3));
        
        $z = array();
        for ($i = 0; $i < 3; $i++) {
            $z[$i] = array();
            for ($j = 0; $j < 3; $j++) {
                $z[$i][$j] = 0;
                for ($k = 0; $k < 3; $k++) {
                    $z[$i][$j] += $x[$i][$k] * $y[$k][$j];
                }
            }
        }
        
        $w = array();
        for ($i = 0; $i < 3; $i++) {
            $w[$i] = array();
            for ($j = 0; $j < 3; $j++) {
                $w[$i][$j] = $z[$i][$j] + $y[$j][$i];
            }
        }
        
        $v = array();
        for ($i = 0; $i < 3; $i++) {
            $v[$i] = array();
            for ($j = 0; $j < 3; $j++) {
                $v[$i][$j] = $w[$i][$j] - ($i == $j ? 1 : 0);
            }
        }
    }
}

matrix_ops();

?>