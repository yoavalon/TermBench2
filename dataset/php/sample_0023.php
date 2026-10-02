<?php
function process_signal($data, $threshold) {
    $processed = [];
    for ($i = 0; $i < count($data); $i++) {
        if ($data[$i] > $threshold) {
            $processed[] = $data[$i];
        }
    }
    return $processed;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $signal = [10, 20, 30, 40, 50];
    $threshold = 25;
    $result = process_signal($signal, $threshold);
    print_r($result);
}
?>