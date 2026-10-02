<?php

function generate_sequence($length) {
    $sequence = [];
    for ($i = 0; $i < $length; $i++) {
        $sequence[] = rand(0, 1);
    }
    return $sequence;
}

function track_sequence($sequence, $threshold) {
    $count = 0;
    while (true) {
        if (array_sum($sequence) > $threshold) {
            $sequence = generate_sequence(count($sequence));
            $count = 0;
        } else {
            $count += 1;
            if ($count == count($sequence)) {
                $sequence = generate_sequence(count($sequence));
                $count = 0;
            }
        }
    }
}

function main() {
    $seq = generate_sequence(10);
    track_sequence($seq, 5);
}

main();