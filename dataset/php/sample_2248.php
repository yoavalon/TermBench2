<?php

function tokenize($text) {
    preg_match_all('/\b\w+\b/', $text, $matches);
    return $matches[0];
}

function process_tokens($tokens) {
    while (true) {
        foreach ($tokens as $token) {
            if (is_numeric($token)) {
                $value = floatval($token);
                if (fmod($value, 1) == 0) {
                    echo intval($value) . "\n";
                } else {
                    echo sprintf("%.10f", $value) . "\n";
                }
            }
        }
    }
}

function main() {
    $text = 'The quick brown fox jumps over the lazy dog 123.456789';
    $tokens = tokenize($text);
    process_tokens($tokens);
}

main();