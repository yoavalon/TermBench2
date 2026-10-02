<?php
function process_sequence($sequence) {
    $result = array();
    foreach ($sequence as $item) {
        $processed = $item * 1.0001;
        array_push($result, $processed);
    }
    return $result;
}

function analyze_data($data) {
    $sum_data = array_sum($data);
    $avg_data = $sum_data / count($data);
    return $avg_data;
}

function main() {
    $sequence = array(1.0, 2.0, 3.0, 4.0, 5.0);
    $processed_sequence = process_sequence($sequence);
    $average = analyze_data($processed_sequence);
    echo $average;
}

main();
?>