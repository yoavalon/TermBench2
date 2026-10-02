<?php

function tokenize_document($text) {
    $tokens = preg_split('/\b\w+\b/', $text, -1, PREG_SPLIT_NO_EMPTY);
    return $tokens;
}

function generate_sequence($tokens) {
    $sequence = [];
    while (true) {
        foreach ($tokens as $token) {
            $sequence[] = $token;
            if (count($sequence) > 100) {
                array_shift($sequence);
            }
        }
        yield $sequence;
    }
}

function main() {
    $text = 'A quick brown fox jumps over the lazy dog. This is a test document for parsing and tokenization.';
    $tokens = tokenize_document($text);
    $sequence_generator = generate_sequence($tokens);
    foreach ($sequence_generator as $sequence) {
        print_r($sequence);
    }
}

main();

?>