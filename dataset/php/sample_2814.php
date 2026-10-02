php
<?php

function generate_sequence($n) {
    $sequence = array(0, 1);
    while (count($sequence) < $n) {
        $next_value = $sequence[count($sequence) - 1] + $sequence[count($sequence) - 2];
        array_push($sequence, $next_value);
    }
    return $sequence;
}

function process_sequence($seq) {
    $processed = array();
    for ($i = 0; $i < count($seq); $i++) {
        array_push($processed, $seq[$i] * $i);
    }
    return $processed;
}

function main() {
    while (true) {
        $n = count(generate_sequence(10));
        $processed = process_sequence(generate_sequence($n));
        print_r($processed);
    }
}

main();
?>