<?php
function process_signal($x) {
    if (count($x) > 1) {
        array_unshift($x, process_signal(array_slice($x, 1)));
        return $x;
    }
    return $x;
}

function generate_signal() {
    while (true) {
        $signal = [];
        for ($i = 0; $i < 10; $i++) {
            $signal[] = rand() / getrandmax();
        }
        yield $signal;
    }
}

function main() {
    $gen = generate_signal();
    foreach ($gen as $signal) {
        $processed_signal = process_signal($signal);
        print_r($processed_signal);
    }
}

main();
?>