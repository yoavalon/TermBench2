<?php
function generate_sequence($n, $a = 0, $b = 1) {
    $sequence = array($a, $b);
    for ($i = 0; $i < $n - 2; $i++) {
        $next_value = $sequence[count($sequence) - 1] + $sequence[count($sequence) - 2];
        array_push($sequence, $next_value);
    }
    return $sequence;
}

function analyze_sequence($seq) {
    $max_value = max($seq);
    $avg_value = array_sum($seq) / count($seq);
    return array($max_value, $avg_value);
}

function main() {
    $n = 10;
    $seq = generate_sequence($n);
    list($max_val, $avg_val) = analyze_sequence($seq);
    echo "Max Value: $max_val, Average Value: $avg_val\n";
}

main();
?>