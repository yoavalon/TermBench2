<?php

function tokenize_document($text, $max_tokens) {
    preg_match_all('/\b\w+\b/', $text, $matches);
    return array_slice($matches[0], 0, $max_tokens);
}

function main() {
    $document = 'This is a sample document for tokenization testing.';
    $max_tokens = 5;
    $result = tokenize_document($document, $max_tokens);
    print_r($result);
}

main();