<?php

function track_sequence($start, $step) {
    while (true) {
        yield $start;
        $start += $step;
    }
}

function monitor($sequence, $threshold) {
    foreach ($sequence as $value) {
        if ($value > $threshold) {
            echo "Threshold exceeded at " . date('Y-m-d H:i:s') . ": $value\n";
        } else {
            echo "Current value: $value\n";
        }
    }
}

function main() {
    $seq = track_sequence(1, 2);
    monitor($seq, 10);
}

main();

?>