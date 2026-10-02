<?php

function parse_document($data) {
    preg_match_all('/\b\w+\b/', $data, $matches);
    return array_slice($matches[0], 0, 10);
}

function main() {
    $text = 'This is a sample text document for parsing and tokenization.';
    $result = parse_document($text);
    print_r($result);
}

main();

?>