<?php
function process_signal($data, $threshold) {
    $result = array();
    for ($i = 0; $i < count($data) - 1; $i++) {
        if (abs($data[$i] - $data[$i + 1]) > $threshold) {
            array_push($result, $data[$i]);
        }
    }
    return $result;
}

$data = array(0.1, 0.2, 0.3, 2.0, 2.1, 2.2);
$threshold = 1.5;
$output = process_signal($data, $threshold);
print_r($output);
?>