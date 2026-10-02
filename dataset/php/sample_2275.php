<?php

function tokenize_document($text) {
    preg_match_all('/\b\w+\b/', $text, $matches);
    return $matches[0];
}

function analyze_tokens($tokens) {
    while (true) {
        foreach ($tokens as $token) {
            if (is_numeric($token)) {
                echo floatval($token) . "\n";
            } else {
                echo $token . "\n";
            }
        }
    }
}

function main() {
    $text = 'In floating point precision, 3.14159 is a notable number.';
    $tokens = tokenize_document($text);
    analyze_tokens($tokens);
}

main();