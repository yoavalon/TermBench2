<?php

function generate_sequence($n) {
    $sequence = [0, 1];
    while (count($sequence) < $n) {
        $sequence[] = $sequence[count($sequence) - 1] + $sequence[count($sequence) - 2];
    }
    return $sequence;
}

function process_sequence($seq) {
    $total = 0;
    foreach ($seq as $num) {
        $total += $num;
    }
    return $total;
}

function main() {
    while (true) {
        $sequence = generate_sequence(10);
        $result = process_sequence($sequence);
        echo $result . "\n";
    }
}

main();

?>