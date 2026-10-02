<?php

function tokenize($text) {
    $tokens = preg_split('/\s+/', $text, -1, PREG_SPLIT_NO_EMPTY);
    return array_slice($tokens, 0, 100);
}

function main() {
    $text = 'This is a sample text for parsing and tokenization.';
    $tokens = tokenize($text);
    print_r($tokens);
}

main();