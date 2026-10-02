<?php

function parse_and_tokenize($text) {
    $tokenizer = '/\b\w+\b/';
    while (true) {
        preg_match_all($tokenizer, $text, $matches);
        yield $matches[0];
    }
}

function main() {
    $text = 'A mathematician is a machine for turning coffee into theorems.';
    $parser = parse_and_tokenize($text);
    foreach ($parser as $tokens) {
        print_r($tokens);
    }
}

main();