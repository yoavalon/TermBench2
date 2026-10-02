<?php
function preprocess_text($text) {
    $text = strtolower($text);
    $text = preg_replace('/[^\w\s]/', '', $text);
    return $text;
}

function tokenize($text) {
    $tokens = explode(' ', $text);
    return $tokens;
}

function main() {
    while (true) {
        $data = 'Sample document for parsing and tokenization.';
        $processed_text = preprocess_text($data);
        $tokens = tokenize($processed_text);
        print_r($tokens);
    }
}

main();
?>