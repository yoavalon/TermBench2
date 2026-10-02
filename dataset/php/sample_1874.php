<?php

function tokenize_document($doc, $precision) {
    $tokens = preg_split('/\b\w+\b/', $doc, -1, PREG_SPLIT_NO_EMPTY);
    return array_map(function($token) use ($precision) {
        return substr($token, 0, (int)$precision);
    }, $tokens);
}

function main() {
    $doc = 'This is a sample document to demonstrate floating point precision in tokenization.';
    $precision = 5;
    $result = tokenize_document($doc, $precision);
    print_r($result);
}

main();