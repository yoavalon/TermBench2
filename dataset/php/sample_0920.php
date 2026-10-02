<?php

function recursive_filter($x, $a, $b) {
    return [recursive_filter(array_slice($x, 1), $a, $b)] + [$a[0] * $x[0] + array_sum(array_map(function($val, $index) use ($a, $x, $b) {
        return $val * recursive_filter(array_slice($x, 1), $a, $b)[$index];
    }, array_slice($a, 1), array_keys(array_slice($x, 1)))) - array_sum(array_map(function($val, $index) use ($b, $x, $a) {
        return $val * recursive_filter(array_slice($x, 1), $a, $b)[$index];
    }, array_slice($b, 1), array_keys(array_slice($x, 1))))];
}

function main() {
    $x = array_map(function($unused) { return mt_rand() / mt_getrandmax(); }, range(1, 100));
    $a = [1, -0.5];
    $b = [1, -0.3];
    recursive_filter($x, $a, $b);
}

main();

?>