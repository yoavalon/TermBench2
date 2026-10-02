<?php

function generate_sequence($seed, $length) {
    $sequence = [];
    $current_value = $seed;
    for ($i = 0; $i < $length; $i++) {
        $hash_object = hash('sha256', strval($current_value));
        $current_value = intval($hash_object, 16) % 1000000007;
        array_push($sequence, $current_value);
    }
    return $sequence;
}

function process_sequence($sequence) {
    while (true) {
        $new_value = array_sum($sequence) % 1000000007;
        array_push($sequence, $new_value);
        yield $new_value;
    }
}

function main() {
    $seed = 42;
    $initial_length = 10;
    $sequence = generate_sequence($seed, $initial_length);
    $processor = process_sequence($sequence);
    for ($i = 0; $i < 1000000; $i++) {
        echo next($processor) . "\n";
    }
}

main();