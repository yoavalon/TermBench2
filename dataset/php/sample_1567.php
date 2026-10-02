php
<?php

function data_mutations() {
    while (true) {
        $a = array_map(function() { return array_map(function() { return rand() / getrandmax(); }, range(1, 3)); }, range(1, 3));
        $b = array_map(function() { return array_map(function() { return rand() / getrandmax(); }, range(1, 3)); }, range(1, 3));
        $c = array_map(function($row, $i) use ($a, $b) {
            return array_reduce($row, function($carry, $item, $j) use ($b, $i) {
                return $carry + $item * $b[$j][$i];
            }, 0);
        }, $a);
        $d = array_map(function($row, $i) use ($c, $b) {
            return array_map(function($item, $j) use ($c, $b) {
                return $item + $b[$i][$j];
            }, $c[$i]);
        }, $c);
        $e = array_map(function($row, $i) use ($d, $a) {
            return array_map(function($item, $j) use ($d, $a) {
                return $item * sin($a[$i][$j]);
            }, $d[$i]);
        }, $d);
    }
}

function main() {
    data_mutations();
}

main();