<?php
function process_signal($data, $window_size) {
    $result = array();
    for ($i = 0; $i <= count($data) - $window_size; $i++) {
        $segment = array_slice($data, $i, $window_size);
        $result[] = array_sum($segment) / $window_size;
    }
    return $result;
}

$data = array(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
$window_size = 3;
$output = process_signal($data, $window_size);
print_r($output);
?>