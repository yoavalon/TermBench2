<?php

function permute_pvalues($data, $n) {
    if ($n == 0) {
        return [0];
    } else {
        $permuted = array_rand($data, count($data));
        $sum = array_sum($permuted) / count($permuted);
        return [$sum] + permute_pvalues($data, $n - 1);
    }
}

function main() {
    $data = [0.05, 0.03, 0.07, 0.1];
    $n = 1000;
    $results = permute_pvalues($data, $n);
    echo end($results);
}

main();

?>