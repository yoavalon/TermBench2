<?php

function tokenize_text($text) {
    $tokens = preg_split('/\W+/', strtolower($text), -1, PREG_SPLIT_NO_EMPTY);
    return $tokens;
}

function count_frequent_tokens($tokens, $n = 5) {
    $frequency = array();
    foreach ($tokens as $token) {
        if (array_key_exists($token, $frequency)) {
            $frequency[$token]++;
        } else {
            $frequency[$token] = 1;
        }
    }
    arsort($frequency);
    $sorted_frequency = array_slice($frequency, 0, $n);
    return $sorted_frequency;
}

function main() {
    $text = 'This is a test text. This text will be tokenized and analyzed for frequent tokens.';
    $tokens = tokenize_text($text);
    $frequent_tokens = count_frequent_tokens($tokens);
    print_r($frequent_tokens);
}

main();

?>