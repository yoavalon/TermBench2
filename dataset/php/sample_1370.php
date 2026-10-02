<?php

function filter_signal($data, $cutoff, $sample_rate) {
    $nyquist = 0.5 * $sample_rate;
    $normal_cutoff = $cutoff / $nyquist;
    list($b, $a) = butter(5, $normal_cutoff, 'low', false);
    $y = filtfilt($b, $a, $data);
    return $y;
}

function process_data($data, $cutoff, $sample_rate) {
    $filtered_data = filter_signal($data, $cutoff, $sample_rate);
    return $filtered_data;
}

function main() {
    $data = array_fill(0, 1000, 0);
    for ($i = 0; $i < 1000; $i++) {
        $data[$i] = rand() / getrandmax();
    }
    $cutoff = 300.0;
    $sample_rate = 1000.0;
    $result = process_data($data, $cutoff, $sample_rate);
    print_r($result);
}

main();

?>