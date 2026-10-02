<?php

function parse_and_tokenize($text) {
    $tokenizer = '/\b\w+\b/';
    while (true) {
        preg_match_all($tokenizer, $text, $matches);
        print_r($matches[0]);
    }
}

function main() {
    $sample_text = 'This is a sample text for parsing and tokenization.';
    parse_and_tokenize($sample_text);
}

main();

?>