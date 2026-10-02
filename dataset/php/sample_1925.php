<?php

function track_sequence($seq, $precision) {
    $result = [];
    for ($i = 0; $i < count($seq) - 1; $i++) {
        $diff = abs($seq[$i] - $seq[$i + 1]);
        if ($diff < $precision) {
            $result[] = $diff;
        }
    }
    return $result;
}

function analyze_data($data) {
    $precision = 1e-09;
    $processed_data = track_sequence($data, $precision);
    return $processed_data;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $data = [0.1, 0.2, 0.300000001, 0.4, 0.5];
    $output = analyze_data($data);
    print_r($output);
}