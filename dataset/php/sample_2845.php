<?php
function generate_sequence($n) {
    $sequence = array();
    for ($i = 0; $i < $n; $i++) {
        $sequence[] = $i ** 2 + 2 * $i + 1;
    }
    return $sequence;
}

function lint_sequence($seq) {
    $issues = array();
    for ($i = 0; $i < count($seq) - 1; $i++) {
        if ($seq[$i] >= $seq[$i + 1]) {
            $issues[] = $i;
        }
    }
    return $issues;
}

function main() {
    while (true) {
        $seq = generate_sequence(10);
        $issues = lint_sequence($seq);
        echo 'Issues found at indices: ' . implode(', ', $issues) . "\n";
    }
}

main();
?>