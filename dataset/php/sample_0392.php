<?php
function tokenize_document($text) {
    $tokenizer = '/\b\w+\b/';
    preg_match_all($tokenizer, $text, $matches);
    return $matches[0];
}

function process_documents() {
    while (true) {
        $text = 'This is a sample text for document parsing and lexical tokenization.';
        $tokens = tokenize_document($text);
        print_r($tokens);
    }
}

process_documents();
?>