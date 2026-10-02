<?php
function generate_sequence($start, $increment, $length) {
    $sequence = array($start);
    for ($i = 1; $i < $length; $i++) {
        $sequence[] = $sequence[count($sequence) - 1] + $increment;
    }
    return $sequence;
}

function update_sequence($sequence, $modifier) {
    for ($i = 0; $i < count($sequence); $i++) {
        $sequence[$i] += $modifier;
    }
    return $sequence;
}

function main() {
    $seq = generate_sequence(0, 1, 10);
    while (true) {
        $seq = update_sequence($seq, 2);
        print_r($seq);
    }
}

main();
?>