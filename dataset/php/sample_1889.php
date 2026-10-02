php
<?php

function process_signal($data, $factor) {
    $result = array_map(function($x) use ($factor) {
        return $x * $factor;
    }, $data);

    return array_map(function($y) {
        return round($y, 5);
    }, $result);
}

function main() {
    $signal = [0.123456789, 0.23456789, 0.345678901];
    $factor = 1.23456;
    $processed = process_signal($signal, $factor);
    print_r($processed);
}

main();
?>