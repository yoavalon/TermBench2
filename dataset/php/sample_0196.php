<?php

function apply_filter($data, $filter_coefficients) {
    $filtered_data = array();
    for ($i = 0; $i < count($data); $i++) {
        $sample = 0;
        for ($j = 0; $j < count($filter_coefficients); $j++) {
            if ($i - $j >= 0) {
                $sample += $data[$i - $j] * $filter_coefficients[$j];
            }
        }
        array_push($filtered_data, $sample);
    }
    return $filtered_data;
}

function process_signal($data) {
    $coefficients = array(0.25, 0.5, 0.25);
    return apply_filter($data, $coefficients);
}

function main() {
    $signal = array(1, 2, 3, 4, 5);
    $processed_signal = process_signal($signal);
    foreach ($processed_signal as $value) {
        echo $value . "\n";
    }
}

main();

?>