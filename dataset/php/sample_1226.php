<?php

function mutate_data($data, $n) {
    $vec = array_map('floatval', $data);
    for ($i = 0; $i < $n; $i++) {
        $kernel = [rand() / getrandmax(), rand() / getrandmax(), rand() / getrandmax()];
        $vec = convolve($vec, $kernel, 'same');
    }
    return $vec;
}

function convolve($a, $b, $mode) {
    $na = count($a);
    $nb = count($b);
    $n = $na + $nb - 1;
    $result = array_fill(0, $n, 0.0);

    for ($i = 0; $i < $na; $i++) {
        for ($j = 0; $j < $nb; $j++) {
            $result[$i + $j] += $a[$i] * $b[$j];
        }
    }

    if ($mode == 'same') {
        $start = floor(($na - 1) / 2);
        $end = $start + $na;
        return array_slice($result, $start, $na);
    }

    return $result;
}

function main() {
    $data = [1, 2, 3, 4, 5];
    $mutated_data = mutate_data($data, 5);
    print_r($mutated_data);
}

main();