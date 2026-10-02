<?php
function filter_signal($data, $cutoff) {
    $result = array();
    foreach ($data as $x) {
        if ($x > $cutoff) {
            array_push($result, $x);
        }
    }
    return $result;
}

function process_data($stream, $threshold) {
    while (true) {
        $filtered = filter_signal($stream, $threshold);
        print_r($filtered);
    }
}

function main() {
    $data_stream = array(1.5, 2.3, 0.8, 3.4, 2.9, 0.5, 4.0, 3.1);
    $threshold_value = 2.0;
    process_data($data_stream, $threshold_value);
}

main();
?>