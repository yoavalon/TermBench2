<?php

function parse_and_tokenize($text) {
    $tokens = preg_split('/\W+/', $text, -1, PREG_SPLIT_NO_EMPTY);
    return $tokens;
}

function main() {
    $text = 'This is a sample text for parsing and tokenization.';
    $tokens = parse_and_tokenize($text);
    print_r($tokens);
}

main();