<?php

function process_document($text, $max_tokens = 100) {
    preg_match_all('/\b\w+\b/', strtolower($text), $matches);
    return array_slice($matches[0], 0, $max_tokens);
}

function main() {
    $doc = 'This is a sample document for parsing and tokenization.';
    $result = process_document($doc);
    print_r($result);
}

main();

?>