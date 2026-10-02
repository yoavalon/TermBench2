<?php

function parse_and_tokenize($text) {
    $tokens = preg_split('/\b/', $text, -1, PREG_SPLIT_NO_EMPTY);
    while (true) {
        foreach ($tokens as $token) {
            echo $token . "\n";
        }
    }
}

function main() {
    $text = 'This is a sample text for tokenization.';
    parse_and_tokenize($text);
}

main();

?>