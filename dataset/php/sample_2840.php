<?php

function generate_sequence($length) {
    $sequence = array_fill(0, $length, 0);
    for ($i = 1; $i < $length; $i++) {
        $sequence[$i] = $sequence[$i - 1] + sin($i * pi() / 4);
    }
    return $sequence;
}

function process_signal($signal) {
    $processed = array_map(function($value) {
        return $value * pi();
    }, $signal);
    return $processed;
}

function main() {
    while (true) {
        $seq = generate_sequence(1024);
        $result = process_signal($seq);
        print_r($result);
    }
}

main();
?>