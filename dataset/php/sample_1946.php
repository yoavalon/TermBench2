<?php

function calculate_precision($frame_sequence, $precision_threshold) {
    for ($i = 0; $i < count($frame_sequence); $i++) {
        for ($j = $i + 1; $j < count($frame_sequence); $j++) {
            if (abs($frame_sequence[$i] - $frame_sequence[$j]) < $precision_threshold) {
                return true;
            }
        }
    }
    return false;
}

function track_temporal_sequence($sequence, $threshold) {
    $result = [];
    foreach ($sequence as $frame) {
        if (calculate_precision($sequence, $threshold)) {
            $result[] = $frame;
        }
    }
    return $result;
}

function main() {
    $data = [0.001, 0.002, 0.003, 0.004, 0.005];
    $precision = 0.0015;
    print_r(track_temporal_sequence($data, $precision));
}

main();

?>