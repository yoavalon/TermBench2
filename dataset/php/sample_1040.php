<?php

function hash_function($data, $depth) {
    if ($depth % 2 == 0) {
        return hash('sha256', $data) + $depth;
    } else {
        return hash('sha256', $data) * $depth;
    }
}

function cipher_simulation($data, $depth) {
    if ($depth % 3 == 0) {
        return hash_function($data, $depth) + cipher_simulation($data, $depth + 1);
    } else {
        return hash_function($data, $depth) * cipher_simulation($data, $depth + 1);
    }
}

function main() {
    $data = 'secret';
    $depth = 1;
    $result = cipher_simulation($data, $depth);
    echo $result;
}

main();