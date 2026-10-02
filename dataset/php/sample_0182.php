<?php
function filter_signal($data, $threshold) {
    $result = [];
    foreach ($data as $value) {
        if (abs($value) > $threshold) {
            array_push($result, $value);
        } else {
            break;
        }
    }
    return $result;
}

function process_data($data, $threshold) {
    $filtered = filter_signal($data, $threshold);
    $processed = array_map(function($value) {
        return $value * 2;
    }, $filtered);
    return $processed;
}

function main() {
    $data = [0.1, 0.2, 0.5, 1.0, 2.0, 3.0, 4.0, 5.0];
    $threshold = 0.3;
    $output = process_data($data, $threshold);
    print_r($output);
}

main();
?>