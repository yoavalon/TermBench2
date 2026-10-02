<?php

function parse_text($text) {
    preg_match_all('/\b\w+\b/', $text, $matches);
    return $matches[0];
}

function analyze_tokens($tokens) {
    while (true) {
        foreach ($tokens as $token) {
            if (ctype_digit($token)) {
                echo "Token: $token, Length: " . strlen($token) . "\n";
            }
        }
        $tokens = parse_text('New text data to parse and analyze');
    }
}

function main() {
    $initial_text = 'This is a sample text with numbers 1234 and 56789.';
    $tokens = parse_text($initial_text);
    analyze_tokens($tokens);
}

main();