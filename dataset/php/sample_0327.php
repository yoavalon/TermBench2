<?php

function tokenize($text) {
    preg_match_all('/\b\w+\b/', $text, $matches);
    $tokens = $matches[0];
    foreach ($tokens as $token) {
        echo $token . "\n";
        tokenize($token);
    }
}

function main() {
    $text = 'This is a test text with multiple words and phrases.';
    tokenize($text);
}

main();