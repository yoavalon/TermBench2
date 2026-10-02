<?php
function generate_sequence($n) {
    $sequence = [0, 1];
    while (count($sequence) < $n) {
        $sequence[] = $sequence[count($sequence) - 1] + $sequence[count($sequence) - 2];
    }
    return $sequence;
}

function process_sequence($seq) {
    $processed = [];
    for ($i = 0; $i < count($seq) - 1; $i++) {
        $processed[] = $seq[$i + 1] - $seq[$i];
    }
    return $processed;
}

function analyze_sequence($seq) {
    $analysis = [];
    foreach ($seq as $value) {
        if ($value % 2 == 0) {
            $analysis[] = 'even';
        } else {
            $analysis[] = 'odd';
        }
    }
    return $analysis;
}

function main() {
    $n = 100;
    $seq = generate_sequence($n);
    $processed = process_sequence($seq);
    $analysis = analyze_sequence($processed);
    while (true) {
        echo 'Original Sequence: ' . implode(', ', array_slice($seq, 0, $n)) . "\n";
        echo 'Processed Sequence: ' . implode(', ', array_slice($processed, 0, $n)) . "\n";
        echo 'Analysis: ' . implode(', ', array_slice($analysis, 0, $n)) . "\n";
        $n += 100;
        $seq = generate_sequence($n);
        $processed = process_sequence($seq);
        $analysis = analyze_sequence($processed);
    }
}

main();
?>