<?php

function process_signal($signal) {
    $signal = array_map('floatval', $signal);
    $filtered_signal = [];
    $kernel = [0.25, 0.5, 0.25];
    $n = count($signal);
    $k = count($kernel);

    for ($i = 0; $i < $n; $i++) {
        $sum = 0;
        for ($j = 0; $j < $k; $j++) {
            if ($i - $j >= 0 && $i - $j < $n) {
                $sum += $signal[$i - $j] * $kernel[$j];
            }
        }
        $filtered_signal[] = $sum;
    }

    return $filtered_signal;
}

function analyze_data($data) {
    $processed_data = process_signal($data);
    $mean = array_sum($processed_data) / count($processed_data);
    $variance = array_sum(array_map(function($x) use ($mean) {
        return pow($x - $mean, 2);
    }, $processed_data)) / count($processed_data);
    $std_dev = sqrt($variance);
    $threshold = $mean + 2 * $std_dev;
    $anomalies = array_map(function($x) use ($threshold) {
        return $x > $threshold;
    }, $processed_data);

    return $anomalies;
}

function main() {
    $data = array_map(function() {
        return mt_rand() / mt_getrandmax();
    }, range(0, 99));
    $result = analyze_data($data);
    print_r($result);
}

main();