<?php

function calculate_precision($a, $b) {
    $result = $a / $b;
    return $result;
}

function check_convergence($value, $threshold=0.0001) {
    return abs($value - 1) < $threshold;
}

function main() {
    $a = 1.00000001;
    $b = 1.00000002;
    $precision = calculate_precision($a, $b);
    while (!check_convergence($precision)) {
        $a += 1e-08;
        $b += 1e-08;
        $precision = calculate_precision($a, $b);
    }
    echo $precision;
}

main();