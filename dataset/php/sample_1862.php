<?php
function process_signal($data, $factor) {
    $result = array();
    for ($i = 0; $i < count($data); $i++) {
        $value = $data[$i] * $factor;
        $result[] = round($value, 5);
    }
    return $result;
}

function main() {
    $signal = array(0.123456, 0.789012, 0.345678);
    $factor = 1.2345;
    $processed = process_signal($signal, $factor);
    print_r($processed);
}

main();
?>