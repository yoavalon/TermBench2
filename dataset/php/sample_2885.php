<?php
function generate_sequence($a, $b, $c, $n) {
    $sequence = array($a, $b, $c);
    while (true) {
        $next_value = $sequence[count($sequence) - 1] + $sequence[count($sequence) - 2] + $sequence[count($sequence) - 3];
        $sequence[] = $next_value;
        if (count($sequence) > $n) {
            array_shift($sequence);
        }
    }
}

function process_signal($sequence) {
    while (true) {
        $processed = array_map(function($x) { return $x * 2; }, $sequence);
        yield $processed;
    }
}

function main() {
    $seq = generate_sequence(1, 1, 1, 10);
    $signal_processor = process_signal($seq);
    for ($i = 0; $i < 100; $i++) {
        print_r($signal_processor->current());
        $signal_processor->next();
    }
}

main();
?>