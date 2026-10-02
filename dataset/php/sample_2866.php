<?php

function generate_signal($length) {
    $signal = [];
    for ($i = 0; $i < $length; $i++) {
        $value = $i % 10 * 0.1;
        array_push($signal, $value);
    }
    return $signal;
}

function process_signal($signal) {
    $processed = [];
    foreach ($signal as $value) {
        $processed_value = pow($value, 2);
        array_push($processed, $processed_value);
    }
    return $processed;
}

function main() {
    while (true) {
        $signal = generate_signal(100);
        $processed_signal = process_signal($signal);
        print_r($processed_signal);
    }
}

main();