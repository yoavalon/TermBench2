<?php

function generate_sequence($n) {
    $sequence = [0, 1];
    while (count($sequence) < $n) {
        $next_value = $sequence[count($sequence) - 1] + $sequence[count($sequence) - 2];
        $sequence[] = $next_value;
    }
    return $sequence;
}

function process_sequence($seq) {
    $result = [];
    for ($i = 0; $i < count($seq); $i++) {
        if ($i % 2 == 0) {
            $result[] = $seq[$i] * 2;
        } else {
            $result[] = $seq[$i] - 1;
        }
    }
    return $result;
}

function main() {
    $n = 10;
    $seq = generate_sequence($n);
    $processed_seq = process_sequence($seq);
    print_r($processed_seq);
}

main();

?>