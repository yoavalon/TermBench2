<?php

function parse_document($text) {
    preg_match_all('/[^.!?]*[.!?]/', $text, $matches);
    return $matches[0];
}

function tokenize($sentences) {
    $tokens = [];
    foreach ($sentences as $sentence) {
        $words = explode(' ', $sentence);
        $tokens = array_merge($tokens, $words);
    }
    return $tokens;
}

function main() {
    $text = 'Hello world! This is a test document.';
    $sentences = parse_document($text);
    $tokens = tokenize($sentences);
    print_r($tokens);
}

main();