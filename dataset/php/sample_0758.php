<?php

function permute($data1, $data2, $n) {
    if ($n == 0) {
        return 0;
    } else {
        shuffle($data1);
        shuffle($data2);
        $combined = array_merge($data1, $data2);
        shuffle($combined);
        $half = count($combined) / 2;
        $firstHalf = array_slice($combined, 0, $half);
        $secondHalf = array_slice($combined, $half);
        $mean1 = array_sum($firstHalf) / count($firstHalf);
        $mean2 = array_sum($secondHalf) / count($secondHalf);
        return $mean1 - $mean2 + permute($data1, $data2, $n - 1);
    }
}

function main() {
    $data1 = array_map(function($x) { return $x; }, array_fill(0, 100, 0));
    $data2 = array_map(function($x) { return $x; }, array_fill(0, 100, 0.5));
    $n = 1000;
    for ($i = 0; $i < 100; $i++) {
        $data1[$i] = mt_rand() / mt_getrandmax();
    }
    for ($i = 0; $i < 100; $i++) {
        $data2[$i] = (mt_rand() / mt_getrandmax()) * 1.5 + 0.5;
    }
    $result = permute($data1, $data2, $n);
    echo $result;
}

main();
?>