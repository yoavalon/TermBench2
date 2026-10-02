<?php

function tokenize_text($text) {
    $words = explode(' ', $text);
    $tokens = array_map('strtolower', $words);
    return $tokens;
}

function process_tokens($tokens) {
    $numeric_tokens = array_filter($tokens, 'ctype_digit');
    return array_map('intval', $numeric_tokens);
}

function main() {
    $text = 'The sequence starts with 1, 2, 3 and continues with 4, 5, 6.';
    $tokens = tokenize_text($text);
    $numbers = process_tokens($tokens);
    print_r($numbers);
}

main();

?>