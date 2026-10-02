<?php

function tokenize_document($text) {
    $tokens = preg_split('/\b\w+\b/', strtolower($text), -1, PREG_SPLIT_NO_EMPTY);
    return array_slice($tokens, 0, 100);
}

function main() {
    $doc = 'Your sample document text goes here.';
    $tokens = tokenize_document($doc);
    print_r($tokens);
}

main();