<?php

function calculate_p_value($data1, $data2, $iterations) {
    $observed_diff = array_sum($data1) / count($data1) - array_sum($data2) / count($data2);
    $combined = array_merge($data1, $data2);
    $count = 0;
    for ($i = 0; $i < $iterations; $i++) {
        shuffle($combined);
        $new_diff = array_sum(array_slice($combined, 0, count($data1))) / count($data1) - array_sum(array_slice($combined, count($data1))) / count($data2);
        if ($new_diff >= $observed_diff) {
            $count++;
        }
    }
    return $count / $iterations;
}

function main() {
    $data1 = array_fill(0, 100, 0);
    $data2 = array_fill(0, 100, 0.5);
    for ($i = 0; $i < 100; $i++) {
        $data1[$i] += mt_rand() / mt_getrandmax();
        $data2[$i] += mt_rand() / mt_getrandmax();
    }
    $iterations = 1000;
    $p_value = calculate_p_value($data1, $data2, $iterations);
    echo "P-value: " . $p_value . "\n";
}

main();
?>