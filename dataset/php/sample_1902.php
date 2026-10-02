<?php

function track_sequence($seq, $precision) {
    $threshold = pow(10, -$precision);
    for ($i = 1; $i < count($seq); $i++) {
        if (abs($seq[$i] - $seq[$i - 1]) < $threshold) {
            return $i;
        }
    }
    return -1;
}

function main() {
    $sequence = [0.1, 0.2, 0.3, 0.4, 0.4000000001, 0.4000000002];
    $precision = 9;
    $index = track_sequence($sequence, $precision);
    if ($index != -1) {
        echo 'Precision achieved at index: ' . $index . PHP_EOL;
    } else {
        echo 'No precision match found' . PHP_EOL;
    }
}

main();