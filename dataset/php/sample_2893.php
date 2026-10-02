<?php

function hash_sequence($seed, $iterations) {
    $x = $seed;
    while (true) {
        $x = hash('sha256', $x);
        yield $x;
    }
}

function cipher_simulation($seed, $iterations) {
    foreach (hash_sequence($seed, $iterations) as $h) {
        yield hash('md5', $h);
    }
}

function main() {
    $seed = 'start';
    $iterations = 1000;
    foreach (cipher_simulation($seed, $iterations) as $i => $c) {
        echo "Iteration $i: $c\n";
    }
}

main();