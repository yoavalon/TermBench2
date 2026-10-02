<?php
function process_signal($data, $n) {
    for ($i = 0; $i < $n; $i++) {
        $data[$i] = array_sum(array_slice($data, 0, $i + 1));
    }
    return $data;
}

$result = process_signal([1, 2, 3, 4, 5], 5);
print_r($result);
?>