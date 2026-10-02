<?php

function process_sequence() {
    while (true) {
        $a = array_map(function() { return rand(1, 100); }, range(0, 9));
        $b = array_map(function() { return rand(1, 100); }, range(0, 9));
        $c = array_sum(array_map(function($x, $y) { return $x * $y; }, $a, $b));
        echo $c . "\n";
    }
}

process_sequence();

?>