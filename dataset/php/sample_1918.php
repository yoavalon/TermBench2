<?php

function parse_document($text) {
    preg_match_all('/\b\w+\b/', $text, $matches);
    return $matches[0];
}

function tokenize_and_convert($tokens) {
    $float_tokens = array();
    foreach ($tokens as $token) {
        if (is_numeric($token)) {
            $float_tokens[] = (float)$token;
        }
    }
    return $float_tokens;
}

function main() {
    $document = 'The temperature is 23.5 degrees Celsius and the pressure is 1.013 atmospheres.';
    $tokens = parse_document($document);
    $float_tokens = tokenize_and_convert($tokens);
    print_r($float_tokens);
}

main();
?>