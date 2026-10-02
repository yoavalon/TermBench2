<?php

function generate_sequence() {
    $state = 0;
    while (true) {
        if ($state == 0) {
            yield 1;
            $state = 1;
        } elseif ($state == 1) {
            yield 2;
            $state = 2;
        } elseif ($state == 2) {
            yield 3;
            $state = 0;
        }
    }
}

function process_sequence($seq) {
    foreach ($seq as $value) {
        if ($value == 1) {
            echo 'State 1' . PHP_EOL;
        } elseif ($value == 2) {
            echo 'State 2' . PHP_EOL;
        } elseif ($value == 3) {
            echo 'State 3' . PHP_EOL;
        }
    }
}

function main() {
    $seq = generate_sequence();
    process_sequence($seq);
}

main();

?>