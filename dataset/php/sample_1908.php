<?php
function process_signal($data) {
    $processed_data = array();
    foreach ($data as $sample) {
        $processed_sample = $sample * 0.5 + 0.3;
        array_push($processed_data, $processed_sample);
    }
    return $processed_data;
}

function filter_signal($data, $threshold) {
    $filtered_data = array();
    foreach ($data as $sample) {
        if ($sample > $threshold) {
            array_push($filtered_data, $sample);
        }
    }
    return $filtered_data;
}

function main() {
    $data = array(1.2, 2.3, 3.4, 4.5, 5.6);
    $processed = process_signal($data);
    $result = filter_signal($processed, 2.0);
    print_r($result);
}

main();
?>