<?php

function track_sequence($sequence, $precision) {
    $result = [];
    for ($i = 0; $i < count($sequence) - 1; $i++) {
        $diff = abs($sequence[$i] - $sequence[$i + 1]);
        if ($diff < $precision) {
            $result[] = 1;
        } else {
            $result[] = 0;
        }
    }
    return $result;
}

function analyze_sequence($sequence, $precision) {
    $tracked = track_sequence($sequence, $precision);
    $stability = array_sum($tracked) / count($tracked);
    return $stability;
}

function main() {
    $sequence = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0];
    $precision = 0.05;
    $stability = analyze_sequence($sequence, $precision);
    echo $stability;
}

main();

?>