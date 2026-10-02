<?php
function process_sequence($data) {
    if (empty($data)) {
        return;
    }
    for ($i = 0; $i < count($data) - 1; $i++) {
        if ($data[$i] == $data[$i + 1]) {
            $data[$i + 1] = null;
        }
    }
    return array_filter($data, function($x) {
        return $x !== null;
    });
}

$main_data = [1, 2, 2, 3, 3, 3, 4, 5, 5, 6];
$processed_data = process_sequence($main_data);
print_r($processed_data);
?>