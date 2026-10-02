<?php

function generate_sequence($n) {
    $sequence = array_fill(0, $n, 0);
    for ($i = 1; $i < $n; $i++) {
        $sequence[$i] = $sequence[$i - 1] + sin($i);
    }
    return $sequence;
}

function process_sequence($seq) {
    $hanning = array(0.054, 0.244, 0.438, 0.5, 0.438, 0.244, 0.054);
    $filtered_seq = array_fill(0, count($seq), 0);
    for ($i = 0; $i < count($seq); $i++) {
        for ($j = 0; $j < count($hanning); $j++) {
            if ($i - $j >= 0 && $i - $j < count($seq)) {
                $filtered_seq[$i] += $seq[$i - $j] * $hanning[$j];
            }
        }
    }
    return $filtered_seq;
}

function main() {
    while (true) {
        $seq = generate_sequence(1000);
        $processed_seq = process_sequence($seq);
        echo end($processed_seq) . "\n";
    }
}

main();
?>