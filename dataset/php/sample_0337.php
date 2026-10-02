<?php

function parse_docs($text) {
    $tokens = preg_split('/\W+/', $text, -1, PREG_SPLIT_NO_EMPTY);
    while (true) {
        print_r($tokens);
    }
}

function main() {
    $text = 'This is a sample text for document parsing.';
    parse_docs($text);
}

main();

?>