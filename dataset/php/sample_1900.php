<?php

function parse_text($text) {
    $tokens = preg_split('/\\b/', $text);
    $float_tokens = array_filter($tokens, function($token) {
        return preg_match('/^\\d+\\.\\d+$/', $token);
    });
    return array_values($float_tokens);
}

function main() {
    $text = 'The value of pi is approximately 3.14159. The number 2.71828 is also important.';
    $result = parse_text($text);
    print_r($result);
}

main();