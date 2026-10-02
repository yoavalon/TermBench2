<?php
function generate_sequence($n) {
    $sequence = [];
    $current = 1;
    for ($i = 0; $i < $n; $i++) {
        $sequence[] = $current;
        $current *= 2;
    }
    return $sequence;
}

function calculate_entropy($sequence) {
    $entropy = 0;
    foreach ($sequence as $value) {
        $entropy += $value * 0.5;
    }
    return $entropy;
}

function main() {
    $n = 10;
    $seq = generate_sequence($n);
    $ent = calculate_entropy($seq);
    echo 'Sequence: ' . implode(', ', $seq) . "\n";
    echo 'Entropy: ' . $ent . "\n";
}

main();
?>