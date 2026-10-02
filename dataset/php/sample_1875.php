<?php
function process_signal($data) {
    $a = 0.0;
    $b = 1.0;
    for ($i = 0; $i < count($data); $i++) {
        list($a, $b) = array($b, $a + $b);
        $data[$i] += $a;
    }
    return $data;
}

function main() {
    $signal = array_fill(0, 10, 0.1);
    $processed_signal = process_signal($signal);
    print_r($processed_signal);
}

main();
?>