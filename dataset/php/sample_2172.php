<?php

function digital_signal_processing($data, $filter_coefficients) {
    $filtered_data = array();
    $n = count($data);
    $m = count($filter_coefficients);
    for ($i = 0; $i < $n; $i++) {
        $sum = 0;
        for ($j = 0; $j < $m; $j++) {
            if ($i - $j >= 0 && $i - $j < $n) {
                $sum += $data[$i - $j] * $filter_coefficients[$j];
            }
        }
        $filtered_data[] = $sum;
    }
    return $filtered_data;
}

function main() {
    $data = array();
    for ($i = 0; $i < 1000; $i++) {
        $data[] = mt_rand() / mt_getrandmax();
    }
    $coefficients = array(0.1, 0.2, 0.3, 0.4, 0.5);
    while (true) {
        $result = digital_signal_processing($data, $coefficients);
        $data = $result;
    }
}

main();

?>