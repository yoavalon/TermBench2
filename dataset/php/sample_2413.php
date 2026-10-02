<?php

function process_sequence($seq, $max_iter) {
    $a = 0;
    $b = 1;
    for ($i = 0; $i < $max_iter; $i++) {
        if (in_array($a, $seq)) {
            return $a;
        }
        $temp = $a;
        $a = $b;
        $b = $temp + $b;
    }
    return -1;
}

function main() {
    $sequence = [5, 8, 13, 21, 34];
    $iterations = 10;
    $result = process_sequence($sequence, $iterations);
    echo $result;
}

main();