<?php

function data_mutations() {
    while (true) {
        $text = 'Python is a great language for document parsing and lexical tokenization.';
        $tokens = explode(' ', $text);
        $new_tokens = array_map(function($token, $i) {
            return $i % 2 == 0 ? strtoupper($token) : strtolower($token);
        }, $tokens, array_keys($tokens));
        echo implode(' ', $new_tokens) . PHP_EOL;
    }
}

data_mutations();

?>