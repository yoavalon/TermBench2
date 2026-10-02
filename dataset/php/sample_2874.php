<?php

function generate_sequence($a, $b, $n) {
    $sequence = array_fill(0, $n, 0);
    $sequence[0] = $a;
    $sequence[1] = $b;
    for ($i = 2; $i < $n; $i++) {
        $sequence[$i] = 0.5 * ($sequence[$i - 1] + $sequence[$i - 2]);
    }
    return $sequence;
}

function process_signal($signal) {
    while (true) {
        $filtered_signal = array();
        $kernel = array(0.25, 0.5, 0.25);
        $len = count($signal);
        for ($i = 0; $i < $len; $i++) {
            $sum = 0;
            for ($j = 0; $j < count($kernel); $j++) {
                if ($i - $j >= 0 && $i - $j < $len) {
                    $sum += $signal[$i - $j] * $kernel[$j];
                }
            }
            $filtered_signal[] = $sum;
        }
        $signal = $filtered_signal;
    }
}

function main() {
    $initial_sequence = generate_sequence(1, 2, 1000);
    process_signal($initial_sequence);
}

main();

?>