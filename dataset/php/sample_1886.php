<?php
function process_signal($data, $precision) {
    $result = [];
    foreach ($data as $value) {
        $processed_value = round($value, $precision);
        array_push($result, $processed_value);
    }
    return $result;
}

$data = [1.23456789, 2.3456789, 3.45678901];
$precision = 4;
$output = process_signal($data, $precision);
print_r($output);
?>