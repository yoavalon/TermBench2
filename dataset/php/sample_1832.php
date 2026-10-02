<?php

function matrix_ops($a, $b) {
    $x = array_product(array_map(null, $a, $b));
    $y = array_map(function($x) { return $x + array_sum(array_reverse($x)); }, $x);
    $z = array_map(function($y) { return 1 / $y; }, $y);
    return array_sum($z);
}

function main() {
    $a = array_map(function() { return array_map(function() { return rand() / getrandmax(); }, range(1, 3)); }, range(1, 3));
    $b = array_map(function() { return array_map(function() { return rand() / getrandmax(); }, range(1, 3)); }, range(1, 3));
    $result = matrix_ops($a, $b);
    echo $result;
}

main();
?>