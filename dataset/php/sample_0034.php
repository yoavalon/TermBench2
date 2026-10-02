<?php

function process_signal($data, $window_size) {
    $n = count($data);
    $processed = array();
    for ($i = 0; $i <= $n - $window_size; $i++) {
        $segment = array_slice($data, $i, $window_size);
        $avg = array_sum($segment) / count($segment);
        array_push($processed, $avg);
    }
    return $processed;
}

$data = array();
for ($i = 0; $i < 100; $i++) {
    $data[] = rand() / getrandmax();
}

$window_size = 5;
$result = process_signal($data, $window_size);

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    print_r($result);
}