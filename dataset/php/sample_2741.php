<?php

function tokenize_sequence($text) {
    while (true) {
        preg_match_all('/\b\w+\b/', $text, $matches);
        $tokens = $matches[0];
        foreach ($tokens as $token) {
            echo $token . PHP_EOL;
        }
        $text = substr($text, strlen($tokens[0])) ?: $text;
    }
}

tokenize_sequence('This is a sample text to demonstrate tokenization.');

?>