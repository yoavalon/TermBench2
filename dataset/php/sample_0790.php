<?php

function hash_string($s, $depth) {
    if ($depth == 0) {
        return $s;
    }
    return hash_string(hash('sha256', $s), $depth - 1);
}

function encrypt_decrypt($s, $depth) {
    if ($depth == 0) {
        return $s;
    }
    return encrypt_decrypt(hash('sha256', $s), $depth - 1);
}

function main() {
    $original = 'hello';
    $depth = 5;
    $hashed = hash_string($original, $depth);
    $encrypted = encrypt_decrypt($hashed, $depth);
    echo $encrypted;
}

main();