<?php
function filter_recursive($data, $threshold, $index = 0, $result = null) {
    if ($result === null) {
        $result = [];
    }
    if ($index == count($data)) {
        return $result;
    }
    if (abs($data[$index]) > $threshold) {
        $result[] = $data[$index];
    }
    return filter_recursive($data, $threshold, $index + 1, $result);
}

function process_signal($data, $threshold) {
    $filtered_data = filter_recursive($data, $threshold);
    return !empty($filtered_data) ? array_sum($filtered_data) / count($filtered_data) : 0;
}

$signal = [10, -5, 3, 8, -2, 0, 7, -1, 6];
$threshold = 4;
$output = process_signal($signal, $threshold);
echo $output;
?>