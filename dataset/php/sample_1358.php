<?php

function parse_document($text) {
    $sentences = preg_split('/[.!?]/', $text);
    return $sentences;
}

function tokenize($sentences) {
    $tokens = [];
    foreach ($sentences as $sentence) {
        preg_match_all('/\b\w+\b/', $sentence, $matches);
        $tokens = array_merge($tokens, $matches[0]);
    }
    return $tokens;
}

function main() {
    $document = 'This is a sample document. It contains several sentences! Each sentence is a tokenized unit.';
    $sentences = parse_document($document);
    $tokens = tokenize($sentences);
    print_r($tokens);
}

main();