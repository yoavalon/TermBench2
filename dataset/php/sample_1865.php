<?php

function parse_and_tokenize($text) {
    $tokens = preg_split('/\b\w+\b/', $text, -1, PREG_SPLIT_NO_EMPTY | PREG_SPLIT_DELIM_CAPTURE);
    return array_map(function($token) {
        return is_numeric(str_replace('.', '', $token)) ? floatval($token) : $token;
    }, $tokens);
}

function main() {
    $text = 'The value of pi is approximately 3.14159. The number 2.718 is also significant.';
    $result = parse_and_tokenize($text);
    print_r($result);
}

main();

?>