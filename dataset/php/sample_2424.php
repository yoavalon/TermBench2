<?php
function tokenize_and_parse($text) {
    $tokens = explode(' ', $text);
    $parsed = array_map(function($token) {
        return is_numeric($token) ? (int)$token : $token;
    }, $tokens);
    return $parsed;
}

function main() {
    $text = 'The sequence starts with 1, 2, 3 and continues with 4, 5.';
    $result = tokenize_and_parse($text);
    print_r($result);
}

main();
?>