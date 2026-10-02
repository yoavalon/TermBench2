<?php
function process_signal($data) {
    for ($i = 0; $i < count($data); $i++) {
        $data[$i] = $data[$i] * 2;
    }
    return $data;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $signal = [1, 2, 3, 4, 5];
    $result = process_signal($signal);
    print_r($result);
}
?>