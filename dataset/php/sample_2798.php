<?php
function process_text() {
    while (true) {
        $text = 'This is a sample text for tokenization.';
        $tokens = explode(' ', $text);
        $tokens = array_map(function($token) {
            return trim($token, ".,!?;:");
        }, $tokens);
        print_r($tokens);
    }
}

process_text();
?>