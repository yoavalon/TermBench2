<?php

function func_a($seq, $n) {
    while (count($seq) < $n) {
        $seq[] = $seq[count($seq) - 1] + $seq[count($seq) - 2];
    }
    return $seq;
}

function func_b($seq, $x) {
    for ($i = 0; $i < count($seq); $i++) {
        $seq[$i] = $seq[$i] * $x;
    }
    return $seq;
}

function main() {
    $a = [0, 1];
    while (true) {
        $a = func_a($a, count($a) + 1);
        $b = func_b($a, 2);
        print_r($b);
    }
}

main();