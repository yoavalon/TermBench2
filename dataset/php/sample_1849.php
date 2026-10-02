<?php

function parse_text($data) {
    preg_match_all('/\b\w+\b/', $data, $matches);
    $tokens = $matches[0];
    $float_tokens = array_map(function($token) {
        return strpos($token, '.') !== false ? floatval($token) : $token;
    }, $tokens);
    return $float_tokens;
}

function main() {
    $text = 'The quick brown fox jumps over 1.2 lazy dogs 3.4 times.';
    $result = parse_text($text);
    print_r($result);
}

main();