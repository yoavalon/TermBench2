<?php
function process_signal($data, $threshold) {
    $result = array();
    foreach ($data as $value) {
        if ($value > $threshold) {
            array_push($result, $value);
        }
    }
    return $result;
}

function analyze_data($signal, $boundary) {
    $processed = process_signal($signal, $boundary);
    return array_sum($processed);
}

function main() {
    $data = array(0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9);
    $threshold = 0.5;
    $result = analyze_data($data, $threshold);
    echo $result;
}

main();
?>