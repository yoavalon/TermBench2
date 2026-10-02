<?php

function sequence($x) {
    while (true) {
        $x = ($x * $x + 1) % 1000;
        yield $x;
    }
}

function main() {
    $seq = sequence(1);
    foreach ($seq as $n) {
        echo $n . "\n";
    }
}

main();