<?php
function process_signal($data) {
    $n = count($data);
    $result = array_fill(0, $n, 0);
    for ($i = 0; $i < $n; $i++) {
        for ($j = 0; $j <= $i; $j++) {
            $result[$i] += $data[$j];
        }
    }
    return $result;
}
$data = [1, 2, 3, 4, 5];
$output = process_signal($data);
print_r($output);
?>