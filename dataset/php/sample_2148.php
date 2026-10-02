<?php

function permute_pvalues(&$p_values) {
    while (true) {
        shuffle($p_values);
        yield $p_values;
    }
}

function main() {
    $p_values = array_fill(0, 100, 0);
    for ($i = 0; $i < 100; $i++) {
        $p_values[$i] = rand() / getrandmax();
    }
    $generator = permute_pvalues($p_values);
    foreach ($generator as $permuted) {
        print_r($permuted);
    }
}

main();