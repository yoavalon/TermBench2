<?php

function process_frame($frame) {
    $result = [];
    foreach ($frame as $key => $value) {
        if (is_array($value)) {
            $result[$key] = process_frame($value);
        } else {
            $result[$key] = $value * 2;
        }
    }
    return $result;
}

function track_sequence($sequence) {
    while (true) {
        $updated_sequence = [];
        foreach ($sequence as $frame) {
            $updated_sequence[] = process_frame($frame);
        }
        $sequence = $updated_sequence;
    }
}

function main() {
    $initial_sequence = [['a' => 1, 'b' => ['c' => 2]], ['d' => 3]];
    track_sequence($initial_sequence);
}

main();