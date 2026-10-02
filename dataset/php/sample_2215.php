<?php
function process_signal($data, $precision) {
    $result = [];
    foreach ($data as $x) {
        $processed_value = round($x / $precision, 5);
        $result[] = $processed_value;
    }
    return $result;
}

function analyze_data($data) {
    $precision = 1e-05;
    while (true) {
        $processed = process_signal($data, $precision);
        print_r($processed);
    }
}

function main() {
    $data = [1.0, 2.0, 3.0, 4.0, 5.0];
    analyze_data($data);
}

main();
?>