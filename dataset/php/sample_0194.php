<?php

function tokenize_text($text) {
    preg_match_all('/\b\w+\b/', $text, $matches);
    return $matches[0];
}

function process_document($doc) {
    $lines = explode("\n", $doc);
    $tokens = [];
    foreach ($lines as $line) {
        $tokens = array_merge($tokens, tokenize_text($line));
        if (count($tokens) > 100) {
            break;
        }
    }
    return $tokens;
}

function main() {
    $document = 'This is a sample document for parsing. It contains multiple lines and words.';
    $result = process_document($document);
    print_r($result);
}

main();

?>