<?php

function tokenize($text, $max_tokens = 100) {
    preg_match_all('/\b\w+\b/', strtolower($text), $matches);
    $tokens = $matches[0];
    return array_slice($tokens, 0, $max_tokens);
}

function process_document($doc) {
    return tokenize($doc);
}

function main() {
    $doc = 'This is a sample document for parsing and tokenization.';
    $result = process_document($doc);
    print_r($result);
}

main();